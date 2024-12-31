#include "carro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct funcionario {
    char nome[20];//nome do funcionário
    int matric;//matrícula do funcionário
};


struct carro {
    int chassi;
    char model[20];
    int lugar;
    int anofab;   
    Funcionario* func;
};

Funcionario* FuncionarioAloca() {
    /* seu codigo aqui */
    Funcionario *func = malloc(sizeof(Funcionario));
    return func;
}

void FuncionarioDesaloca(Funcionario** func) {
    /* seu codigo aqui */
    free(*func);
}

Carro* CarroAloca(int n) {
    /* seu codigo aqui */
    Carro *car;
    car = malloc(n * sizeof(Carro));
    for(int i = 0; i < n; i++){
        car[i].func = FuncionarioAloca();
    }
    return car;
}

void CarroDesaloca(Carro** carros, int n) {
    /* seu codigo aqui */
    for(int i =0; i< n; i++){
          FuncionarioDesaloca(&(*carros)[i].func);
    }
  
    free(*carros);
}

void le(Carro* carros, int n) {
    /* seu codigo aqui */
    for(int i = 0; i < n; i++){
        scanf("%d %s %d %d %s %d",&carros[i].chassi, carros[i].model, &carros[i].lugar, &carros[i].anofab, carros[i].func->nome, &carros[i].func->matric);
    }
   
}

int conta(Carro* carros, int n, const int ano, const int lugares) {
    /* seu codigo aqui */
    if(n == 0)
        return 0;
    int total = (carros[n-1].lugar > lugares && carros[n -1].anofab > ano);
    return total + conta(carros, n-1, ano, lugares);
}

void imprime(Carro* carros, int n, const char* nome) {
    /* seu codigo aqui */
    if(n == 0)
        return;
    if(strcmp(carros[n - 1].func->nome, nome)==0){
        printf("%s [%d|%d|%d]\n", carros[n-1].model, carros[n-1].anofab, carros[n-1].lugar, carros[n-1].chassi);
    }
    imprime(carros, n - 1 , nome);
    
}
