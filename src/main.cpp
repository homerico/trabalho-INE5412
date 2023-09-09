
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "schedulers/fcfs.h"
#include "schedulers/sjf.h"
#include "schedulers/priority.h"
#include "schedulers/priority_with_preemption.h"
#include "schedulers/round_robin.h"

using namespace std;

class ProcessParams
{
public:
    ProcessParams(int c, int d, int p) {
        creation_time = c;
        duration = d;
        priority = p;
    }

    friend ostream &operator<<(ostream& os, const ProcessParams& p) {
        os << "Creation time = " << p.creation_time << " duration = " << p.duration << " priority = " << p.priority << endl;
        return os;
    }

private:
    int creation_time;
    int duration; //seconds
    int priority;
};

class File
{

public:
    File(const string path) {
        cout << "Abrindo arquivo " << path << endl;
        cout << endl;
        myfile.open(path.c_str());
        if (!myfile.is_open()) {
            cout << "Erro ao abrir o arquivo!\n";
        }
    }

    void read_file() {

        int a, b, c;

        if (!myfile.is_open()) {
            cout << "Arquivo não está aberto!" << endl;
        }

        while (myfile >> a >> b >> c) {
            ProcessParams *p = new ProcessParams(a, b, c);
            processes.push_back(p);
        }

        cout << "Quantidade de processos lidos do arquivo: " << processes.size() << endl;
    }

    void print_processes_params() {
        vector<ProcessParams *>::iterator iter = processes.begin();

        for(iter; iter < processes.end(); iter++) {
            ProcessParams *p = *iter;
            cout << *p;
        }
    }

    vector<ProcessParams *> get_processes_params() {
        return processes;
    }

    ~File() {
        for(int i = 0; i < processes.size() ; i++) {
            ProcessParams *p = processes[i];
            delete p;
        }
    }

private:
    ifstream myfile;
    vector<ProcessParams *> processes;
};

int main () {
    int option;

    File f("src/entrada.txt");
    f.read_file();
    f.print_processes_params();
    cout << endl;

    do {
        cout << "Escolha o tipo de escalonamento que deseja executar:" << endl;
        cout << "1 - FCFS (First Come, First Served)" << endl;
        cout << "2 - SJF (Shortest Job First)" << endl;
        cout << "3 - Por prioridade, sem preempção" << endl;
        cout << "4 - Por prioridade, com preempção por prioridade" << endl;
        cout << "5 - Round-Robin com quantum = 2s, sem prioridade" << endl;
        cout << "6 - Sair" << endl;
        cout << ">>> ";
        cin >> option;
        cout << endl;

        // Caso o usuário digite uma letra ou frase
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256,'\n');
            option = 0;
        }

        switch (option) {
            case 1:
                // TODO: implementar FCFS
                break;
            case 2:
                // TODO: implementar SJF
                break;
            case 3:
                // TODO: implementar por prioridade, sem preempção
                break;
            case 4:
                // TODO: implementar por prioridade, com preempção por prioridade
                break;
            case 5:
                // TODO: implementar Round-Robin com quantum = 2s, sem prioridade
                break;
            case 6:
                cout << "Saindo" << endl;
                break;
            default:
                cout << "\033[31m" << "Opção inválida!" << "\033[0m" << std::endl;
                cout << endl;
                break;
        }
    } while (option != 6);

    return 0;
};
