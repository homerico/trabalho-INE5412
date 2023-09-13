
#ifndef TRABALHO_INE5412_PROCESS_H
#define TRABALHO_INE5412_PROCESS_H

#include "ProcessParams.h"

class Process {
public:
    Process(ProcessParams &params, unsigned pid);

    ~Process();

    void run(int time);

    enum State {
        NEW = 0, READY, RUNNING, BLOCKED, TERMINATED
    };

    bool isFinished();

    unsigned getPid() const {
        return pid;
    }

    int getState() {
        return state;
    }

    void setState(int state) {
        this->state = state;
    }

    int getCreationTime();

    int getDuration();

    void addWaitingTime(int time);

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
