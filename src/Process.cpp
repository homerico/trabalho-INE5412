
#include <csignal>
#include "Process.h"

Process::Process(ProcessParams &params, unsigned pid) {
    this->pid = pid;
    state = State::NEW;
    priority = params.getPriority();
    duration = params.getDuration();
    creationTime = params.getCreationTime();
    finalTime = 0;
    waitingTime = 0;
    contextSwitches = 0;
}

Process::~Process() = default;

void Process::run() {
    sleep(duration);
}
