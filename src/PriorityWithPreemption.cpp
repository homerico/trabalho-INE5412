
#include "PriorityWithPreemption.h"

std::pair<Process *, int> PriorityWithPreemption::schedule(std::vector<Process *> &runningProcesses) {
    return Scheduler::schedule(runningProcesses);
}
