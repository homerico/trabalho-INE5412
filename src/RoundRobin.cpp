
#include <algorithm>
#include "RoundRobin.h"

Process *RoundRobin::schedule(std::vector<Process *> &waitingProcesses, Process *runningProcess) {
    // se o processo que está executando não terminou e o contador não chegou no quantum, então ele continua executando
    if (runningProcess != nullptr && counter != quantum) {
        counter++;
        return runningProcess;
    }

    // se o processo que está executando não terminou e o contador chegou no quantum, então ele é passado para o final da fila,
    // incrementa a prioridade dinâmica dele
    if (runningProcess != nullptr && counter == quantum) {
        runningProcess->incrementDynamicPriority();
    }

    counter = 0;

    // reordena os processos que estão esperando para serem executados de acordo com a prioridade dinâmica deles
    reorderWaitingProcessesByDynamicPriority(waitingProcesses);

    // e o processo que está na primeira posição da fila é passado para a execução
    Process *process;
    process = waitingProcesses.at(0);
    waitingProcesses.erase(waitingProcesses.begin());
    // por conta de que processo vai ser passado diretamente para a primeira execução, então o contador é incrementado
    counter++;
    return process;
}

void RoundRobin::reorderWaitingProcessesByDynamicPriority(std::vector<Process *> &vector) {
    std::sort(vector.begin(), vector.end(), [](Process *a, Process *b) {
        return a->getDynamicPriority() < b->getDynamicPriority();
    });
}
