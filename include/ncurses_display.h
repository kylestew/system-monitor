#pragma once
#include <curses.h>
#include <vector>

#include "process.h"
#include "system.h"

namespace NCursesDisplay {

void Display(System& system, int n = 10);
void DisplaySystem(System& system, WINDOW* window);
void DisplayProcesses(std::vector<Process>& process, WINDOW* window, int n);
std::string ProgressBar(float percent);

};  // namespace NCursesDisplay
