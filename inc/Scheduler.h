
#ifndef TRABALHO_INE5412_SCHEDULER_H
#define TRABALHO_INE5412_SCHEDULER_H

#include <vector>
#include "Process.h"

class Scheduler {
public:
    virtual ~Scheduler() = default;

    enum Type {
        FCFS = 1, SJF, Priority, PriorityWithPreemption, RoundRobin
    };

    virtual std::pair<Process *, int> schedule(std::vector<Process *> &runningProcesses);
protected:
};

#endif //TRABALHO_INE5412_SCHEDULER_H
