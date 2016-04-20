# local_planner

rostopic pub /move_base_simple/goal geometry_ms/PoseStamped '{header: {stamp: now, frame_id: "map"}, pose: {position: {x: 2.25, y: 1.25, z: 0.0}, orientation: {z: 0.707, w: 0.707}}}'


roslaunch local_planner testmap.launch 
