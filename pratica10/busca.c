#include "busca.h"

#include <stdio.h>
#include <stdlib.h>

// Crie as funcoes que julgar necessario

int* aloca(int n) {
    // preencha aqui
    int *v = malloc(n * sizeof(int));
    if(v == NULL)
        return NULL;
    return v;
}

void desaloca(int**v ) {
    // preencha aqui
    free(*v);
    (*v) = NULL;
}

void le(int* v, int n) {
    // preencha aqui
    for(int i = 0; i< n; i++){
        scanf("%d", &v[i]);
    }
}

int buscaSequencial(int* v, int n, int num) {
    // preencha aqui
    int i;
    for(i= 0; i< n; i++){
        if(v[i] == num)
            return i + 1;
    }
    return i;
}

int buscaBinaria(int* v, int n, int num) {
    // preencha aqui
    //shellsort
    int h, i, j, aux;
    for (h=1;h<n;h=3*h + 1);
    do {
        h = (h - 1)/3;
        for (i=h;i<n;i++) {
            aux = v[i];
            j = i-h;
            while (j >= 0 && v[j] > aux) {
                v[j + h] = v[j];
                j -= h;
            }
            v[j+h] = aux;
        }
        
    } while (h > 1);
    //agora v tá ordenado

    int esq = 0, dir = n-1, k = 1;
    while(esq <= dir){
        int meio = (esq + dir)/2;
        if(v[meio] < num){
            esq = meio + 1;
            k++;
        }else if(v[meio] > num){
            dir = meio - 1;
            k++;
        }else if(v[meio] == num){
            return k;
        }
    }
    return k-1;
}
