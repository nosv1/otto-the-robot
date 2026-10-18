# Setup

Checklist to get from a bare `Ubuntu-24.04` WSL distro to a robot driving in Gazebo. Do the boxes
in order; each stage ends with a check, so you know it worked before the next one.

Stack: **ROS 2 Jazzy** + **Gazebo Harmonic**, on the existing `Ubuntu-24.04` distro (same one as
12_months). Why Jazzy: [12_months/docs/environment.md](https://github.com/nosv1/12_months/blob/dev/docs/environment.md).

## 0. Already true (checked 2026-10-17)

- [x] `Ubuntu-24.04` (24.04.4), WSL2, ~950 GB free, 15 GB RAM visible to WSL
- [x] Locale is `C.UTF-8` (any UTF-8 locale is fine for ROS; skip the docs' locale step)
- [x] apt suites include `noble-updates` and `noble-backports` (the docs warn `ros-dev-tools`
      conflicts without them)
- [x] `gh` logged in as `nosv1` (HTTPS); `git` user set
- [x] GPU visible: `nvidia-smi` → RTX 5080
- [x] WSLg present (`DISPLAY=:0`), so GUI windows should open on Windows
- [x] Repo cloned to `~/otto-the-robot` (inside WSL, not `/mnt/c/`)
- [ ] No ROS yet (`/opt/ros` doesn't exist)

## 1. ROS 2 apt repository

```bash
sudo apt install software-properties-common
sudo add-apt-repository universe

sudo apt update && sudo apt install curl -y
export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F'"' '{print $4}')
curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo ${UBUNTU_CODENAME:-${VERSION_CODENAME}})_all.deb"
sudo dpkg -i /tmp/ros2-apt-source.deb
```

- [x] **Check:** `apt-cache policy ros-jazzy-desktop` shows a candidate version (not `(none)`)

## 2. ROS 2 Jazzy

```bash
sudo apt update && sudo apt upgrade
sudo apt install ros-dev-tools        # colcon, rosdep, vcstool
sudo apt install ros-jazzy-desktop    # ROS + RViz + demos; a few GB
```

Source it in every shell (once, then new terminals have it):

```bash
echo 'source /opt/ros/jazzy/setup.bash' >> ~/.bashrc
source ~/.bashrc
```

- [x] **Check:** two terminals. One: `ros2 run demo_nodes_cpp talker`. Other:
      `ros2 run demo_nodes_py listener`. The listener prints what the talker says. Ctrl+C both.

## 3. Gazebo Harmonic (through ROS)

Jazzy pairs with Gazebo **Harmonic**, installed as ROS vendor packages. **Gazebo Classic (what
the 2022 class used) is not available for Jazzy**: no `gazebo` command, worlds are SDF for
`gz sim`, and the ROS bridge is `ros_gz` instead of `gazebo_ros`. Expect the 2022 launch files
not to work as is.

```bash
sudo apt install ros-jazzy-ros-gz
```

- [x] **Check:** `gz sim shapes.sdf` opens a window with shapes in it. If it's black, or very
      slow, that's WSLg rendering; stop and ask before fiddling.

## 4. A robot in a world

The Nav2 packages ship a TurtleBot 3 for modern Gazebo (`nav2_minimal_tb*`). The old
`turtlebot3_gazebo` package is the Gazebo Classic path; skip it.

```bash
sudo apt install ros-jazzy-navigation2 ros-jazzy-nav2-bringup ros-jazzy-nav2-minimal-tb\*
```

- [x] **Check:** `ros2 launch nav2_bringup tb3_simulation_launch.py headless:=False`. Gazebo and
      RViz open with a TurtleBot 3. In RViz: **2D Pose Estimate** where the robot is, then
      **Nav2 Goal** somewhere else; it drives there.

That run uses Nav2's planner, not yours. It's here only to prove the sim, robot, and transforms
work. Whether Otto uses any of Nav2 later (maps, localization, `slam_toolbox`) is your call; the
planner against red's cones is the part you write.

## 5. Your workspace

**Decided 2026-10-17: the repo root is the colcon workspace.** Packages go in `src/`; `build/`,
`install/`, `log/` are gitignored. Layout copies Nav2's bringup/sim split. Names (Claude's, at
his request):

| Package | Holds | Build |
| --- | --- | --- |
| `otto_bringup` | launch, params, maps, rviz | ament_cmake |
| `otto_sim` | worlds, edited Waffle, ros_gz bridge configs | ament_cmake |
| `otto_blue` | defense: patrol, cones | ament_python |
| `otto_red` | attack: Otto's planners | ament_python |
| `otto_debrief` | scoring, scenario sets, plots | ament_python |

Make each one when an HW needs it. HW1 needs only `otto_blue`.

```bash
cd ~/otto-the-robot
ros2 pkg create --build-type ament_python --destination-directory src <name>
colcon build --symlink-install       # always from the repo root
source install/setup.bash            # each new shell, after /opt/ros/jazzy
```

Run `colcon build` from anywhere else and it makes a second `build/`/`install/` there.

Several terminals at once: [tmux.md](tmux.md).

## Gotchas carried over from 12_months

- Work in `~/`, never `/mnt/c/` (slow, breaks file watching and `colcon`).
- `rclpy` is a system package for Python 3.12. It **won't import into a uv venv** that downloaded
  its own Python. ROS nodes run on the system `python3`.
- No bare `python` on Noble, only `python3`.
- Talking to another machine over DDS (a real robot later) needs `networkingMode=mirrored` in
  `%USERPROFILE%\.wslconfig`. Not needed for sim.

## Sources (fetched 2026-10-17)

- ROS 2 Jazzy, Ubuntu debs (doc source, since docs.ros.org blocked the fetch):
  [Ubuntu-Install-Debs.rst](https://github.com/ros2/ros2_documentation/blob/jazzy/source/Installation/Ubuntu-Install-Debs.rst),
  [_Apt-Repositories.rst](https://github.com/ros2/ros2_documentation/blob/jazzy/source/Installation/_Apt-Repositories.rst),
  [_Ubuntu-Set-Locale.rst](https://github.com/ros2/ros2_documentation/blob/jazzy/source/Installation/_Ubuntu-Set-Locale.rst)
- Gazebo with ROS (Jazzy → Harmonic, `ros-jazzy-ros-gz`):
  [gazebosim.org/docs/latest/ros_installation](https://gazebosim.org/docs/latest/ros_installation/)
- Nav2 quickstart (`navigation2`, `nav2-bringup`, `nav2-minimal-tb*`, `tb3_simulation_launch.py`):
  [quickstart.md](https://github.com/ros-navigation/docs.nav2.org/blob/master/docs/getting_started/quickstart/quickstart.md)
- Not used: community guides installing `ros-jazzy-turtlebot3-gazebo` on Jazzy; Nav2 calls that
  package the Gazebo Classic path, so it was left out.
