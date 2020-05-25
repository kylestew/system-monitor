
#include "system.h"

#include "linux_parser.h"

// Number of seconds since the system started
long int System::UpTime() { LinuxParser::UpTime(); }
