#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "linux_parser.h"

using std::string;

// == System ==
long LinuxParser::UpTime() {
    std::ifstream stream(kProcDirectory + kUptimeFilename);
    long uptime;
    if (stream.is_open()) {
        stream >> uptime;
    }
    return uptime;
}

std::string LinuxParser::OperatingSystem() {
    string line, key, value;
    std::ifstream stream(kOSPath);
    if (stream.is_open()) {
        // search for the line we need
        while (std::getline(stream, line)) {
            // make line easier to parse
            std::replace(line.begin(), line.end(), ' ', '_');
            std::replace(line.begin(), line.end(), '=', ' ');
            std::replace(line.begin(), line.end(), '"', ' ');

            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "PRETTY_NAME") {
                    // found it!

                    // undo parse helper
                    std::replace(value.begin(), value.end(), '_', ' ');
                    return value;
                }
            }
        }
    }
    return "(unknown)";
}

std::string LinuxParser::Kernel() {
    string skip, kernel;
    std::ifstream stream(kProcDirectory + kVersionFilename);
    if (stream.is_open()) {
        stream >> skip >> skip >> kernel;
    }
    return kernel;
}
