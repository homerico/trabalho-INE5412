
#include "SJF.h"

std::pair<Process *, int> SJF::schedule(std::vector<Process *> &runningProcesses) {
    return Scheduler::schedule(runningProcesses);
}
