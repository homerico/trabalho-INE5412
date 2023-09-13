
#include <csignal>
#include <iostream>
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

void Process::run(int time) {
    std::cout << "Process " << pid << ": Running" << std::endl;
    state = State::RUNNING;
    sleep(time);
    finalTime += time;
    if (duration == finalTime) {
        state = State::TERMINATED;
        std::cout << "Process " << pid << ": Terminated" << std::endl;
    } else {
        state = State::BLOCKED;
        std::cout << "Process " << pid << ": Blocked" << std::endl;
    }
}

bool Process::isFinished() {
    if (state == State::TERMINATED) {
        return true;
    }
    return false;
}

int Process::getCreationTime() {
    return creationTime;
}

int Process::getDuration() {
    return duration;
}

void Process::addWaitingTime(int time) {
    waitingTime += time;
}
