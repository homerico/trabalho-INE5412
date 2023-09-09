
#include "Scheduler.h"

Scheduler::Scheduler() {
    preemptive = false;
}

Scheduler::~Scheduler() {
    delete this;
}

bool Scheduler::is_preemptive() {
    return preemptive;
}
