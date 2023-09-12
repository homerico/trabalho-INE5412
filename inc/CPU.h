
#ifndef TRABALHO_INE5412_CPU_H
#define TRABALHO_INE5412_CPU_H

#include <vector>
#include "Context.h"
#include "ProcessParams.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "PriorityWithPreemption.h"
#include "RoundRobin.h"

class CPU
{
public:
    CPU(int alg, const vector<ProcessParams *> & processes) {
        type = Scheduler::Type(alg);
        this->processes = processes;
        scheduler = getScheduler();
    }

    ~CPU() {
        delete scheduler;
    };

    void run();

    void workIn(ProcessParams * process);

private:
    // static variables
    const char* id = "INE5412";

    // instance variables
    Scheduler * scheduler;
    Scheduler::Type type;
    vector<ProcessParams *> processes;

    // methods
    Scheduler * getScheduler();
};

#endif //TRABALHO_INE5412_CPU_H
