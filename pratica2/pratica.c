#include <stdio.h>

#include "matriz.h"

int main()
{
    char opcao;
    int n, cont;
    double soma;

    // Leitura do Char
    scanf("%c", &opcao);
    
    // Leitura do tamanho da matriz
    scanf("%d", &n);
    
    // Declarar e alocar matriz
    Matriz *M = alocar(n);
    
    // Leitura da Matriz e Cálculos
    le(M);
    
    // Soma parte dos valores da matriz e conta a quantidade
    //double somaParte(Matriz *matriz, int *cont)
    soma = somaParte(M, &cont);
    
    // Impressão dos resultados
    if(opcao == 'S'){
        printf("%.1lf", soma);
    }else{
        printf("%.1lf", soma/cont);
    }
    
    // Liberar memória
    Matriz* desalocar(Matriz *matriz);
    M = desalocar(M);

    
    return 0;
}
