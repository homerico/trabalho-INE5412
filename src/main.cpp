
#include <iostream>

using namespace std;

int main () {
    char option;
    int trash;

    do {
        cout << "Escolha o tipo de escalonamento que deseja executar:" << endl;
        cout << "1 - FCFS (First Come, First Served)" << endl;
        cout << "2 - SJF (Shortest Job First)" << endl;
        cout << "3 - Por prioridade, sem preempção" << endl;
        cout << "4 - Por prioridade, com preempção por prioridade" << endl;
        cout << "5 - Round-Robin com quantum = 2s, sem prioridade" << endl;
        cout << "6 - Sair" << endl;
        cin >> option;

        switch (option) {
            case '1':
                // TODO: implementar FCFS
                cout << "Digite qualquer coisa para voltar ao menu principal" << endl;
                cin >> trash;
                break;
            case '2':
                // TODO: implementar SJF
                cout << "Digite qualquer coisa para voltar ao menu principal" << endl;
                cin >> trash;
                break;
            case '3':
                // TODO: implementar por prioridade, sem preempção
                cout << "Digite qualquer coisa para voltar ao menu principal" << endl;
                cin >> trash;
                break;
            case '4':
                // TODO: implementar por prioridade, com preempção por prioridade
                cout << "Digite qualquer coisa para voltar ao menu principal" << endl;
                cin >> trash;
                break;
            case '5':
                // TODO: implementar Round-Robin com quantum = 2s, sem prioridade
                cout << "Digite qualquer coisa para voltar ao menu principal" << endl;
                cin >> trash;
                break;
            case '6':
                cout << "Saindo" << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (option != '6');

    return 0;
};
