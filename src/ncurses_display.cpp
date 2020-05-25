#include <curses.h>
#include <chrono>
#include <thread>
#include <vector>

#include "ncurses_display.h"
#include "system.h"



void NCursesDisplay::DisplaySystem(System &system, WINDOW *window) {
    int row{0};
    //mvwprintw(window, ++row, 2, ("OS: " + system.OperatingSystem()).c_str());
    mvwprintw(window, ++row, 2, "OS: N/A");


    wrefresh(window);
}

void NCursesDisplay::DisplayProcess(std::vector<Process>& processes, WINDOW* window, int n) {
    int row{0};

    int const pid_column{2};

    mvwprintw(window, ++row, pid_column, "PID");
}

void NCursesDisplay::Display(System &system, int n) {
    // start ncurses
    initscr();
    // do not print input values
    noecho();
    // terminate ncurses on ctrl + c
    cbreak();
    // enable color
    start_color();

    int x_max{getmaxx(stdscr)};
    WINDOW *system_window = newwin(9, x_max - 1, 0, 0);

    while(1) {
        // color pairs?
        init_pair(1, COLOR_BLUE, COLOR_BLACK);

        // draw border on window
        box(system_window, 0, 0);

        DisplaySystem(system, system_window);

        wrefresh(system_window);
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    endwin();
}
