#include "process.h"
#include "linux_parser.h"

using std::string;

string Process::User() { return LinuxParser::User(pid); }

string Process::Command() { return ""; }

float Process::CpuUtilization() const {
    LinuxParser::ProcTime time = LinuxParser::ProcessTime(pid);
    long int total_time = time.utime + time.stime;

    return total_time / 100.0;
}

string Process::Ram() { return ""; }

long int Process::UpTime() { return 0; }

bool Process::operator<(const Process& rhs) const {
    return CpuUtilization() > rhs.CpuUtilization();
}
