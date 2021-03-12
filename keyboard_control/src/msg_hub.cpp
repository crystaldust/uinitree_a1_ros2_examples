//
// Created by lance on 3/12/21.
//
#include "msg_hub.h"

MessageHub::MessageHub(Keyboard &keyboard, std::shared_ptr<PubNode>& pubNode) {
  this->keyboard = keyboard;
  this->pubNode = pubNode;
}

void MessageHub::messageLoop() {
  while(true) {
    boost::this_thread::interruption_point();
    char ch = this->keyboard->readKey();
    // Do something with pubNode
  }
}

void MessageHub::releaseResources() {

}