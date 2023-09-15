#ifndef TRABALHO_INE5412_ROUNDROBIN_H
#define TRABALHO_INE5412_ROUNDROBIN_H

#include "Scheduler.h"

class RoundRobin : public Scheduler {
public:
    RoundRobin() : Scheduler() {};

    Process *schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) override;
};

#endif //TRABALHO_INE5412_ROUNDROBIN_H
