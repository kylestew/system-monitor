#include "process.h"

using std::string;

string Process::User() { return ""; }

string Process::Command() { return ""; }

float Process::CpuUtilization() { return 0; }

string Process::Ram() { return ""; }

long int Process::UpTime() { return 0; }

bool Process::operator<(Process const& a) const { return true; }
