#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"

void TArvoreinicia(TNo **ppRaiz){
    (*ppRaiz) = NULL;
}

int TArvoreInsere(TNo **ppNo, TItem x){
    if((*ppNo) == NULL){
        (*ppNo) = TNoCria(x);
        return 1;
    }

    //comparar se é menor
    if(strcmp((*ppNo)->item.chave, x.chave) < 0){
        if((*ppNo)->esq == NULL){
            (*ppNo) = TNoCria(x);
            return 1;
        }
        return(TArvoreInsere(&((*ppNo)->esq), x));
    }else if(strcmp((*ppNo)->item.chave, x.chave) > 0){//se é maior 
        if((*ppNo)->dir == NULL){
            (*ppNo) = TNoCria(x);
            return 1;
        } 
        return(TArvoreInsere(*((*ppNo)->dir), x));
    }else{//se são iguais
        (*ppNo)->item.cont++;
        return 0;
    }
}
TNo* TNoCria(TItem x){
    TNo *new = malloc(sizeof(TNo));
    new->esq = NULL;
    new->dir = NULL;
    new->item = item;
    return new;
 }

 void caminhamento(TNo *p){
    if(p == NULL)
        return;
    caminhamento(p->esq);
    printf("%s %d", p->item.chave, p->item.cont);
    caminhamento(p->dir);
 }