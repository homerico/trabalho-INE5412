
#ifndef TRABALHO_INE5412_PROCESS_H
#define TRABALHO_INE5412_PROCESS_H

class Process {
public:
    Process();
    ~Process();
    void run();
    enum State {RUNNING, READY, BLOCKED, NEW, TERMINATED};
};

#endif //TRABALHO_INE5412_PROCESS_H
