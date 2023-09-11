
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
    switch (this->type) {
        case Scheduler::FCFS:
            FCFS().schedule();
            break;
        case Scheduler::SJF:
            SJF().schedule();
            break;
        case Scheduler::Priority:
            Priority().schedule();
            break;
        case Scheduler::PriorityWithPreemption:
            PriorityWithPreemption().schedule();
            break;
        case Scheduler::RoundRobin:
            RoundRobin().schedule();
            break;
        default:
            cout << "CPU " << id << ": Invalid scheduler" << endl;
    }
    cout << "CPU " << id << ": Finished" << endl;
}