#include <iostream>
#include <string>
#include <cstdlib>
#include "Lista.h"

using namespace std;

TipoCelula *Frente, *Tras;
int Contador;

void Lista_Construtor() {
    Frente = Tras = NULL;
    Contador = 0;
}

void Lista_Destrutor() {
    TipoCelula *Temp;
    while (Frente != NULL) {
        Temp = Frente;
        Frente = Frente->Prox;
        delete Temp;
    }
    Tras = NULL;
    Contador = 0;
}

bool Lista_Vazia() {
    return Frente == NULL;
}

bool Lista_Inserir_Ordenado(string palavra) {
    TipoCelula *Novo = new TipoCelula;
    Novo->Item = palavra;
    Novo->Prox = NULL;

    if (Lista_Vazia() || Frente->Item > palavra) { // Se a lista est� vazia ou a nova palavra deve ser a primeira
        Novo->Prox = Frente;
        Frente = Novo;
        if (Tras == NULL) Tras = Novo; // Se a lista estava vazia, tamb�m atualiza Tras
        Contador++;
        return true;
    }

    TipoCelula *Temp = Frente;
    TipoCelula *Anterior = NULL;

    while (Temp != NULL && Temp->Item < palavra) {
        Anterior = Temp;
        Temp = Temp->Prox;
    }

    if (Temp != NULL && Temp->Item == palavra) { // Palavra j� existe
        delete Novo; // Libera a mem�ria
        return false;
    }

    Novo->Prox = Temp;
    Anterior->Prox = Novo;

    if (Temp == NULL) Tras = Novo; // Atualiza Tras se necess�rio

    Contador++;
    return true;
}

bool Lista_Remover(string palavra) {
    if (Lista_Vazia()) return false;

    TipoCelula *Temp = Frente;
    TipoCelula *Anterior = NULL;

    while (Temp != NULL && Temp->Item != palavra) {
        Anterior = Temp;
        Temp = Temp->Prox;
    }

    if (Temp == NULL) return false; // Palavra n�o encontrada

    if (Anterior == NULL) {
        Frente = Frente->Prox; // Remove do in�cio
    } else {
        Anterior->Prox = Temp->Prox; // Remove do meio ou fim
    }

    if (Temp == Tras) Tras = Anterior; // Atualiza Tras se necess�rio

    delete Temp; // Libera a mem�ria
    Contador--;
    return true;
}

void Lista_Exibir() {
    TipoCelula *Temp = Frente;
    while (Temp != NULL) {
        cout << Temp->Item << endl;
        Temp = Temp->Prox;
    }
}
