
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
    explicit File(const string& path) {
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
            auto *p = new ProcessParams(a, b, c);
            processes.push_back(p);
        }

        cout << "Quantidade de processos lidos do arquivo: " << processes.size() << endl;
    }

    void print_processes_params() {
        auto iter = processes.begin();
        for (; iter < processes.end(); iter++) {
            ProcessParams *p = *iter;
            cout << *p;
        }
    }

    vector<ProcessParams *> getProcessParams() {
        return processes;
    }

    ~File() {
        for (auto p : processes) {
            delete p;
        }
    }

private:
    ifstream myfile;
    vector<ProcessParams *> processes;
};

int main () {
    int option;

    File f("src/entrada1.txt");
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
            cout << "Saindo" << endl;
            break;
        } else if (option < 1 || option > 6) {
            cout << "\033[31m" << "Opção inválida!" << "\033[0m" << endl;
            cout << endl;
        }

        CPU cpu(option, f.getProcessParams());
        cpu.run();
        //cpu.printReport();
    } while (true);

    return 0;
}
