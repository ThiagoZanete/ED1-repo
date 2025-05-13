#include <stdio.h>

#include "hash.h"


int main() {
    Hash hash;
    Chave chave;
    int n;

    // PREENCHER COM OUTRAS VARIÁVEIS
    int m, p, pos;

    // Ler a quantidade de casos
    // PREENCHER AQUI
    scanf("%d", &n);//casos teste
    //printf("OK\n");

    while (n-- > 0) {
        //Hash hash;
        // Lendo tamanho da tabela e quantidade de pesos
        // PREENCHER AQUI
        scanf("%d%d", &m, &p);
        //printf("OK");
        // Iniciar Hash
        // PREENCHER AQUI
        inicia(&hash, m, p);

        // Lendo pesos
        // PREENCHER AQUI
        for(int i = 0; i < p; i++){
            scanf("%d", &hash.pesos[i]);
        }

        // Lendo quantidade de chaves
        // PREENCHER AQUI
        int s;
        scanf("%d", &s);

        // Lendo chaves
        // PREENCHER AQUI
        for(int i = 0; i < s; i++){
            //Chave chave;
            scanf("%s", chave);
            pos = insere(&hash, chave);
        }

        // Imprimir resposta
        // PREENCHER AQUI
        printf("%d\n", pos);
       // printf("1, 12 3\n");

        // Liberar Hash
        // PREENCHER AQUI
        libera(&hash);
    }

    return 0;
}