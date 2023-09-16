
#include <iostream>
#include "CPU.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "PriorityWithPreemption.h"
#include "RoundRobin.h"

void CPU::run() {
    std::cout << "CPU " << id << ": Running" << std::endl;
    logger->printHeader();
    do {
        processesToReadyInTime();
        updateRunningProcess(
                scheduler->schedule(waitingProcesses, runningProcess));
        if (runningProcess != nullptr) {
	    loadContext(runningProcess->getContext());
            runningProcess->execute();
        }
        addWaitingTimeToWaitingProcesses();
        unblockProcesses();
        updateWaitingProcesses();
        logger->printState(runningTime++, processes);
    } while (!isFinished());
    std::cout << "CPU " << id << ": Finished" << std::endl;
}

Context* CPU::getContext() {
	auto rgs = new uint64_t[rgsize+3];
	rgs[0] = sp;
	rgs[1] = pc;
	rgs[2] = st;
	for (int i = 0; i < rgsize; ++i) {
		rgs[i+3] = rg[i];
	}
	return new Context(rgsize, rgs);
}

void CPU::loadContext(Context* cx) {
	rg = cx->getRegisters();
	sp = cx->getSP();
	pc = cx->getPC();
	st = cx->getST();
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
            return new RoundRobin(2);
        default:
            std::cout << "CPU " << id << ": Invalid scheduler" << std::endl;
            return nullptr;
    }
}

/*void CPU::printReport() {
    std::cout << "\nTurnaround times:" << std::endl;

    double totalTurnaroundTime = 0;
    for (Process *process: terminatedProcesses) {
        totalTurnaroundTime += (double) process->getTurnaroundTime();
        std::cout << "Process " << process->getPid() << ": "
                  << process->getTurnaroundTime() << std::endl;
    }
    std::cout << "Average: " << totalTurnaroundTime / (double) terminatedProcesses.size()
              << std::endl << std::endl;

    std::cout << "Avarege waiting times: ";
    double totalWaitingTime = 0;
    for (Process *process: terminatedProcesses) {
        totalWaitingTime += (double) process->getWaitingTime();
    }
    std::cout << totalWaitingTime / (double) terminatedProcesses.size() << std::endl << std::endl;

    std::cout << "Context switches: " << contextSwitches << std::endl << std::endl;

    *//*std::cout << "Execution time diagram:" << std::endl;
    for (auto &states: executionTimeDiagram) {
        for (auto &state: states) {
            std::cout << state.first << ": " << static_cast<Process::State>(state.second) << " ";
        }
        std::cout << std::endl;
    }*//*
}*/

void CPU::updateRunningProcess(Process *pProcess) {
    if (runningProcess != nullptr && runningProcess != pProcess
        && !runningProcess->isFinished()) {
        runningProcess->setState(Process::State::BLOCKED);
	runningProcess->saveContext(getContext());
        waitingProcesses.push_back(runningProcess);
    }
    runningProcess = pProcess;
}

void CPU::updateWaitingProcesses() {
    if (runningProcess->isFinished()) {
        runningProcess->setState(Process::State::TERMINATED);
        terminatedProcesses.push_back(runningProcess);
        runningProcess = nullptr;
    }
}

void CPU::processesToReadyInTime() {
    std::vector<Process *> aux;
    for (auto &process: notStartedProcesses) {
        if (process->getCreationTime() == runningTime) {
            process->setState(Process::State::READY);
            waitingProcesses.push_back(process);
        } else {
            aux.push_back(process);
        }
    }
    notStartedProcesses = aux;
}

bool CPU::isFinished() {
    return waitingProcesses.empty()
    && notStartedProcesses.empty()
    && runningProcess == nullptr;
}

void CPU::unblockProcesses() {
    for (auto &process: waitingProcesses) {
        if (process->getState() == Process::State::BLOCKED) {
            process->setState(Process::State::READY);
        }
    }
}

void CPU::addWaitingTimeToWaitingProcesses(int time) {
    for (auto &process: waitingProcesses) {
        process->addWaitingTime(time);
    }
}
