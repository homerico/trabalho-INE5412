
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

using namespace std;
class CPU
{
public:
    CPU(int alg, const vector<ProcessParams *> & processes) {
        type = Scheduler::Type(alg);
        scheduler = getScheduler();
        this->processes = processes;
    }

    ~CPU() = default;

    void run();

protected:
private:
    Scheduler * getScheduler();
    Scheduler * scheduler;
    Scheduler::Type type;
    vector<ProcessParams *> processes;
    const char* id = "INE5412";
};

#endif //TRABALHO_INE5412_CPU_H
