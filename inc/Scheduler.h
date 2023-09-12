
#ifndef TRABALHO_INE5412_SCHEDULER_H
#define TRABALHO_INE5412_SCHEDULER_H

#include <vector>
#include "ProcessParams.h"
#include "Process.h"

class Scheduler {
public:
    explicit Scheduler(std::vector<ProcessParams *> &processes) {
        this->processParams = processes;
    };

    virtual ~Scheduler() = default;
    enum Type {FCFS = 1, SJF, Priority, PriorityWithPreemption, RoundRobin};
    virtual void schedule();

    virtual void execute();

protected:
    std::vector<ProcessParams *> processParams;
    std::vector<Process *> processes;
};

#endif //TRABALHO_INE5412_SCHEDULER_H
