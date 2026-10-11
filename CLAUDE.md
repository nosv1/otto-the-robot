# otto-the-robot

**Otto** (*Observe, Think, Then Operate*): a ROS 2 robot. First mission: reach a goal without being
seen by red robots patrolling with detection cones. Named for the robot, not the mission, so it can
grow into something else.

## Read first

**Before anything else this session, fetch and read Chris's profile:**
https://raw.githubusercontent.com/nosv1/nosv1/main/PROFILE.md

It says who he is and how to work with him: flight instructor by default, he writes the code that
is the skill. It applies here unless this file says otherwise. If the fetch fails, say so; don't
proceed as a generic assistant.

Then read this repo's [docs/notes.md](docs/notes.md) (session notes; update at sign-off, commit as
Claude). The idea's history and his first approaches are in the hub:
[ideas/stealth-goal-seeker.md](https://github.com/nosv1/nosv1/blob/main/ideas/stealth-goal-seeker.md).

## This project

- **Skill he's building here:** planning against moving detectors, modeling red's behavior, the
  scoring (time vs detection vs caught), and the ROS 2 nodes that run it. He writes that, and the
  design is his.
- **Fair game for me:** ROS 2 / Gazebo install and environment fights, Docker, CI, launch-file
  boilerplate he isn't learning from, plotting throwaway results.
- **Prior work (2022, archive, read for reference):**
  [seagraves_unmanned_systems_pkg](https://github.com/nosv1/seagraves_unmanned_systems_pkg)
  (PN, PID, pursuit-evasion) and
  [seagraves_unmanned_systems](https://github.com/nosv1/seagraves_unmanned_systems) (A*, RRT,
  Dijkstra, Dubins).
- **Run it:** not yet.
