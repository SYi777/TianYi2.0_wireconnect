from __future__ import annotations

from xrocs.utils.ros2_node_manager import ros2_node_manager
from xrocs.entity.robot.TienKungDex.tienkung_dex_ros2_mc import TienKungDexRos2MotionController
from xrocs.entity.robot.TienYi2.tienyi2_ros2_mc import TienYi2Ros2MotionController
import traceback


def set_param_example(node, motion_controller):
    new_value = 2000
    print(f"Setting step_threshold on endpose_single_arm_qp_L_controller to {new_value})...")
    
    success = motion_controller.set_param(
        node_name='endpose_single_arm_qp_L_controller',
        parameter_name='step_threshold', 
        value=new_value,
        timeout_sec=10.0
    )

    if success:
        print("The step_threshold parameter was set successfully!")
    else:
        print("Could not set step_threshold parameter.")
    return success


def endpose_body_controller_example(node, motion_controller):
    target_pose = [0.0, 0.7, 0.0, 0.0]

    try:
        motion_controller.exec_endpose_body_controller(
            x=target_pose[0],
            z=target_pose[1],
            pitch=target_pose[2],
            yaw=target_pose[3]
        )
        print("Command sent successfully!")
    except Exception as e:
        print(f"Failed: {str(e)}")


def action_jointspace_arm_R_controller_example(node, motion_controller):

    # Feedback callback to monitor progress
    def feedback_callback(current_positions, feedback_msg):
        print(f"Current joint positions: {current_positions}")

    # [shoulder_pitch, shoulder_roll, shoulder_yaw, elbow_pitch, elbow_yaw, wrist_pitch, wrist_roll]
    target_joints = [0.2, -0.2, 0.0, -0.2, 0.0, 0.0, 0.0]

    try:
        success, result_msg = motion_controller.exec_action_jointspace_arm_R_controller(
            target=target_joints,
            feedback_callback=feedback_callback,
            timeout_sec=30.0
        )
        
        if success:
            print(f"SUCCESS: {result_msg}")
        else:
            print(f"FAILED: {result_msg}")
            
    except Exception as e:
        print(f"Exception: {str(e)}")


def action_endpose_arm_qp_R_controller_example(node, motion_controller):

    # Feedback callback to monitor progress
    def feedback_callback(current_err, feedback_msg):
        print(f"Feedback received! Current error: {current_err}, Message: {feedback_msg}")
        
    try:
        success, result_msg = motion_controller.exec_action_endpose_arm_qp_R_controller(
            from_frame="waist_yaw_link",  # Changed from base_footprint
            to_frame="right_tcp_link",
            target=[0.0, -0.26, -0.20, 0.043, 0.0, 0.0, 0.999],  # (position x,y,z and orientation x,y,z,w)
            offset=[0.0, 0.0, 0.0],
            feedback_callback=feedback_callback,
            timeout_sec=30.0
        )
        
        if success:
            print(f"SUCCESS: {result_msg}")
        else:
            print(f"FAILED: {result_msg}")
            
    except Exception as e:
        print(f"Exception: {str(e)}")


def main():

    try:
        # Acquire shared ROS 2 node from manager
        node = ros2_node_manager.acquire()
        
        # Example 1: TienKungDex set_param
        tienkung_controller = TienKungDexRos2MotionController(node)
        set_param_result = set_param_example(node, tienkung_controller)
        
        # Example 2: TienYi2 body controller
        tienyi2_controller = TienYi2Ros2MotionController(node)
        endpose_body_controller_result = endpose_body_controller_example(node, tienyi2_controller)
        
        # Example 3: TienKungDex action jointspace controller
        action_jointspace_arm_R_controller_result = action_jointspace_arm_R_controller_example(node, tienkung_controller)
        
        # Example 4: TienKungDex action endpose controller
        action_endpose_arm_qp_R_controller_result = action_endpose_arm_qp_R_controller_example(node, tienkung_controller)
            
    except Exception as e:
        print(f"Error occurred: {str(e)}")
        traceback.print_exc()
        
    finally:
        # Release the shared node reference
        ros2_node_manager.release()


if __name__ == '__main__':
    main()
