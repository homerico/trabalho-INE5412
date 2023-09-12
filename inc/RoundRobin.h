#ifndef TRABALHO_INE5412_ROUNDROBIN_H
#define TRABALHO_INE5412_ROUNDROBIN_H

#include "Scheduler.h"

class RoundRobin: public Scheduler {
public:
    RoundRobin(std::vector<ProcessParams *> &processes);
    ~RoundRobin() = default;
};

#endif //TRABALHO_INE5412_ROUNDROBIN_H
