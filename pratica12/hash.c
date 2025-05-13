#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void inicia (Hash *hash, int m, int p) {//m tam hash p tam pesos
    // PREENCHER AQUI
    //printf("OK\n");
    //hash = malloc(sizeof(Hash));
    hash->pesos = malloc(p * sizeof(int));
    hash->chaves = malloc(m * sizeof(Chave));
    hash->m = m;
    hash->p = p;
    for (int i = 0; i < m; i++) {
        hash->chaves[i][0] = '\0';
    }
}

// Manter como especificado
void libera(Hash *hash) {
    // PREENCHER AQUI
    free(hash->chaves);
    free(hash->pesos);
    //free(hash);
}

int H(Hash* hash, Chave chave) {
    // PREENCHER AQUI
    unsigned int soma = 0;
    for (int i=0;i<strlen(chave);i++)
        soma += chave[i] * hash->pesos[i % hash->p];
    return soma % hash->m;
}

// Manter como especificado
int insere (Hash *hash, Chave chave) {
    // PREENCHER AQUI
    //printf("OK\n");
    int pos = H(hash, chave);
    int j = 0;

    while(strcmp(hash->chaves[(pos+j) %hash->m], "\0") != 0 && j < hash->m && strcmp(hash->chaves[(pos + j) % hash->m], chave) != 0){
        j++;
    }
    if (!strcmp(hash->chaves[(pos + j) % hash->m], chave))
        return -1;
    if(j < hash->m){
        strcpy(hash->chaves[(pos + j) % hash->m], chave);
        return (pos + j) % hash->m;
    }
    return -1;
}

