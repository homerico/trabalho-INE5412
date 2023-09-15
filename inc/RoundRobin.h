#ifndef TRABALHO_INE5412_ROUNDROBIN_H
#define TRABALHO_INE5412_ROUNDROBIN_H

#include "Scheduler.h"

class RoundRobin : public Scheduler {
public:
    RoundRobin(int quantum) : Scheduler() {
        this->quantum = quantum;
        this->counter = 0;
    };

    Process *schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) override;
private:
    int quantum;
    int counter;

    static void reorderWaitingProcessesByDynamicPriority(std::vector<Process *> &vector);
};

#endif //TRABALHO_INE5412_ROUNDROBIN_H
