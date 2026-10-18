# Roadmap

Homework-style. Each assignment gives you a problem and something to turn in. **The answers are
yours:** where an assignment says *your call*, nobody has decided yet, and that's the work.

Due dates are blank on purpose. Fill one in when you start an assignment, not before.

## The story

Changed 2026-10-17: sneaking past someone is adversarial, and he didn't like that mindset. The math
stays the same; the story is now **considerate**. Otto is a store robot that delivers or cleans and
stays out of people's way. The inspiration is QuikTrip's floor cleaner, which moves too slowly for
a place full of people moving at walking speed.

| Label | Means |
| --- | --- |
| **Blue** | Otto |
| **Red** | people walking their routes (staff, shoppers) |
| **Cone** | the space a person is looking at or about to walk into |
| **In the way** (was "detected") | Otto is inside someone's cone |
| **Blocked** (was "caught") | Otto stops someone or forces them to step around it |

Red doesn't share its plans, so Otto still has to observe and predict. Delivering is
start-to-goal, which is what this roadmap builds. Cleaning means covering the whole floor, which is
a different planning problem (coverage). Treat it as a later variant.

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

---

## HW1: Red on its route

**Given:** one TurtleBot in the sandbox world.
**Do:** drive a red robot along a predetermined path, forever.
**Turn in:** a node, plus a plot of red's path from `/odom` over several laps.

Your calls:
- How a "predetermined path" is represented: waypoints, a loop, timing.
- Does red repeat exactly, with jitter, or randomly? This choice is the difficulty knob for every
  approach that observes red first.

Reuse from 2022: path following, PID. Fair game for Claude: the launch file that spawns a second
or third robot under its own namespace.

**Due:** ____

## HW2: The cone

**Given:** red's pose and blue's pose.
**Do:** decide whether blue is in red's way.
**Turn in:** a detector node that publishes the result, plus the cone drawn in RViz as a marker.

Your calls:
- Cone range and half-angle.
- Do walls block the cone (line of sight), or is it pure geometry?
- Is "in the way" on/off, or does it build up the longer blue stays there?

**Due:** ____

## HW3: The score

**Do:** define the score *before* you write a planner, so every later attempt is measured the
same way.
**Turn in:** a script that takes one run (a rosbag) and prints one scoreboard row.

Your calls:
- What "blocked" means, and how it differs from "in the way".
- How time trades off against being in the way. How much is tolerable?
- The fixed scenario set every attempt runs on: start, goal, red paths, how many runs.

**Due:** ____

## HW4: Baselines (the classmates)

**Do:** run two blue robots that don't try to be smart, and score them.
1. Straight to the goal, ignoring red. Use Nav2 or your 2022 A*.
2. A second naive blue you pick.

**Turn in:** their rows on the scoreboard. Everything after this has to beat them.

**Due:** ____

## HW5: Cone as an obstacle (your approach 3)

**Do:** blue treats red's currently known cone as an obstacle and replans as it moves.
**Turn in:** a planner node, its scoreboard row, and a video of a run.

The open question from the hub note comes due here: is a blocked cell blocked forever, or only
at certain times? Your answer decides whether this stays a 2D planner or becomes a planner over
space and time.

**Due:** ____

## HW6: Observe first (your approach 1)

**Do:** blue watches red before committing, learns the pattern, and plans against where red
*will be*.
**Turn in:** your model of red, the planner, a scoreboard row, and a run where watching first
beats HW5.

Your calls: how blue detects red (2022 lidar object detection carries over), how long to watch,
and what to do when red breaks the pattern. The lidar range answer matters most here.

**Due:** ____

## HW7: Scout (your approach 2, optional)

**Do:** a second blue robot scouts, and the main blue uses what it reports.
**Turn in:** a scoreboard row. Is the scout worth its cost?

**Due:** ____

## Final project: Round trip

Deliver, then return to base, with both legs out of the way (formerly the rescue variant). Same scoreboard.

---

## Scoreboard

One row per attempt, all on the same scenario set (HW3). The column names come from HW3.

| Date | Attempt | Scenario set | ... | Notes |
| --- | --- | --- | --- | --- |
