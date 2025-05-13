#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>

struct pacote {
    char name[51];
    int code;
    float weight;
};

void swap(Pacote*, Pacote*);
int partition(Pacote*, int, int);
void quick(Pacote*, int, int);

// Manter como especificado
Pacote *alocaVetor(int n) {
    // seu codigo aqui
    Pacote *pessoas = malloc(n * sizeof(Pacote));
    return pessoas;
}

// Manter como especificado
void desalocaVetor(Pacote** pacotes) {
    // seu codigo aqui
    free(*pacotes);
    (*pacotes) = NULL;
}

// Manter como especificado
void lePacotes(Pacote* pacotes, int n) {
    // para cada pacote...
    // seu codigo aqui
    for(int i = 0; i < n; i++){
        scanf("%s", pacotes[i].name);
        scanf("%d%f", &pacotes[i].code, &pacotes[i].weight);

    }
}

// Manter como especificado
void ordenarPacotes(Pacote* pacotes, int n) {
    // seu codigo aqui
    quick(pacotes, 0, n-1);
}

// Manter como especificado
void imprimirPacotes(Pacote* pacotes, int n) {
    // seu codigo aqui
    for(int i = 0; i < n; i++){
        printf("%s ", pacotes[i].name);
        printf("%d %.1f\n", pacotes[i].code, pacotes[i].weight);
    }
}

// Manter como especificado
void swap(Pacote* a, Pacote* b) {
    // seu codigo aqui
    Pacote aux = *b;
    *b = *a;
    *a = aux;
}

// Manter como especificado
int partition(Pacote* pacotes, int p, int r) {
    // seu codigo aqui
    Pacote x = pacotes[r];//pivo
    int i, j;
    i = p - 1;
    for(j = p; j < r; j++){
        if(pacotes[j].weight < x.weight){
            swap(&pacotes[i+1], &pacotes[j]);
            i++;
        }
        if(pacotes[j].weight == x.weight){
            if(pacotes[j].code < x.code ){
                swap(&pacotes[i+1], &pacotes[j]);
                i++;
            }
        }
    }
    swap(&pacotes[i+1], &pacotes[r]);
    return i+1;

}
// Manter como especificado
void quick(Pacote* pacotes, int p, int r) {
    // seu codigo aqui
    if(r>p){
        int q = partition(pacotes, p, r);
        quick(pacotes, p, q-1);
        quick(pacotes, q+1, r);
    }
}
