#pragma once

#include <string>

class Process {
public:
    Process(int pid) : pid(pid) {}
    std::string User();
    std::string Command();
    float CpuUtilization() const;
    std::string Ram();
    long int UpTime();
    bool operator<(const Process& rhs) const;

    int pid;

private:
};
