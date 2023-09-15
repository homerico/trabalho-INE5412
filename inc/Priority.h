
#ifndef TRABALHO_INE5412_PRIORITY_H
#define TRABALHO_INE5412_PRIORITY_H

#include "Scheduler.h"

class Priority : public Scheduler {
public:
    Priority() : Scheduler() {};

    Process *schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) override;
};

#endif //TRABALHO_INE5412_PRIORITY_H
