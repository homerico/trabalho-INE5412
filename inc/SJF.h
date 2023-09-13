
#ifndef TRABALHO_INE5412_SJF_H
#define TRABALHO_INE5412_SJF_H

#include "Scheduler.h"

class SJF : public Scheduler {
public:
    SJF() : Scheduler() {};

    std::pair<Process *, int> schedule(std::vector<Process *> &runningProcesses) override;
};

#endif //TRABALHO_INE5412_SJF_H
