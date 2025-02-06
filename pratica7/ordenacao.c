#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
int* alocaVetor(int n){
    int *v = malloc(n*sizeof(int));
    return v;
}

// Manter como especificado
int* desalocaVetor(int* v){
    free(v);
    return NULL;
}

// Manter como especificado
void ordenacao(int* v, int n, int* movimentos){
    int cont = 0;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j< n - i - 1; j++){
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                (*movimentos)++;
                cont++;
            }
            
        }
    }
}
