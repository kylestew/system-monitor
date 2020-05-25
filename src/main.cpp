//#include "ncurses_display.h"
#include "system.h"

#include <iostream>
#include "linux_parser.h"

int main() {
  System system;

  std::cout << system.UpTime() << std::endl;

  // std::cout << LinuxParser::UpTime() << std::endl;

  //    NCursesDisplay::Display(system);
}
