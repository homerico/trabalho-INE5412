
#ifndef TRABALHO_INE5412_PRIORITY_H
#define TRABALHO_INE5412_PRIORITY_H

#include "Scheduler.h"

class Priority: public Scheduler {
public:
    Priority(std::vector<ProcessParams *> &processes);
    ~Priority() = default;

};

#endif //TRABALHO_INE5412_PRIORITY_H
