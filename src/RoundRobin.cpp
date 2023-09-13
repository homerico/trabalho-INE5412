
#include "RoundRobin.h"

std::pair<Process *, int> RoundRobin::schedule(std::vector<Process *> &runningProcesses) {
    return Scheduler::schedule(runningProcesses);
}
