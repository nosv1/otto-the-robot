# otto_sim

Sim assets. No code.

Planned folders, created when they're needed:

| Folder | What |
| --- | --- |
| `worlds/` | Gazebo worlds (a depot or warehouse copy, once Fuel is back) |
| `urdf/` | edited Waffle copies (6 m lidar, speed caps) |
| `configs/` | ros_gz bridge YAML |
| `maps/` | nav maps that match the worlds |
| `launch/` | spawn and sim launch files |

Edit copies here, never the installed files under `/opt/ros`. With `ament_cmake`, each folder
needs an `install(DIRECTORY ...)` line in `CMakeLists.txt` before launch files can find it.
