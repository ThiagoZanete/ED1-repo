#include <stdio.h>
#include <stdlib.h>

#include "busca.h"

int main() {
    // criar variaveis
    int quantCasos, *v, numProc, n;
    // ler quantidade de casos
    scanf("%d", &quantCasos);
    // enquanto houver casos
    while(quantCasos > 0){
    // ler o numero a ser buscado e a quantidade de numeros
    scanf("%d%d", &numProc, &n);
    // alocar o vetor e realizar as buscas
    v = aloca(n);
    le(v, n);
    int compSeq= 0, compBi= 0; 
    compSeq = buscaSequencial(v, n, numProc);
    compBi = buscaBinaria(v, n, numProc);
    printf("%d %d\n", compSeq, compBi);
    desaloca(&v);
    quantCasos--;
    }
    return 0;
}