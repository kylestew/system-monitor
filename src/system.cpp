#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

Processor& System::Cpu() { return cpu_; }

std::vector<Process>& System::Processes() { return processes_; }

std::string System::Kernel() { return LinuxParser::Kernel(); }

float System::MemoryUtilization() { return 0.0; }

std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() { return 0; }

int System::TotalProcesses() { return 0; }

// Number of seconds since the system started
long int System::UpTime() { LinuxParser::UpTime(); }
