#include "ncurses_display.h"
#include "system.h"

#include <iostream>
#include "format.h"
#include "linux_parser.h"

int main() {
    System system;

    // std::cout << LinuxParser::OperatingSystem() << std::endl;

    // std::cout << Format::ElapsedTime(LinuxParser::UpTime()) << std::endl;

    NCursesDisplay::Display(system);
}
