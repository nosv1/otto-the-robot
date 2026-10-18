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

**Reframed (same night), and settled:** he asked how symmetric 6 m sensing fits a real scenario,
then went through three stories. (1) Stealth: dropped, because "sneaking means no cooperation"
and he didn't like that mindset. (2) Considerate store robot (QuikTrip's floor cleaner is too slow
for people): dropped, "these are just chores", with no stakes. (3) A game (tag): "but why are we
playing tag." **Landed on red-teaming his own defense**, which he enjoyed at work. He builds both
the patrol (defense) and Otto (attack); each attack that works hardens the defense. Roadmap: the
story section was rewritten, every attack HW now ends with a Harden step, and the scoreboard is
attack × defense. README and CLAUDE.md were updated to match. Flagged and open: security
convention has red = attacker, the opposite of his colors. **Not updated:** the hub idea note
(nosv1 `ideas/stealth-goal-seeker.md`). Open for HW2: with symmetric 6 m sensing, what makes the
cone a cone? **Scope set by him: 1v1 or 2v1, never more than one Otto any time soon**; the
scout (HW7) is parked. **Colors swapped (his call): blue = his defense (the
patrol), red = Otto (the attacker),** matching security convention. Earlier entries above use the
old colors. Each HW now opens with a Mission: Impossible style brief (his idea: "lighten the
mood", and future readers might enjoy it).

**Map and models:** he wants a more complex map than the sandbox (depot or warehouse; those
worlds ship with the TB4 sim) and doesn't mind editing robot models to raise speed and sensing,
"it's for fun anyways." Flagged: ratios matter more than absolutes. Also: he wants the deep end,
not warm-ups.

## Next

- Pick the map (depot or warehouse) and get the Waffle spawning in it.
- Start HW1 in [roadmap.md](roadmap.md) and write its due date.
