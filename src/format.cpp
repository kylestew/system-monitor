#include "format.h"
#include <iomanip>
#include <sstream>
#include <string>

using std::string;

/**
 * Converts seconds to HH:MM:SS formatting
 */
string Format::ElapsedTime(long seconds) {
    int h = seconds / (60 * 60);
    int s = seconds - h * (60 * 60);
    int m = s / 60;
    s -= m * 60;

    // cap at 99 hrs
    if (h > 99) h = 99;

    // format output using streams :)
    std::ostringstream buf;
    buf.fill('0');
    buf << std::setw(2) << h;
    buf << std::setw(1) << ':';
    buf << std::setw(2) << m;
    buf << std::setw(1) << ':';
    buf << std::setw(2) << s;
    return buf.str();
}

