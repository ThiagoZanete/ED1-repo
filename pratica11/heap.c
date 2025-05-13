#include "heap.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Mantenha como especificado
 * Refaz o heap da raiz para as folhas
 */ 
void refaz(Heap *heap);

/** Mantenha como especificado
 * Insere um chamada na posicao index
 */ 
void heapInsere(Heap *heap, Chamada chamada, int index);

/** Mantenha como especificado
 * Retorna true se c1 tem mais prioridade do que c2.
 * Se forem iguais, retorne false
 */ 
bool temMaisPrioridade(Chamada* c1, Chamada* c2);

// Mantenha como especificado
Chamada criarChamada(char *nome, int prioridade, int dia, int mes, int ano) {
    /* Preencher aqui */
    Chamada novaChamada;
    strcpy(novaChamada.nome, nome);
    novaChamada.prioridade = prioridade;
    novaChamada.nascimento.dia = dia;
    novaChamada.nascimento.mes = mes;
    novaChamada.nascimento.ano = ano;
    return novaChamada;
}

// Mantenha como especificado
void imprimeChamada(Chamada chamada) {
    printf("%02d | %02d/%02d/%04d | %s\n", chamada.prioridade, chamada.nascimento.dia,
            chamada.nascimento.mes, chamada.nascimento.ano, chamada.nome);
}

// Mantenha como especificado
Heap* criarHeap() {
    /* Preencher aqui */
    Heap *heap = malloc(sizeof(Heap));
    heap->tam = 0;
    return heap;
}

// Mantenha como especificado
Heap* destroiHeap(Heap *heap) {
    /* Preencher aqui */
    free(heap);
    return NULL;
}

// Mantenha como especificado
void inserirChamada(Heap *heap, Chamada chamada) {
    /* Preencher aqui */
    // A posicao que deve-se inserir no heap eh na primeira posicao vazia do heap
    // Chame a funcao heapInsere
    heapInsere(heap, chamada, heap->tam);
}

// Mantenha como especificado
Chamada atenderChamada(Heap *heap) {
    /* Preencher aqui */
    // Remover a chamada com maior prioridade do heap
    Chamada chamRemovida = heap->chamadas[0];// a chamada com maior prioridade sempre vai estar na posição 0 do vetor heap
    heap->chamadas[0] = heap->chamadas[heap->tam-1];
    heap->tam--;
    refaz(heap);
    return chamRemovida;

}

// Mantenha como especificado
bool consultarSeTemProximaChamada(Heap *heap) {
    /* Preencher aqui */
    // Verifica se tem o heap tem pelo menos uma chamada
    if(heap->tam > 0)
        return true;
    return false;
}

//Mantenha como especificado
void refaz(Heap *heap) {
    if (heap->tam <= 1) return; // Se houver 0 ou 1 elemento, já está organizado

    int i = 0; // Começa na raiz
    while (2 * i + 1 < heap->tam) { // Enquanto houver filhos
        int filhoEsq = 2 * i + 1;
        int filhoDir = 2 * i + 2;
        int maior = filhoEsq;

        // Verifica se o filho direito existe e tem maior prioridade que o esquerdo
        if (filhoDir < heap->tam && temMaisPrioridade(&heap->chamadas[filhoDir], &heap->chamadas[filhoEsq])) {
            maior = filhoDir;
        }

        // Se o pai já tiver mais prioridade que o maior filho, o heap já está organizado
        if (temMaisPrioridade(&heap->chamadas[i], &heap->chamadas[maior])) {
            break;
        }

        // Troca o pai com o maior filho
        Chamada temp = heap->chamadas[i];
        heap->chamadas[i] = heap->chamadas[maior];
        heap->chamadas[maior] = temp;

        i = maior; // Continua descendo no heap
    }
}


// Mantenha como especificado
void heapInsere(Heap *heap, Chamada chamada, int index) {
    /* Preencher aqui */
    if (heap->tam >= 100) return;  // Caso o heap esteja cheio

    // Inserir o novo elemento no final
    heap->chamadas[heap->tam] = chamada;
    
    // Restaurar a propriedade do heap
    int i = heap->tam;
    heap->tam++;
    while (i > 0 && temMaisPrioridade(&heap->chamadas[i], &heap->chamadas[(i - 1) / 2])) {
        // Troca com o pai se tiver mais prioridade
        Chamada temp = heap->chamadas[i];
        heap->chamadas[i] = heap->chamadas[(i - 1) / 2];
        heap->chamadas[(i - 1) / 2] = temp;
        
        i = (i - 1) / 2;  // Sobe no heap
    }


}

// Mantenha como especificado
bool temMaisPrioridade(Chamada* c1, Chamada* c2) {
    if (c1->prioridade > c2->prioridade) return true;
    if (c1->prioridade < c2->prioridade) return false;

    // Comparar data de nascimento se prioridade for igual
    if (c1->nascimento.ano < c2->nascimento.ano) return true;
    if (c1->nascimento.ano > c2->nascimento.ano) return false;
    
    if (c1->nascimento.mes < c2->nascimento.mes) return true;
    if (c1->nascimento.mes > c2->nascimento.mes) return false;
    
    return c1->nascimento.dia < c2->nascimento.dia;
}
