# Planning target for one arm — consumed by cable_tracker
std_msgs/Header header
string arm                      # "left" or "right"
geometry_msgs/Pose pose         # target TCP pose in waist_yaw_link
float64 cable_yaw               # cable direction angle (rad, for computing palm orientation)
float64 cable_z                 # cable Z in waist_yaw_link (for table obstacle placement)
int32 plug_id                   # which plug this target corresponds to
