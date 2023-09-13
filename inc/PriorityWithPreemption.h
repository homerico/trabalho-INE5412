
#ifndef TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
#define TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H

#include "Scheduler.h"

class PriorityWithPreemption : public Scheduler {
public:
    PriorityWithPreemption() : Scheduler() {};

    std::pair<Process *, int> schedule(std::vector<Process *> &runningProcesses) override;
};

#endif //TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
