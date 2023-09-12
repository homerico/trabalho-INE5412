
#ifndef TRABALHO_INE5412_FCFS_H
#define TRABALHO_INE5412_FCFS_H

#include <iostream>
#include "Scheduler.h"

using namespace std;

class FCFS: public Scheduler{
public:
    FCFS(vector<ProcessParams *> &processes);
    ~FCFS() = default;
    void schedule() override;
protected:
private:
};

#endif //TRABALHO_INE5412_FCFS_H
