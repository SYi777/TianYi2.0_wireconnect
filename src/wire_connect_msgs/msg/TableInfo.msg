# Desktop surface detected from depth image sampling
std_msgs/Header header
float64 z                      # table surface Z in target_frame
float64 x_min                  # table bounding box
float64 x_max
float64 y_min
float64 y_max
bool valid                     # false if no plane found
