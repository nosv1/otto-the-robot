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

**2026-10-17 (evening):** setup §1–4 done (§2 talker/listener confirmed later). ROS 2 Jazzy and Gazebo Harmonic are installed;
`gz sim shapes.sdf` works. Two snags, neither one a checklist bug: he skipped the `apt update`
after adding the ROS source, and `gz` wasn't on PATH until he re-sourced (`setup.bash` only adds
vendor bin dirs for packages that were installed when it ran). §4: launched the TB3 sim, and
the Nav2 sim only ships the **Waffle** (2022 was the Burger, because the lab had real Burgers).
Same LDS lidar (`/scan`, 360 samples, 5 Hz), plus a depth camera he doesn't plan to use.
**The sim lidar max is 20 m against about 3.5 m on a real LDS-01.** He called that a huge
difference. **Decided: 6 m for both teams.** His picture: blue sees red, then hides by getting out
of red's view, so blue and red can have the same capabilities. The §4 Nav2 Goal drive check passed.

He asked for a roadmap framed as homework, and wondered whether his old motivation came from
the class itself: comparing results, shared adversity. [roadmap.md](roadmap.md) written
(Claude): HW1 red patrol → HW2 cone → HW3 score → HW4 baselines → HW5–7 his three approaches →
rescue. Design questions are left as "your call", and due dates are blank for him to fill. In
place of classmates there's a scoreboard against baselines. Workspace: repo root is the colcon
workspace, packages in `src/` (his call; setup §5).

**Reframed (same night):** first he asked how the 6 m symmetric lidar fits a real scenario. Then
he dropped sneaking: "the idea behind sneaking means no cooperation, and i don't like that
mindset." New story: a considerate store robot (delivery, or cleaning later), inspired by
QuikTrip's floor cleaner, which is too slow for people moving at walking speed. Red = people on
routes, "detected" → in the way, "caught" → blocked. That matches his 2022 note that a slower blue
has to out-know red. Updated: the roadmap's story section and wording, README, CLAUDE.md. **Not
updated:** the hub idea note (nosv1 `ideas/stealth-goal-seeker.md`). Open for HW2: with
symmetric 6 m sensing, what makes the cone a cone (people looking forward?), and is Otto slower
than people by design?

## Next

- Start HW1 in [roadmap.md](roadmap.md) and write its due date.
