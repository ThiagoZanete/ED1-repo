#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
void TArvoreInicia (TNo **pRaiz){
  //PREENCHER AQUI
  *pRaiz = NULL;
}

//Manter como especificado
int TArvoreInsere (TNo **pNo, TItem item){
  //PREENCHER){
  //PREENCHER AQUI
  if((*pNo) == NULL){
    (*pNo) = TNoCria(item);
    return 1;
  }
  //printf("\n%s\n%s\n", item.chave, (*pNo)->item.chave);
  if(strcmp(item.chave, (*pNo)->item.chave) < 0){//se a chave for menor deve ser insreido a esquerda 
    if((*pNo)->esq == NULL){//se fr NULL é um nó folha
      (*pNo)->esq = TNoCria(item);
      return 1;
    }
    return TArvoreInsere(&((*pNo)->esq), item);//continua descendo na árvore
  }
  
  else if(strcmp(item.chave, (*pNo)->item.chave) > 0){//se a chave for maior deve ser inserido a direita
    if((*pNo)->dir == NULL){
      (*pNo)->dir = TNoCria(item);
      return 1;
    }
    return TArvoreInsere(&((*pNo)->dir), item);//ou continua descendo
  }
  else//aqui a chave já existe e o contador é incrementado  
    (*pNo)->item.cont++;
  return 0;
}

//Manter como especificado
TNo *TNoCria (TItem x){
  //PREENCHER AQUI
  //aloca um novo nó e atriubui o item x a ele
  TNo *new = (TNo*) malloc(sizeof(TNo));
  new->item = x;
  new->esq = NULL;
  new->dir = NULL;
  return new;
}

// realizar o caminhamento adequado na arvore
// Manter como especificado
void caminhamento(TNo *p) {
  //PREENCHER AQUI
  if(p == NULL)
    return;
  caminhamento(p->esq);//menores palvras
  printf("%s %d\n", p->item.chave, p->item.cont);
  caminhamento(p->dir);//maiores palvras
}


//essa bosta tá toda errada
void antecessor(struct No* q, struct No** p){
  if(q == NULL || *p == NULL)
    return;
  while(*p != NULL || *p < q){
    if(*p > q){
      printf("%d\n", (*p)->chave);
      break;
    }
    return(antecessor(q, (*p)->dir));
  }
  while(*p != NULL || *p > q){
    if(*p < q){
      printf("%d\n", (*p)->chave);
      break;
    }
    return(antecessor(q, (*p)->esq));
  }
  printf("Não tem antecessor");
}
