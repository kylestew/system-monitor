#pragma once
#include <curses.h>
#include <vector>

#include "system.h"
#include "process.h"

namespace NCursesDisplay {

    void Display(System &system, int n = 10);
    void DisplaySystem(System &system, WINDOW* window);
    void DisplayProcess(std::vector<Process> &process, WINDOW* window, int n);
    std::string ProgressBar(float percent);

};
