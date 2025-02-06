#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 10

struct lista {
    // Preencher aqui
    int *numeros;
    int qtd;
    int primeiro, ultimo;
};

Lista* cria () {
    // Preencher aqui
    Lista *lst = malloc(sizeof(Lista));
    lst->numeros = malloc(MAX_TAM * sizeof(int));
    lst->qtd = 0;
    lst->primeiro = 0;
    lst->ultimo = 0;
    return lst;
}

Lista* libera (Lista *lista) {
    // Preencher aqui
    free(lista->numeros);
    free(lista);
    return NULL;
}

void imprime (Lista *lista) {
    // Preencher aqui
    int i = lista->primeiro;
    int cont = 0;

    while (cont < lista->qtd) {//enquanto o contador for menor que a quantidade
        printf("%d ", lista->numeros[i]);
        i++;
        if (i == MAX_TAM) // Volta ao início se atingir o final do array
            i = 0;
        cont++;
    }
    printf("\n");
}

bool pertence (Lista *lista, int chave) {
    // Preencher aqui
    int i = lista->primeiro;//primeira posicao
    for (int k = 0; k < lista->qtd; k++) {//percorrer o tanto de espaços preenchidos
        if (lista->numeros[i] == chave) 
            return true;
        i++;
        if (i == MAX_TAM) 
            i = 0;
    }
    return false;
}

bool insereOrdenado(Lista *lista, int chave) {
    if (lista->qtd == MAX_TAM)
        return false; // Lista cheia


    int i = lista->primeiro;
    int aux = -1;
    for (int k = 0; k < lista->qtd; k++) {
        if (lista->numeros[i] > chave) {//se for maior que a cghave
            aux = i;//posicao onde devo inserir
            break;
        }
        i++;
        if (i == MAX_TAM)//coisa ciclante
            i = 0;
    }
    if (aux == -1) //se ainda for -1 a chave é maior que todas
        aux = lista->ultimo;

    int j = lista->ultimo;
    while (j != aux) {
        int prev = j - 1;
        if (prev < 0) 
            prev = MAX_TAM - 1;

        lista->numeros[j] = lista->numeros[prev];
        j = prev;
    }
    lista->numeros[aux] = chave;
    lista->ultimo++;
    if (lista->ultimo == MAX_TAM)
        lista->ultimo = 0;
    lista->qtd++;

    return true;
}

bool retiraEspecifico(Lista *lista, int chave) {
    // Verifica se a lista está vazia
    if (lista->qtd == 0)
        return false;

    int i = lista->primeiro;
    int encontrou = 0;

    do {
        if (lista->numeros[i] == chave) {
            encontrou = 1;
            break;
        }
        i++;
        if (i == MAX_TAM) 
            i = 0;
    } while (i != lista->ultimo);
     //i é a posição do elemento que será retidaos
    // Se não encontrou o elemento
    if (!encontrou)
        return false;

    // se ta no inicio
    if (i == lista->primeiro) {
        lista->primeiro++; 
        if (lista->primeiro == MAX_TAM) 
            lista->primeiro = 0;
    }
    // se ta no fim
    else if (i == lista->ultimo - 1 || (lista->ultimo == 0 && i == MAX_TAM - 1)) {
        lista->ultimo--; // Reduz o fim
        if (lista->ultimo < 0) // Se for menor que zero, volta para o final do array
            lista->ultimo = MAX_TAM - 1;
    }
    // se ta meio
    else {
        int j = i;
        while (j != lista->ultimo - 1) {
            int proximo = j + 1;
            if (proximo == MAX_TAM) // Volta ao início se atingir o final do array
                proximo = 0;

            lista->numeros[j] = lista->numeros[proximo];
            j = proximo;
        }

        lista->ultimo--; // Ajusta o fim após deslocar os elementos
        if (lista->ultimo< 0) // Se for menor que zero, volta para o final do array
            lista->ultimo = MAX_TAM - 1;
    }

    lista->qtd--; // Decrementa a quantidade de elementos
    return true;
}

bool retiraInicio (Lista *lista) {
    // Preencher aqui
    if (lista->qtd == 0)
        return false;

    lista->primeiro++;
    if (lista->primeiro == MAX_TAM) 
        lista->primeiro = 0;

    lista->qtd--; 
    return true;
}

int posicaoInicialLista(Lista *lista) {
    // Preencher aqui
    return(lista->primeiro);
}