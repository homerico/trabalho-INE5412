
#include <csignal>
#include <iostream>
#include "Process.h"

Process::Process(ProcessParams &params, unsigned pid, Context *cx) {
    this->pid = pid;
    this->cx = cx;
    state = State::NEW;
    priority = params.getPriority();
    duration = params.getDuration();
    creationTime = params.getCreationTime();
    finalTime = 0;
    waitingTime = 0;
    dynamicPriority = 0;
}

Process::~Process() = default;

void Process::execute(int time) {
    state = State::RUNNING;
    sleep(time);
    finalTime += time;
    if (duration == finalTime) {
        state = State::TERMINATED;
    }
}

bool Process::isFinished() {
    if (duration == finalTime){
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

int Process::getPriority() {
    return priority;
}

long Process::getTurnaroundTime() {
    return duration + waitingTime;
}

long Process::getWaitingTime() {
    return waitingTime;
}

void Process::saveContext(Context* cx) {
	this->cx = cx;
}

Context* Process::getContext() {
	return cx;
}

void Process::incrementDynamicPriority() {
    dynamicPriority++;
}

int Process::getDynamicPriority() {
    return dynamicPriority;
}
