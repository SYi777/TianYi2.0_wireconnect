import time
import traceback
from xrocs.utils.ros2_node_manager import ros2_node_manager
from xrocs.entity.robot.TienKungDex.tienkung_dex_ros2_mc import TienKungDexRos2MotionController


def main():

    try:
        # Acquire shared ROS 2 node from manager
        node = ros2_node_manager.acquire()
        
        # Create motion controller instance
        motion_controller = TienKungDexRos2MotionController(node)
        
        # Wait a moment for TF tree to be populated
        print("Waiting 2 seconds for TF tree to populate...")
        time.sleep(2.0)
        
        # Get and print left TCP pose
        left_tcp_pose = motion_controller.moveit_ctrler.get_left_tcp_pose()
        right_tcp_pose = motion_controller.moveit_ctrler.get_right_tcp_pose()
        camera_pose = motion_controller.moveit_ctrler.get_camera_pose()
        head_pose = motion_controller.moveit_ctrler.get_head_pose()

    except Exception as e:
        print(f"Error occurred: {str(e)}")
        traceback.print_exc()
        
    finally:
        # Release the shared node reference
        ros2_node_manager.release()


if __name__ == '__main__':
    main()
