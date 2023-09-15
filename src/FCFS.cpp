
#include "FCFS.h"

Process *FCFS::schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) {
    if (runningProcess != nullptr && !runningProcess->isFinished()) {
        return runningProcess;
    }
    Process *process = waitingProcesses.at(0);
    waitingProcesses.erase(waitingProcesses.begin());
    return process;
}
