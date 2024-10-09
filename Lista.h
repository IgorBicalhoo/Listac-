
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <string>

typedef std::string TipoDado; // Define o tipo de dado que será armazenado na Lista

struct TipoCelula {
    TipoDado Item;
    TipoCelula *Prox;
};

// Funções da lista
void Lista_Construtor();
void Lista_Destrutor();
bool Lista_Vazia();
int Lista_Tamanho();
bool Lista_Inserir_Ordenado(TipoDado Elemento);
bool Lista_Remover(TipoDado Elemento);
void Lista_Exibir();

#endif // LISTA_H_INCLUDED
