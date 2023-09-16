
#ifndef TRABALHO_INE5412_CPU_H
#define TRABALHO_INE5412_CPU_H

#include <iostream>

#include <vector>
#include <map>
#include "Logger.h"
#include "Context.h"
#include "ProcessParams.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "PriorityWithPreemption.h"
#include "RoundRobin.h"
using std::vector;

class CPU {
public:

    CPU(int alg, const std::vector<ProcessParams *> &processParams) {
        type = Scheduler::Type(alg);
        scheduler = getScheduler();
        runningTime = 0;
        contextSwitches = 0;
        runningProcess = nullptr;

	// Inicializa registradores vazios
	rg = new uint64_t[rgsize];
	for (int i = 0; i < rgsize; ++i)
		rg[i] = 0;
	sp = 0;
	pc = 0;
	st = 0;

	Context* cx = getContext(); // Contexto vazio usado para inicializar processos
	
        for (unsigned i = 0; i < processParams.size(); i++) {
            ProcessParams pParams = *processParams[i];
	    auto p = new Process(pParams, i, cx);
	    
	    processes.push_back(p);
            
	    notStartedProcesses.push_back(p);
        }

	logger = new Logger(std::cout.rdbuf(), processParams.size());
    }

    ~CPU() {
        delete scheduler;
        for (auto p : terminatedProcesses) {
            delete p;
        }
    };

    void 	run();
    void 	printReport();

private:
    Logger* logger;

    // Constantes
    const char*	id = "INE5412";
    const int 	rgsize = 6;

    // Registradores
    uint64_t *rg;
    uint64_t sp;
    uint64_t pc;
    uint64_t st;

    // Instancias
    int 		contextSwitches;
    int 		runningTime;
    Process*		runningProcess;
    Scheduler*		scheduler;
    Scheduler::Type 	type;
    vector<Process*> 	processes;
    vector<Process*> 	notStartedProcesses;
    vector<Process*> 	waitingProcesses;
    vector<Process*> 	terminatedProcesses;

    // Metodos
    bool 	isFinished();
    Scheduler* 	getScheduler();
    void 	processesToReadyInTime();
    void 	unblockProcesses();
    void 	updateWaitingProcesses();
    void 	addWaitingTimeToWaitingProcesses(int time = 1);
    void 	updateRunningProcess(Process* pProcess);
    void 	storeStates();
    Context*	getContext();
    void	loadContext(Context* cx);


};

#endif //TRABALHO_INE5412_CPU_H
