# Session notes

## Where things stand

**2026-10-11:** repo created, scaffolding only. Stack, simulator, and first milestone not chosen.

His starting points (from the hub idea note):

- Approaches: watch red first to learn its pattern; a scout; treat red's known cone as an obstacle
  and replan.
- Scoring: time counts. Detected is bad, detected **and caught** is the real failure; maybe some
  detection is acceptable. Rescue variant: reach the goal and get back.
- Open question he was left with: in his planner, is a blocked cell blocked forever, or only at
  certain times?

**2026-10-17:** [setup.md](setup.md) written (Claude): install checklist for ROS 2 Jazzy +
Gazebo Harmonic + Nav2 TurtleBot 3 sim on the existing `Ubuntu-24.04` distro, with a check per
stage and the sources fetched. Nothing installed yet; repo cloned to `~/otto-the-robot` in WSL.

**2026-10-17 (evening):** setup §1–3 done. ROS 2 Jazzy and Gazebo Harmonic are installed;
`gz sim shapes.sdf` works. Two snags, neither one a checklist bug: he skipped the `apt update`
after adding the ROS source, and `gz` wasn't on PATH until he re-sourced (`setup.bash` only adds
vendor bin dirs for packages that were installed when it ran). §4: launched the TB3 sim, and
the Nav2 sim only ships the **Waffle** (2022 was the Burger, because the lab had real Burgers).
Same LDS lidar (`/scan`, 360 samples, 5 Hz), plus a depth camera he doesn't plan to use.
**The sim lidar max is 20 m against about 3.5 m on a real LDS-01.** He called that a huge
difference; which range he designs for is still open. The §4 Nav2 Goal drive check passed.

He asked for a roadmap framed as homework, and wondered whether his old motivation came from
the class itself: comparing results, shared adversity. [roadmap.md](roadmap.md) written
(Claude): HW1 red patrol → HW2 cone → HW3 score → HW4 baselines → HW5–7 his three approaches →
rescue. Design questions are left as "your call", and due dates are blank for him to fill. In
place of classmates there's a scoreboard against baselines. Workspace: repo root is the colcon
workspace, packages in `src/` (his call; setup §5).

## Next

- Decide the lidar range: 20 m sim or 3.5 m real.
- Start HW1 in [roadmap.md](roadmap.md) and write its due date.
