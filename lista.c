/* lista.c */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {			// estrutura de cada nó da lista
	int info;
	struct lista* prox;
};

Lista* lst_cria() {
	return NULL;		// retorna um ponteiro nulo para representar lista vazia
}

Lista* lst_insere(Lista* l, int i) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));	// aloca espaço de memória para o novo Nó
	if( novo == NULL ) {							// caso não haja memória suficiente
		printf("Memoria insuficiente!\n");			// saia
		exit(1);
	}
	novo->info = i;									// atribui a informação do argumento à informação do Nó
	novo->prox = l;									// liga o ponteiro 'prox' do Nó ao primeiro elemento da lista
	return novo;									// retorna o ponteiro para o Nó criado, para que passe a ser o primeiro
}

void lst_imprime(Lista* l) {
	Lista* aux;										// ponteiro de lista auxiliar para percorrê-la
	for(aux = l; aux != NULL; aux = aux->prox) {	// laço para percorrer cada Nó
		printf("%d ", aux->info);	// e imprimir o seu conteúdo
	}
	printf("\n");
}
void lst_imprime_matriz(Lista* l) {
	Lista* aux;
	int i,j = 0;								    // ponteiro de lista auxiliar para percorrê-la
	for(aux = l; aux != NULL; aux = aux->prox) {	// laço para percorrer cada Nó
		if(j<10){
			printf("[%d  -> %d] ", j, aux->info);
		}
		else{
			printf("[%d -> %d] ", j, aux->info);
		}
		i++;										// e imprimir o seu conteúdo
		j++;
		if(i==10){
			printf("\n");
			i = 0;
		}
	}
	printf("\n");
}

Lista* lst_pagina(Lista* l){
	int i;
	for(i=0;i<100;i++){
		l = lst_insere(l,0);
	}
	return l;
}

int lst_vazia(Lista* l) {
	if( l == NULL )									// se a lista for vazia, então seu ponteiro é nulo
		return 1;									// retorne '1' se for vazia
	else
		return 0;									// '0' caso contrário
}

Lista* lst_busca(Lista* l, int valor) {
	Lista* p;										// ponteiro auxiliar de lista para percorrê-la
	for(p = l; p != NULL; p = p->prox)				// laço principal. Executa até o fim da lista
		if( p->info == valor )						// se encontrar o valor,
			return p;								// retorne o ponteiro para nó que contém o valor
	return NULL;									// se não encontrar, o laço encerra e um valor 'NULL' é retornado, indicando fim da lista
}

Lista* lst_retira(Lista* l, int valor) {
	Lista* ant = NULL;								// ponteiro auxiliar para guardar a referência do nó anterior
	Lista* p = l;									// ponteiro auxiliar para percorrer a lista
	
	while(p != NULL && p->info != valor) {			// o laço executa até atingir o fim da lista ou até o valor ter sido encontrado
		ant = p;									// atualiza o valor do ponteiro anterior para o nó atual
		p = p->prox;								// atualiza o valor do ponteiro atual para o próximo
	}
	
	if( p == NULL )									// se tiver atingido o fim da lista significa que o valor não foi encontrado
		return l;										// então retorne a lista original, sem mudanças
		
	if( ant == NULL )								// se o valor inicial de 'ant' (NULL) não tiver sido alterado, significa que o nó removido foi o primeiro
		l = p->prox;									// então basta apontar o ponteiro original da lista para o segundo nó
	else											// caso contrário (o elemento a ser retirado NÃO é o primeiro, ou seja, está no meio ou fim da lista)
		ant->prox = p->prox;							// então basta conectar o nó anterior com o próximo do nó que foi removido
		
	free(p);										// libere o espaço de memória apenas do nó que foi removido
	return l;										// retorne o ponteiro original da lista para atualizá-la
}

void lst_libera(Lista* l) {
	Lista* p = l;									// ponteiro auxiliar para percorrer a lista, nó a nó
	while( p!=NULL ) {								// o laço executa até que se atinja o fim da lista
		Lista* t = p->prox;								// um ponteiro auxiliar local guarda a referência do próximo nó, para que o atual possa ser liberado sem perdas de referência
		free(p);										// desaloca o espaço de memória do nó a ser removido
		p = t;											// atualiza o ponteiro que percorre para o próximo nó, que foi guardado anteriormente em 't'
	}
}

