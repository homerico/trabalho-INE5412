
#ifndef TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
#define TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H

#include "Scheduler.h"

class PriorityWithPreemption: public Scheduler {
public:
    PriorityWithPreemption(std::vector<ProcessParams *> &processes);
    ~PriorityWithPreemption() = default;
};

#endif //TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
