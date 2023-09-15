
#include "RoundRobin.h"

Process *RoundRobin::schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) {
    return Scheduler::schedule(waitingProcesses, runningProcess);
}
