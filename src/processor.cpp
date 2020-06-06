#include "processor.h"

#include "linux_parser.h"

float Processor::Utilization() {
    LinuxParser::CPUState state = LinuxParser::CpuUtilization();
    // TODO: math to add up correct #s
    return state.user;
}
