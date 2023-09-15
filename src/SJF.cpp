
#include <limits>
#include "SJF.h"

Process *SJF::schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) {
    if (runningProcess != nullptr && !runningProcess->isFinished()) {
        return runningProcess;
    }
    Process *lessDurationProcess;
    unsigned lessDurationProcessIndex = 0;
    int duration = std::numeric_limits<int>::max();
    for (unsigned int i = 0; i < waitingProcesses.size(); i++) {
        if (waitingProcesses[i]->getDuration() < duration) {
            duration = waitingProcesses[i]->getDuration();
            lessDurationProcess = waitingProcesses[i];
            lessDurationProcessIndex = i;
        }
    }
    waitingProcesses.erase(waitingProcesses.begin() + lessDurationProcessIndex);
    return lessDurationProcess;
}
