#ifndef TRABALHO_INE5412_ROUNDROBIN_H
#define TRABALHO_INE5412_ROUNDROBIN_H

#include "Scheduler.h"

class RoundRobin : public Scheduler {
public:
    RoundRobin() : Scheduler() {};

    std::pair<Process *, int> schedule(std::vector<Process *> &runningProcesses) override;
};

#endif //TRABALHO_INE5412_ROUNDROBIN_H
