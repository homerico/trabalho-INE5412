
#ifndef TRABALHO_INE5412_PROCESS_H
#define TRABALHO_INE5412_PROCESS_H

#include <cstdint>
#include "ProcessParams.h"
#include "Context.h"

class Process {
public:
    Process(ProcessParams &params, unsigned pid, Context *cx);

    ~Process();

    void execute(int time = 1);

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

    int getPriority();

    void addWaitingTime(int time);

    long getTurnaroundTime();

    long getWaitingTime();
    
    void saveContext(Context* cx);

    Context* getContext();

    void incrementDynamicPriority();

    int getDynamicPriority();

private:
    unsigned pid;
    int state;

    int priority;
    int duration;
    int creationTime;
    int dynamicPriority;
    int finalTime;
    int waitingTime;
    int contextSwitches;
<<<<<<< HEAD

    uint64_t* context;
=======
    Context* cx;
>>>>>>> e3446c3 (Refactor)
};

#endif //TRABALHO_INE5412_PROCESS_H
