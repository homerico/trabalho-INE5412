
#ifndef TRABALHO_INE5412_PRIORITY_H
#define TRABALHO_INE5412_PRIORITY_H

#include "Scheduler.h"

class Priority: public Scheduler {
public:
    Priority() {};
    ~Priority() {delete this;};

};

#endif //TRABALHO_INE5412_PRIORITY_H
