#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
    char nome[21];
    int idade;
    ESCALADO escalado;
};

struct time {
    char nomeLider[21], nomeConfeiteiro[21], nomeEntregador[21], nomeEmbrulhador[21];
    int idadeLider, idadeConfeiteiro, idadeEntregador, idadeEmbrulhador;
};

void lerQuantidade(int *qtd){
    scanf("%d\n", qtd);
}

// Manter como especificado
Duende *alocaDuendes(int qtd){
    // preencha aqui
    Duende *duendes = malloc(qtd*sizeof(Duende));
    return duendes;
}

// Manter como especificado
Time *alocaTimes(int qtd){
    // preencha aqui
    Time *times = malloc(qtd*sizeof(Time));
    return times;
}

// Manter como especificado
Duende* desalocaDuendes(Duende *duendes){
    // preencha aqui
    free(duendes);
    return NULL;
}

// Manter como especificado
Time* desalocaTimes(Time *times){
    // preencha aqui
    free(times);
    return NULL;
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtd){
    // preencha aqui
    for(int i = 0; i< qtd; i++){
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
}

// Manter como especificado
//complexidade de 4*O(qtd^2) = O(qtd^2) ou O(n^2)
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;
    
    //complexidade de O(qtd)*O(qtdTimes) mas como QtdTimes = qtd/4 então O(qtd * qtd/4) = O((qtd^2)/4 = O(qtd^2)
    // Escalando os lideres
    for(i = 0; i < qtdTime; i++){
        //complexidade O(qtd)
        index = proximoMaisVelho(duendes, qtdDuendes);//index recebe a posição do mais veio
        times[i].idadeLider = duendes[index].idade;
        strcpy(times[i].nomeLider, duendes[index].nome);
        duendes[index].escalado = SIM; 
    }

    // Escalando os confeiteiros
    //O(qtd^2)
    for(int i = 0; i < qtdTime; i++){
        index = proximoMaisVelho(duendes, qtdDuendes);//index recebe a posição do mais veio
        times[i].idadeConfeiteiro = duendes[index].idade;
        strcpy(times[i].nomeConfeiteiro, duendes[index].nome);
        duendes[index].escalado = SIM; 
    }
    
    // Escalando os entregador
    //O(qtd^2)
    for(int i = 0; i < qtdTime; i++){
        index = proximoMaisVelho(duendes, qtdDuendes);//index recebe a posição do mais veio
        times[i].idadeEntregador = duendes[index].idade;
        strcpy(times[i].nomeEntregador, duendes[index].nome);
        duendes[index].escalado = SIM; 
    }
    
    // Escalando os embrulhadores
    //O(qtd^2)
    for(int i = 0; i < qtdTime; i++){
        index = proximoMaisVelho(duendes, qtdDuendes);//index recebe a posição do mais veio
        times[i].idadeEmbrulhador = duendes[index].idade;
        strcpy(times[i].nomeEmbrulhador, duendes[index].nome);
        duendes[index].escalado = SIM; 
    }
}

//complexidade = O(n), ou O(qtd)
int proximoMaisVelho(Duende *D, int qtd){
    // preencha aqui
    int pos, maior = 0;
    for(int j = 0; j < qtd; j++){
        if(D[j].idade > maior && D[j].escalado == NAO){
            maior = D[j].idade;
            pos = j;
        }
    }
    return pos;//posição da maior idade
}

// Manter como especificado
void printTimes(Time *times, int qtd){
   
    for (int i=0; i<qtd; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}