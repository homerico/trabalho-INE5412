
#include "PriorityWithPreemption.h"

Process *PriorityWithPreemption::schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) {
    Process *mostPriorityProcess;
    unsigned mostPriorityProcessIndex = 0;
    int priority = 0;
    for (unsigned int i = 0; i < waitingProcesses.size(); i++) {
        if (waitingProcesses[i]->getPriority() > priority) {
            priority = waitingProcesses[i]->getPriority();
            mostPriorityProcess = waitingProcesses[i];
            mostPriorityProcessIndex = i;
        }
    }
    if (runningProcess != nullptr && runningProcess->getPriority() > priority) {
        mostPriorityProcess = runningProcess;
    } else {
        waitingProcesses.erase(waitingProcesses.begin() + mostPriorityProcessIndex);
    }

    return mostPriorityProcess;
}
