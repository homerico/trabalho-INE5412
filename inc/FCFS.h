
#ifndef TRABALHO_INE5412_FCFS_H
#define TRABALHO_INE5412_FCFS_H

#include <iostream>
#include "Scheduler.h"

class FCFS : public Scheduler {
public:
    explicit FCFS() : Scheduler() {};

    Process *schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) override;
};

#endif //TRABALHO_INE5412_FCFS_H
