#ifndef UINITREE_A1_ROS2_EXAMPLES_MESSAGE_PUB_H
#define UINITREE_A1_ROS2_EXAMPLES_MESSAGE_PUB_H

#include"rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "a1_msgs/msg/mode.hpp"
//int msg_pub_init(int argc, char * argv[]);

class PubNode: public rclcpp::Node
{
public:
    PubNode(std::string nodeName="pub_node"):Node(nodeName){
        walk_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        mode_pub = this->create_publisher<a1_msgs::msg::Mode>("cmd_mode", 10);
    }
    void publisherWalk(float forwardSpeed, float sideSpeed, float rotateSpeed);
    void publisherCmd(uint8_t mode, float value);
    bool keyboardPressProcess(char ch);
    void publisherReset();
    bool setValue(float *set_value, float base_val);
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr walk_pub;
    rclcpp::Publisher<a1_msgs::msg::Mode>::SharedPtr mode_pub;
};


#endif