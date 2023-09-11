#ifndef TRABALHO_INE5412_ROUNDROBIN_H
#define TRABALHO_INE5412_ROUNDROBIN_H

#include "Scheduler.h"

class RoundRobin: public Scheduler {
public:
    RoundRobin() {};
    ~RoundRobin() {delete this;};
};

#endif //TRABALHO_INE5412_ROUNDROBIN_H
