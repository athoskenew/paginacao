/* lista.c */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {			// estrutura de cada n� da lista
	int info;
	struct lista* prox;
};

Lista* lst_cria() {
	return NULL;		// retorna um ponteiro nulo para representar lista vazia
}

Lista* lst_insere(Lista* l, int i) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));	// aloca espa�o de mem�ria para o novo N�
	if( novo == NULL ) {							// caso n�o haja mem�ria suficiente
		printf("Memoria insuficiente!\n");			// saia
		exit(1);
	}
	novo->info = i;									// atribui a informa��o do argumento � informa��o do N�
	novo->prox = l;									// liga o ponteiro 'prox' do N� ao primeiro elemento da lista
	return novo;									// retorna o ponteiro para o N� criado, para que passe a ser o primeiro
}

void lst_imprime(Lista* l) {
	Lista* aux;										// ponteiro de lista auxiliar para percorr�-la
	for(aux = l; aux != NULL; aux = aux->prox) {	// la�o para percorrer cada N�
		printf("%d ", aux->info);	// e imprimir o seu conte�do
	}
	printf("\n");
}
void lst_imprime_matriz(Lista* l) {
	Lista* aux;
	int i,j = 0;								    // ponteiro de lista auxiliar para percorr�-la
	for(aux = l; aux != NULL; aux = aux->prox) {	// la�o para percorrer cada N�
		if(j<10){
			printf("[%d  -> %d] ", j, aux->info);
		}
		else{
			printf("[%d -> %d] ", j, aux->info);
		}
		i++;										// e imprimir o seu conte�do
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
	if( l == NULL )									// se a lista for vazia, ent�o seu ponteiro � nulo
		return 1;									// retorne '1' se for vazia
	else
		return 0;									// '0' caso contr�rio
}

Lista* lst_busca(Lista* l, int valor) {
	Lista* p;										// ponteiro auxiliar de lista para percorr�-la
	for(p = l; p != NULL; p = p->prox)				// la�o principal. Executa at� o fim da lista
		if( p->info == valor )						// se encontrar o valor,
			return p;								// retorne o ponteiro para n� que cont�m o valor
	return NULL;									// se n�o encontrar, o la�o encerra e um valor 'NULL' � retornado, indicando fim da lista
}

Lista* lst_retira(Lista* l, int valor) {
	Lista* ant = NULL;								// ponteiro auxiliar para guardar a refer�ncia do n� anterior
	Lista* p = l;									// ponteiro auxiliar para percorrer a lista
	
	while(p != NULL && p->info != valor) {			// o la�o executa at� atingir o fim da lista ou at� o valor ter sido encontrado
		ant = p;									// atualiza o valor do ponteiro anterior para o n� atual
		p = p->prox;								// atualiza o valor do ponteiro atual para o pr�ximo
	}
	
	if( p == NULL )									// se tiver atingido o fim da lista significa que o valor n�o foi encontrado
		return l;										// ent�o retorne a lista original, sem mudan�as
		
	if( ant == NULL )								// se o valor inicial de 'ant' (NULL) n�o tiver sido alterado, significa que o n� removido foi o primeiro
		l = p->prox;									// ent�o basta apontar o ponteiro original da lista para o segundo n�
	else											// caso contr�rio (o elemento a ser retirado N�O � o primeiro, ou seja, est� no meio ou fim da lista)
		ant->prox = p->prox;							// ent�o basta conectar o n� anterior com o pr�ximo do n� que foi removido
		
	free(p);										// libere o espa�o de mem�ria apenas do n� que foi removido
	return l;										// retorne o ponteiro original da lista para atualiz�-la
}

void lst_libera(Lista* l) {
	Lista* p = l;									// ponteiro auxiliar para percorrer a lista, n� a n�
	while( p!=NULL ) {								// o la�o executa at� que se atinja o fim da lista
		Lista* t = p->prox;								// um ponteiro auxiliar local guarda a refer�ncia do pr�ximo n�, para que o atual possa ser liberado sem perdas de refer�ncia
		free(p);										// desaloca o espa�o de mem�ria do n� a ser removido
		p = t;											// atualiza o ponteiro que percorre para o pr�ximo n�, que foi guardado anteriormente em 't'
	}
}

