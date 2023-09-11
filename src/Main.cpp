
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ProcessParams.h"
#include "CPU.h"

using namespace std;

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
        cout << "Fechando arquivo" << endl;
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

        // Caso o usuário digite uma string
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256,'\n');
            option = 0;
        }

        if (option == 6) {
            cout << "Saindo..." << endl;
            break;
        } else if (option < 1 || option > 6) {
            cout << "Opção inválida!" << endl;
            cout << endl;
        }

        cout << "teta" << endl;
        CPU cpu(option, f.get_processes_params());
        cout << "teta2" << endl;
        cpu.run();
    } while (true);

    return 0;
};
