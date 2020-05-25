#pragma once

#include <fstream>
#include <string>

namespace LinuxParser {
// paths
const std::string kProcDirectory{"/proc/"};

const std::string kUptimeFilename{"/uptime"};

// System
long UpTime();

// Processes
long int UpTime(int pid);
};  // namespace LinuxParser
