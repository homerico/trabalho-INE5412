
#include "FCFS.h"

std::pair<Process *, int> FCFS::schedule(std::vector<Process *> &runningProcesses) {
    std::pair<Process *, int> PAIR;
    PAIR.first = runningProcesses[0];
    PAIR.second = runningProcesses[0]->getDuration();
    return PAIR;
}
