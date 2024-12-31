#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz {
    double **values;
    int n;
};

Matriz* alocar(int n) {
    // Preencher aqui
    Matriz *m;
    m = malloc(sizeof(Matriz));
    m -> values = malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++){
        m -> values[i] = malloc(n * sizeof(double));
    }
    m->n = n;
    return m;
}

Matriz* desalocar(Matriz *matriz) {
    // Preencher aqui
    for(int i = 0; i < matriz->n; i++){
      free(matriz->values[i]);
    }
    free(matriz->values);
    free(matriz);
    return NULL;
}

void le(Matriz *matriz) {
    // Preencher aqui
    for(int i = 0; i < matriz->n; i++){
        for(int j = 0; j < matriz->n; j++){
            scanf("%lf", &matriz->values[i][j]);
        }
    }
}

double somaParte(Matriz *matriz, int *cont) {
    // Preencher aqui
    *cont = 0;
    double soma= 0;
    int N = matriz -> n;
    int N2= N;

    if(N % 2 != 0){
        N = N /2 +1;
    }else{
        N = N/2;
    }

    int inicial = 1;
    for(int i = N2-1; i >= N; i--){
        for(int j = inicial; j <N2 - inicial; j++){
                soma += matriz->values[i][j];
                (*cont)++;
        }
        inicial++;
    }
    return soma;
}
