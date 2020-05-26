#pragma once

#include <fstream>
#include <string>

namespace LinuxParser {
// paths
const std::string kProcDirectory{"/proc/"};

const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kUptimeFilename{"/uptime"};

// System
long UpTime();
std::string OperatingSystem();
std::string Kernel();

// Processes
long int UpTime(int pid);
};  // namespace LinuxParser
