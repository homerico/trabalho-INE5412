
#include <iostream>
#include "CPU.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "PriorityWithPreemption.h"
#include "RoundRobin.h"

void CPU::run() {
    std::cout << "CPU " << id << ": Running" << std::endl;

    do {
        unblockProcesses();
        processesToReadyInTime();
        std::pair<Process *, int> PAIR = scheduler->schedule(runningProcesses);
        PAIR.first->run(PAIR.second);
        runningTime += PAIR.second;
        PAIR.first->addWaitingTime(PAIR.second);
        updateRunningProcesses();
    } while (!isFinished());
    std::cout << "CPU " << id << ": Finished" << std::endl;
}

Scheduler *CPU::getScheduler() {
    switch (this->type) {
        case Scheduler::FCFS:
            return new FCFS();
        case Scheduler::SJF:
            return new SJF();
        case Scheduler::Priority:
            return new Priority();
        case Scheduler::PriorityWithPreemption:
            return new PriorityWithPreemption();
        case Scheduler::RoundRobin:
            return new RoundRobin();
        default:
            std::cout << "CPU " << id << ": Invalid scheduler" << std::endl;
            return nullptr;
    }
}

bool CPU::isFinished() {
    bool finished = true;
    for (auto &process: processes) {
        finished = finished && process->isFinished();
    }
    return finished;
}

void CPU::processesToReadyInTime() {
    for (auto &process: processes) {
        //FIXME: está colocando processos que já terminaram no running processes
        if (process->getCreationTime() <= runningTime && !process->isFinished()) {
            process->setState(Process::State::READY);
            runningProcesses.push_back(process);
        }
    }
}

void CPU::unblockProcesses() {
    for (auto &process: processes) {
        if (process->getState() == Process::State::BLOCKED) {
            process->setState(Process::State::READY);
        }
    }

}

void CPU::updateRunningProcesses() {
    for (unsigned i = 0; i < runningProcesses.size(); ++i) {
        if (runningProcesses.at(i)->isFinished()) {
            runningProcesses.erase(runningProcesses.begin() + i);
        }
    }
}
