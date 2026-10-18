# Roadmap

Homework-style. Each assignment gives you a problem and something to turn in. **The answers are
yours:** where an assignment says *your call*, nobody has decided yet, and that's the work.

Due dates are blank on purpose. Fill one in when you start an assignment, not before.

## The story: red-teaming your own defense

Settled 2026-10-17, after trying stealth (didn't like the no-cooperation mindset) and a
considerate store robot (a chore, no stakes). **You build both sides.** The patrol is your
defense. Otto is your attacker, built to find the holes in that defense so you can close them.
The sneaking is real and the risk is real, and the point is to make the defense better: the
same thing you liked about red-teaming at work.

| Label | Means |
| --- | --- |
| **Blue** | the patrol: your defense |
| **Red** | Otto: your attacker |
| **Detected** | Otto is inside a patrol robot's cone |
| **Caught** | your call (HW3) |

Colors follow security convention: the *blue team* is the defense and the *red team* is the
attacker.

**Scope: 1v1 or 2v1.** One Otto, always. One or two patrol robots. Anything bigger waits until
this works.

**The loop:** attack until it beats the defense → harden the defense (routes, timing, cone
placement) → attack again. Every attack HW below ends with a **Harden** step: change the defense
so that attack stops working, and rerun the earlier attacks against the new defense.

## What the class gave you, and what can be rebuilt

| Class had | Here |
| --- | --- |
| A due date | You write it on the assignment when you start it. |
| A grader | Claude grades each turn-in like a TA: reads the code, runs it, says what's wrong. |
| Other people's results to compare against | The [scoreboard](#scoreboard): every attempt scored on the same scenarios against dumb baselines and your own earlier attempts. |
| Shared adversity | **Can't be rebuilt.** The closest substitute is posting results somewhere someone else will see them. |

Evidence against relying on the format alone: 12_months had a full syllabus and it's paused. What
you said you have is *wanting to see it work*, so every assignment ends with something you can
watch: Gazebo running, a plot, a video.

## Prerequisite: finish setup

- [setup.md](setup.md) §4: the Nav2 Goal drive check.
- [setup.md](setup.md) §5: where the workspace lives, and the first package name.
- Lidar range: **decided, 6 m for both teams** (`<max>` in a copy of `gz_waffle.sdf.xacro`).
- Map: **something more complex than the sandbox** (his call, for fun). Candidates: `depot` (about
  30 × 15 m) or `warehouse` (about 30 × 50 m). Their worlds are in `nav2_minimal_tb4_sim/worlds/`
  and their maps are in `nav2_bringup/maps/`. The Waffle in those worlds is untested.
- Robot models: edit **copies** in the repo, not the installed files. The sim caps the Waffle at
  0.46 m/s and 1.9 rad/s (`max_linear_velocity` in `gz_waffle.sdf.xacro`). Pick the ratios
  first (warning time = range ÷ speed, Otto's speed vs the patrol's), then the numbers.

---

## HW1: Blue on patrol

> Good evening. Before anyone can break in, someone has to stand guard. Your mission, should
> you choose to accept it: put a blue patrol robot on a route and keep it walking. Forever.

**Given:** one TurtleBot in the sandbox world.
**Do:** drive a blue patrol robot along a predetermined path, forever.
**Turn in:** a node, plus a plot of blue's path from `/odom` over several laps.

Your calls:
- How a "predetermined path" is represented: waypoints, a loop, timing.
- Does blue repeat exactly, with jitter, or randomly? This choice is the difficulty knob for every
  approach that observes blue first.

Port from 2022 (Python → C++, rewrite, don't copy): path following, PID. Fair game for Claude: the launch file that spawns a second
or third robot under its own namespace.

**Due:** ____

## HW2: The cone

> A guard who can't see is just furniture. Your mission: give the patrol eyes, and decide exactly
> what it takes to be seen.

**Given:** blue's pose and red's pose.
**Do:** decide whether red is detected.
**Turn in:** a detector node that publishes the result, plus the cone drawn in RViz as a marker.

Your calls:
- Cone range and half-angle.
- Do walls block the cone (line of sight), or is it pure geometry?
- Is detection on/off, or does it build up the longer red stays in view?

**Due:** ____

## HW3: The score

> Every operation gets a debrief. Your mission: decide how this one is judged *before* anyone
> goes in, so nobody can grade on a curve afterward.

**Do:** define the score *before* you write a planner, so every later attempt is measured the
same way.
**Turn in:** a script that takes one run (a rosbag) and prints one scoreboard row.

Your calls:
- What "caught" means, and how it differs from "detected".
- How time trades off against detection. How much detection is tolerable?
- The fixed scenario set every attempt runs on: start, goal, blue paths, how many runs.

**Due:** ____

## HW4: Baselines (the classmates)

> Send in the rookies. Your mission: run Ottos with no tricks at all and record how fast they get
> spotted. This is the bar every real plan has to clear.

**Do:** run two red Ottos (one at a time) that don't try to be smart, and score them.
1. Straight to the goal, ignoring blue. Use Nav2 or your 2022 A*.
2. A second naive Otto you pick.

**Turn in:** their rows on the scoreboard. Everything after this has to beat them.

**Due:** ____

## HW5: Cone as an obstacle (your approach 3)

> Otto, your first real assignment. The guards' line of sight is a wall you can't walk through.
> Go around it. If you're spotted, the agency will deny all knowledge of your planner.

**Do:** red treats blue's currently known cone as an obstacle and replans as it moves.
**Turn in:** a planner node, its scoreboard row, and a video of a run.

The open question from the hub note comes due here: is a blocked cell blocked forever, or only
at certain times? Your answer decides whether this stays a 2D planner or becomes a planner over
space and time.

**Harden:** change the defense until this attack stops working; rerun every earlier attack.

**Due:** ____

## HW6: Observe first (your approach 1)

> Patience, Otto. Watch the guards, learn their rhythm, and move when they look away. Recon
> first, then the run.

**Do:** red watches blue before committing, learns the pattern, and plans against where blue
*will be*.
**Turn in:** your model of blue, the planner, a scoreboard row, and a run where watching first
beats HW5.

Your calls: how red detects blue (port the 2022 lidar object detection), how long to watch,
and what to do when blue breaks the pattern. The lidar range answer matters most here.

**Harden:** change the defense until this attack stops working; rerun every earlier attack.

**Due:** ____

## Parked: Scout (your approach 2)

A scout means a second attacker, which is outside the 1v1/2v1 scope. Revisit once HW6 works.

## Final project: Rescue

> The big one. Get in, reach the goal, and get out, unseen both ways. As always, this message will
> self-destruct after `colcon build`.

Reach the goal, then return, both legs undetected. Same scoreboard.

---

## Scoreboard

One row per attack × defense pairing, all on the same scenario set (HW3). The column names
come from HW3. Once you've hardened the defense, rerun the old attacks against it: a defense
that only stops the newest attack hasn't been hardened.

| Date | Attack | Defense | Scenario set | ... | Notes |
| --- | --- | --- | --- | --- |
