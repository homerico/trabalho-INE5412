
#ifndef TRABALHO_INE5412_SCHEDULER_H
#define TRABALHO_INE5412_SCHEDULER_H

#include <vector>
#include "Process.h"

class Scheduler {
public:
    Scheduler() = default;
    virtual ~Scheduler() = default;

    enum Type {
        FCFS = 1, SJF, Priority, PriorityWithPreemption, RoundRobin
    };

    virtual Process *schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess);
};

#endif //TRABALHO_INE5412_SCHEDULER_H
