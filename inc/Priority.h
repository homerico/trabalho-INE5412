
#ifndef TRABALHO_INE5412_PRIORITY_H
#define TRABALHO_INE5412_PRIORITY_H

#include "Scheduler.h"

class Priority : public Scheduler {
public:
    Priority() : Scheduler() {};

    std::pair<Process *, int> schedule(std::vector<Process *> &runningProcesses) override;
};

#endif //TRABALHO_INE5412_PRIORITY_H
