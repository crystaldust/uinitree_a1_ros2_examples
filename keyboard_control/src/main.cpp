#include "keyboard.h"
#include "msg_hub.h"
#include "msg_pub.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    KeyBoard keyboard;
    auto keyboardMsgNode = std::make_shared<PubNode>("keyboard_msg_pub");

    MessageHub msgHub(keyboard, keyboardMsgNode);

    /*create pthread monitor keyboard*/
    boost::thread t = boost::thread(boost::bind(&MessageHub::messageLoop, &msgHub));

    rclcpp::spin(keyboardMsgNode);
    rclcpp::shutdown();

    keyboard.freeKeyBoard();
    return 0;
}