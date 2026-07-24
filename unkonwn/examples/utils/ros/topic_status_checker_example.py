from xrocs.utils.ros.topic_status_checker import TopicFrequencyChecker


if __name__ == "__main__":
    checker = TopicFrequencyChecker()
    topic_configs = [
        ("/arm/status", 300, 100),
        ("/arm_6dof_left", 300, 100),
        ("/arm_6dof_right", 300, 100),
        ("/inspire_gripper/left_status", 80, 40),
        ("/inspire_gripper/right_status", 80, 40),
        ("/inspire_hand/state/left_hand", 80, 40),
        ("/inspire_hand/state/right_hand", 80, 40),

        ("/camera/color/image_raw/compressed", 20, 30),
        ("/camera/depth/image_raw", 20, 30),
        ("/camera1/camera1/color/image_rect_raw/compressed", 20, 30),
        ("/camera1/camera1/depth/image_rect_raw", 20, 30),
        ("/camera2/camera2/color/image_rect_raw/compressed", 20, 30),
        ("/camera2/camera2/depth/image_rect_raw", 20, 30),

        ("/encoder_identical_joint", 200, 80),
        ("/encoder_identical_button", 200, 80),
        ("/joint_states_flex_freq", 20, 30)
    ]

    results = checker.check_topics(topic_configs=topic_configs)
    print(results)