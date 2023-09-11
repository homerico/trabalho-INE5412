
#ifndef TRABALHO_INE5412_SCHEDULER_H
#define TRABALHO_INE5412_SCHEDULER_H

#include <vector>

class Scheduler {
public:
    Scheduler() {preemptive = false;};
    ~Scheduler() {delete this;};
    enum Type {FCFS = 1, SJF, Priority, PriorityWithPreemption, RoundRobin};
    bool is_preemptive();
    virtual void schedule();

protected:
    bool preemptive;
};

#endif //TRABALHO_INE5412_SCHEDULER_H
