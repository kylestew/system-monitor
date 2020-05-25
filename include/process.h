#pragma once

#include <string>

class Process {
    public:
        int Pid();
        std::string User();
        std::string Command();
        float CpuUtilization();
        std::string Ram();
        long int UpTime();
        bool operator<(Process const &a) const;

    private:
};
