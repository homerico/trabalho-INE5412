
#ifndef TRABALHO_INE5412_CPU_H
#define TRABALHO_INE5412_CPU_H

#include <vector>
#include <map>
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
        contextSwitches = 0;
        runningProcess = nullptr;

        for (unsigned i = 0; i < processParams.size(); i++) {
            ProcessParams processParams1 = *processParams[i];
            notStartedProcesses.push_back(new Process(processParams1, i));
        }
    }

    ~CPU() {
        delete scheduler;
        for (auto p : terminatedProcesses) {
            delete p;
        }
    };

    void run();

    void printReport();

private:
    // static variables
    const char *id = "INE5412";

    // instance variables
    int contextSwitches;
    int runningTime;
    Process *runningProcess;
    Scheduler *scheduler;
    Scheduler::Type type;
    //std::vector<std::vector<std::pair<int, int>>> executionTimeDiagram;
    std::vector<Process *> notStartedProcesses;
    std::vector<Process *> waitingProcesses;
    std::vector<Process *> terminatedProcesses;

    // methods
    bool isFinished();

    Scheduler *getScheduler();

    void processesToReadyInTime();

    void unblockProcesses();

    void updateWaitingProcesses();

    void addWaitingTimeToWaitingProcesses(int time = 1);

    void updateRunningProcess(Process *pProcess);

    void storeStates();
};

#endif //TRABALHO_INE5412_CPU_H
