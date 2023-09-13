
#include "Priority.h"

std::pair<Process *, int> Priority::schedule(std::vector<Process *> &runningProcesses) {
    return Scheduler::schedule(runningProcesses);
}
