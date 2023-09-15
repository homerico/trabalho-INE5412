
#ifndef TRABALHO_INE5412_SJF_H
#define TRABALHO_INE5412_SJF_H

#include "Scheduler.h"

class SJF : public Scheduler {
public:
    SJF() : Scheduler() {};

    Process *schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) override;
};

#endif //TRABALHO_INE5412_SJF_H
