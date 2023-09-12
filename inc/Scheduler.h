
#ifndef TRABALHO_INE5412_SCHEDULER_H
#define TRABALHO_INE5412_SCHEDULER_H

#include <vector>
#include "ProcessParams.h"

class Scheduler {
public:
    explicit Scheduler(std::vector<ProcessParams *> &processes) {
        preemptive = false;
        this->processes = processes;
    };

    virtual ~Scheduler() = default;
    enum Type {FCFS = 1, SJF, Priority, PriorityWithPreemption, RoundRobin};
    bool is_preemptive();
    virtual void schedule();

protected:
    std::vector<ProcessParams *> processes;
    bool preemptive;
};

#endif //TRABALHO_INE5412_SCHEDULER_H
