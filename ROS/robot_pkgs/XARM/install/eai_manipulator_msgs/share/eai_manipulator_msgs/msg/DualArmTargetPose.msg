

# 双臂目标位姿消息，包含左臂、右臂的目标信息及同步控制标志
std_msgs/Header header

# 左臂目标位姿信息
geometry_msgs/Pose target_l       # 目标位姿 T_A_B（从A系到B系的变换）
string from_frame_l               # A系名称（参考系）  
string to_frame_l                 # B系名称（目标系）  
float32 offset_x_l                # 末端参考点X方向偏移量
float32 offset_y_l                # 末端参考点Y方向偏移量
float32 offset_z_l                # 末端参考点Z方向偏移量

# 右臂目标位姿信息
geometry_msgs/Pose target_r       # 目标位姿 T_A_B（从A系到B系的变换）
string from_frame_r               # A系名称（参考系）
string to_frame_r                 # B系名称（目标系）
float32 offset_x_r                # 末端参考点X方向偏移量
float32 offset_y_r                # 末端参考点Y方向偏移量
float32 offset_z_r                # 末端参考点Z方向偏移量

bool is_dual_arm_syn              # 是否启用双臂同步运动（true=同步，false=独立）
