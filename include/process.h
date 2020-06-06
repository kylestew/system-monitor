#pragma once

#include <string>

class Process {
public:
    Process(int pid) : pid(pid) {}
    std::string User();
    std::string Command();
    float CpuUtilization();
    std::string Ram();
    long int UpTime();
    bool operator<(Process const& a) const;

    int pid;

private:
};
