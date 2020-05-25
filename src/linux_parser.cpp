#include <string>

#include "linux_parser.h"

using std::string;

// == System ==
long LinuxParser::UpTime() {
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  long uptime, idle;
  if (stream.is_open()) {
    stream >> uptime >> idle;
  }
  return uptime;
}
