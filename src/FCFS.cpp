
#include "FCFS.h"

void FCFS::schedule() {
    cout << "teste" << endl;
    // TODO
}

FCFS::FCFS(vector<ProcessParams *> &processes) : Scheduler(processes) {
    cout << "FCFS" << endl;
    for (auto &process : processes) {
        cout << *process << endl;
    }
}
