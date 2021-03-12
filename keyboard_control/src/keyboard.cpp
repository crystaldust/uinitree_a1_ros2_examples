#include "keyboard.h"
#include <iostream>

KeyBoard::KeyBoard() {
  tcgetattr(kfd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));

  raw.c_lflag &= ~(ICANON | ECHO);
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);

  ufd.fd = kfd;
  ufd.events = POLLIN;
}

char KeyBoard::readKey() {
  if ((rcv_num = poll(&ufd, 1, 250)) < 0) {
    std::cout << "poll rcv error code:" << rcv_num << std::endl;
    return '?';
  }
  // rcv_num is greater than 0
  if (read(kfd, &c, 1) < 0) {
    std::cout << "read kfd error" << std::endl;
    return '?';
  }

  return c;
}

void KeyBoard::freeKeyBoard()
{
    tcsetattr(kfd, TCSANOW, &cooked);
}