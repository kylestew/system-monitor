#include <algorithm>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

Processor& System::Cpu() { return cpu_; }

std::vector<Process>& System::Processes() {
    processes_.clear();
    for (auto pid : LinuxParser::Pids()) {
        processes_.push_back(Process(pid));
    }

    // sort by CPUUtilization() using the < operator
    std::sort(processes_.begin(), processes_.end());

    return processes_;
}

std::string System::Kernel() { return LinuxParser::Kernel(); }

float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// Number of seconds since the system started
long int System::UpTime() { return LinuxParser::UpTime(); }
