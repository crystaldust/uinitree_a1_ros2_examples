//
// Created by lance on 3/12/21.
//

#ifndef UINITREE_A1_ROS2_EXAMPLES_MESSAGE_HUB_H
#define UINITREE_A1_ROS2_EXAMPLES_MESSAGE_HUB_H

#include "keyboard.h"
#include "msg_pub.h"

// A hub to integrate message and keyboard
class MessageHub {
public:
  MessageHub():keyboard(), pubNode("msg_pub_node") {}
  MessageHub(KeyBoard &, std::shared_ptr<PubNode>&);
  void messageLoop();
  void releaseResources();

private:
  KeyBoard keyboard;
  PubNode pubNode;
};

#endif //UINITREE_A1_ROS2_EXAMPLES_MESSAGE_HUB_H
