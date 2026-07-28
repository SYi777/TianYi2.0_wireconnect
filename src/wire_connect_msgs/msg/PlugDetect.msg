# Single plug detection (YOLO OBB + depth back-projection)
int32 id                        # 0-based index after left-to-right sorting
geometry_msgs/Pose pose         # 3D position + cable direction as quat (yaw only)
float64 confidence              # YOLO confidence [0,1]
float64 cable_yaw               # cable direction in waist_yaw_link XY plane (rad)
bool depth_valid                # false = depth hole, skip for planning
