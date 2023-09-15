
#ifndef TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
#define TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H

#include "Scheduler.h"

class PriorityWithPreemption : public Scheduler {
public:
    PriorityWithPreemption() : Scheduler() {};

    Process *schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) override;
};

#endif //TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
