
#include "Priority.h"

Process *Priority::schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) {
    if (runningProcess != nullptr && !runningProcess->isFinished()) {
        return runningProcess;
    }
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
    waitingProcesses.erase(waitingProcesses.begin() + mostPriorityProcessIndex);
    return mostPriorityProcess;
}
