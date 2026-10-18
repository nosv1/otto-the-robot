# src

The colcon workspace is the repo root; build from there, not from here.

| Package | What |
| --- | --- |
| [otto](otto/) | all the nodes, in C++ |
| [otto_sim](otto_sim/) | sim assets: worlds, robot models, bridge configs, maps, launch |

The split keeps Gazebo out of the node package. A real robot would swap `otto_sim` for something
else and leave `otto` alone.
