
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
    scheduler->schedule();
    scheduler->execute();
    cout << "CPU " << id << ": Finished" << endl;
}

Scheduler *CPU::getScheduler() {
    switch (this->type) {
        case Scheduler::FCFS:
            return new FCFS(this->processes);
        case Scheduler::SJF:
            return new SJF(this->processes);
        case Scheduler::Priority:
            return new Priority(this->processes);
        case Scheduler::PriorityWithPreemption:
            return new PriorityWithPreemption(this->processes);
        case Scheduler::RoundRobin:
            return new RoundRobin(this->processes);
        default:
            cout << "CPU " << id << ": Invalid scheduler" << endl;
            return nullptr;
    }
}

void CPU::workIn(ProcessParams *process) {
    cout << "CPU " << id << ": Working in " << *process << endl;

}
