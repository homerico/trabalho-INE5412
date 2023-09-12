
#include "FCFS.h"

void FCFS::schedule() {
    for (unsigned i = 0; i < this->processParams.size(); i++) {
        ProcessParams processParams = *this->processParams[i];
        processes.push_back(new Process(processParams, i));
    }
}

FCFS::FCFS(vector<ProcessParams *> &processes) : Scheduler(processes) {
//    cout << "FCFS" << endl;
//    for (auto &process : processes) {
//        cout << *process << endl;
//    }
}

void FCFS::execute() {
    for (auto &process : processes) {
        process->run();
    }
}
