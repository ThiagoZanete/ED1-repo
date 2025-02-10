#include "ordenacao.h"
#include <stdio.h>

int main()
{
    int n; 
    int i = 0;

    //leia o numero de casos de teste
    scanf("%d", &n);

    //enquanto houver casos de teste
    while (i < n) {
        int p;
        int j;
        Pessoa *pessoas;

        //leia o numero de pessoas
        scanf("%d", &p);

        //aloque o vetor
        pessoas = alocaVetor(p);

        //para cada pessoa...
        for (j = 0; j < p; j++) {
            // preencher o vetor de pessoas...
            //fgets()
            scanf(" %[^0-9] %d",  pessoas[j].nome, &pessoas[j].idade);
        }
 
        
        // use o mergesort para ordenar o vetor
        MergeSort(pessoas, 0, p-1);

        // imprima o resultado
        printf("\n\nTeste %d:\n", i+1);
        for(int k = 0; k < p; k++){
            printf("%s %d\n", pessoas[k].nome, pessoas[k].idade);
        }

        // desaloque o vetor
        desalocaVetor(&pessoas);
        
        i++;
    }

    return 0;
}
