#include <iostream>
#include <string>
#include "Lista.h"

// Nome: Igor Bicalho Nogueira de Paula
// Objetivo: Implementar uma lista ordenada e sem duplicatas
// Entrada: Palavras fornecidas pelo usuário
// Resultado: Lista de palavras ordenadas e sem duplicatas

using namespace std;

int main() {
    string palavra;
    int escolha;

    // Inicializa a lista
    Lista_Construtor();

    do {
        cout << "---------- LISTA C++ -----------" << endl;
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - ADICIONAR NA LISTA" << endl;
        cout << "2 - REMOVER DA LISTA" << endl;
        cout << "3 - EXIBIR LISTA" << endl;
        cout << "10 - SAIR" << endl;
        cin >> escolha;

        switch (escolha) {
            case 1: // Adicionar palavra
                cout << "Digite uma palavra: ";
                cin >> palavra;
                if (Lista_Inserir_Ordenado(palavra)) {
                    cout << "Palavra '" << palavra << "' adicionada com sucesso!" << endl;
                } else {
                    cout << "Palavra '" << palavra << "' já existe na lista!" << endl;
                }
                break;

            case 2: // Remover palavra
                cout << "Digite a palavra a ser removida: ";
                cin >> palavra;
                if (Lista_Remover(palavra)) {
                    cout << "Palavra '" << palavra << "' removida com sucesso!" << endl;
                } else {
                    cout << "Palavra '" << palavra << "' não encontrada na lista!" << endl;
                }
                break;

            case 3: // Exibir lista
                cout << "Lista de palavras:" << endl;
                Lista_Exibir(); // Esta função deve exibir todos os elementos da lista
                break;

            case 10: // Sair
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    } while (escolha != 10);

    Lista_Destrutor(); // Limpa a lista antes de sair
    return 0;
}
