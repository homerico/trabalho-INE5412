
#ifndef TRABALHO_INE5412_SCHEDULER_H
#define TRABALHO_INE5412_SCHEDULER_H


class Scheduler {
public:
    Scheduler();
    ~Scheduler();
    bool is_preemptive();

protected:
    bool preemptive;

};


#endif //TRABALHO_INE5412_SCHEDULER_H
