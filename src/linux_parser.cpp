#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "linux_parser.h"

using std::string;

// == System ==

float LinuxParser::MemoryUtilization() {
    long total, free = 0;

    string line, key, value;
    std::ifstream stream(kProcDirectory + kMeminfoFilename);
    if (stream.is_open()) {
        // search for the line(s) we need
        while (std::getline(stream, line)) {
            // make line easier to parse
            std::replace(line.begin(), line.end(), ':', ' ');

            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "MemTotal") {
                    total = std::stol(value);
                } else if (key == "MemFree") {
                    free = std::stol(value);
                }
            }
        }
    }

    return (float)(total - free) / (float)total;
}

long LinuxParser::UpTime() {
    std::ifstream stream(kProcDirectory + kUptimeFilename);
    long uptime;
    if (stream.is_open()) {
        stream >> uptime;
    }
    return uptime;
}

/**
 * Reads an int value for key from a given file
 */
int readKeyFromFile(string key, string file) {
    std::ifstream stream(file);
    string line, _key, val;
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::istringstream linestream(line);
            if (linestream >> _key >> val) {
                if (_key == key) {
                    return std::stoi(val);
                }
            }
        }
    }
    return -1;
}

int LinuxParser::TotalProcesses() {
    return readKeyFromFile("processes", kProcDirectory + kStatFilename);
}

int LinuxParser::RunningProcesses() {
    return readKeyFromFile("procs_running", kProcDirectory + kStatFilename);
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
