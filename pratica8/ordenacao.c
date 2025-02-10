#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
Pessoa *alocaVetor(int n) {
    Pessoa *pessoas = (Pessoa*) malloc(n * sizeof(Pessoa));
    if(pessoas == NULL)
        printf("Não alocou\n");
    return pessoas;
    
}

// Manter como especificado
void desalocaVetor(Pessoa **vetor) {
    free(*vetor);
    *vetor = NULL;
}

// implemente sua funcao do mergesort, que deve invocar a funcao merge
void MergeSort(Pessoa *vetor, int esquerda, int direita)
{
    if(esquerda < direita){
        int meio = (esquerda + direita) / 2;
        MergeSort(vetor, esquerda, meio);
        MergeSort(vetor, meio+1, direita);
        merge(vetor, esquerda, meio, direita);
    }
   
}

// implemente sua funcao do mergesort, que deve invocar a funcao merge
void merge(Pessoa *vetor, int esquerda, int meio, int direita)
{
    int tamL = meio - esquerda + 1;
    int tamR = direita - meio;
    Pessoa *vL = (Pessoa*) malloc(tamL * sizeof(Pessoa));
    Pessoa *vR = (Pessoa*) malloc(tamR * sizeof(Pessoa));
    int i, j, k;
    for(i = 0; i < tamL; i++)
        vL[i] = vetor[esquerda + i];
    for(j = 0; j < tamR; j++)
        vR[j] = vetor[meio + 1 + j];
    
    i = 0, j= 0, k = esquerda;
    for(k = esquerda; k <= direita; k++){
        if(i == tamL)//se todos os elementos do vetor da esquerda foram usados
            vetor[k] = vR[j++];
        else if(j == tamR)//se todos os elementos do vetor da direita foram usados
            vetor[k] = vL[i++];
        else if(strcmp(vL[i].nome, vR[j].nome) == 0) //são iguais
            if(vL[i].idade <= vR[j].idade)//se o da esquerda for menor que a direita
                vetor[k] = vL[i++];
            else//se o da esquerda for maior que o da direita
                vetor[k] = vR[j++];
        else if(strcmp(vL[i].nome, vR[j].nome) < 0)//a esquerdavem antes da direita
            vetor[k] = vL[i++];
        else 
            vetor[k] = vR[j++];//a direita vem antes da esquerda
    }
    free(vL);
    free(vR);
}