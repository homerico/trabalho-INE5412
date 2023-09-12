
#ifndef TRABALHO_INE5412_PROCESS_H
#define TRABALHO_INE5412_PROCESS_H

#include "ProcessParams.h"

class Process {
public:
    Process(ProcessParams &params, unsigned pid);
    ~Process();
    void run();
    enum State {NEW = 0, READY, RUNNING, BLOCKED, TERMINATED};
private:
    unsigned pid;
    int state;

    int priority;
    int duration;
    int creationTime;
    int finalTime;
    int waitingTime;
    int contextSwitches;
};

#endif //TRABALHO_INE5412_PROCESS_H
