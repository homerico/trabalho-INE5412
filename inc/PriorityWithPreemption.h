
#ifndef TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
#define TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H

#include "Scheduler.h"

class PriorityWithPreemption: public Scheduler {
public:
    PriorityWithPreemption() {};
    ~PriorityWithPreemption() {delete this;};
};

#endif //TRABALHO_INE5412_PRIORITYWITHPREEMPTION_H
