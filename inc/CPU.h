
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

class CPU {
public:
    CPU(int alg, const std::vector<ProcessParams *> &processParams) {
        type = Scheduler::Type(alg);
        scheduler = getScheduler();
        runningTime = 0;

        for (unsigned i = 0; i < processParams.size(); i++) {
            ProcessParams processParams1 = *processParams[i];
            processes.push_back(new Process(processParams1, i));
        }
    }

    ~CPU() {
        delete scheduler;
        for (auto p : processes) {
            delete p;
        }
    };

    void run();

private:
    // static variables
    const char *id = "INE5412";

    // instance variables
    int runningTime;
    Scheduler *scheduler;
    Scheduler::Type type;
    std::vector<Process *> processes;
    std::vector<Process *> runningProcesses;

    // methods
    bool isFinished();

    Scheduler *getScheduler();

    void processesToReadyInTime();

    void unblockProcesses();

    void updateRunningProcesses();
};

#endif //TRABALHO_INE5412_CPU_H
