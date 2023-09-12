
#include <iostream>
#include "CPU.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "PriorityWithPreemption.h"
#include "RoundRobin.h"

using namespace std;

void CPU::run() {
    cout << "CPU " << id << ": Running" << endl;
    //scheduler->schedule(processes);
    cout << "CPU " << id << ": Finished" << endl;
}

Scheduler *CPU::getScheduler() {
    switch (this->type) {
        case Scheduler::FCFS:
            return new FCFS();
        case Scheduler::SJF:
            return new SJF();
        case Scheduler::Priority:
            return new Priority();
        case Scheduler::PriorityWithPreemption:
            return new PriorityWithPreemption();
        case Scheduler::RoundRobin:
            return new RoundRobin();
        default:
            cout << "CPU " << id << ": Invalid scheduler" << endl;
            return nullptr;
    }
}
