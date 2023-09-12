
#include "RoundRobin.h"

RoundRobin::RoundRobin(std::vector<ProcessParams *> &processes) : Scheduler(processes) {
    preemptive = true;
}
