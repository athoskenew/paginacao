#include <stdio.h>
#include <stdlib.h>
#include "matriz.c"
#include "lista.c"
/*
** A matriz sera considerada um processo
** A lista sera considerada uma pagina
*/

// Assinatura das funcoes
void criar_processo (matriz_t* p, int id, int npr, int local, Lista* pr);
int mapeamento (Lista* l);
void imprime_processo (matriz_t* p);
matriz_t* seta_processo(Lista* pr);
matriz_t* seta_processo_ms(Lista* pr);
//  Processo 2112
/*  [npv][npr][bitv][bitm][local]
    [ 0 ][ 0 ][ 1  ][ 1  ][ mp  ]
	[ 1 ][ 1 ][ 1  ][ 0  ][ mp  ]
	[ 2 ][ 2 ][ 1  ][ 0  ][ mp  ]
	[ 3 ][ 3 ][ 1  ][ 0  ][ mp  ]
	[ 4 ][ 4 ][ 1  ][ 0  ][ mp  ]
*/    

//  inicio da função main
int main(void){
	Lista* l;
	matriz_t * m; //= matriz_criar(5,5); // linhas x colunas
	matriz_t * n;
	matriz_t * k;
	l = lst_cria();
	l = lst_pagina(l); //cria a pagina com 100 posicoes
	printf("-------------Matriz 1 Processo------------\n"); // Processo na MP
	m = seta_processo(l);
	matriz_imprimir(m);
	printf("-------------Matriz 2 Processo------------\n"); // Processo na Memoria Secundaria (HD)
	n = seta_processo_ms(l);
	matriz_imprimir(n);
	printf("-------------Matriz 3 Processo------------\n"); // Processo na MP
	k = seta_processo(l);
	matriz_imprimir(k);
	printf("-------------Matriz Pagina--------------\n");
	lst_imprime_matriz(l); //imprime a pagina completa
	return 0;
}

// seta os elementos da matriz 
/* Processo p -> será o processo criado que vai ser preenchido.
// int id -> é o id único do processo.	
// int npr -> será o primeiro valor disponível na página real
// e aumentará +5 a partir deste valor inicial.
// int local -> indica o local que o processo está
// sendo 1 = MP, 2 = MS.
*/

void criar_processo (matriz_t* m, int id, int npr, int local, Lista* pr){
	int inicio_r = npr;
	int i,j;
	Lista* aux = pr;
	//preenchendo NPV
	for(i=0;i<5;i++){
		matriz_setar_elemento(m,0,i,i);
	}
	
	//preenchendo NPR
	j = 0;
	if(local==1){
		for(i = inicio_r;i<((inicio_r)+5);i++){
			matriz_setar_elemento(m,1,j,i);
			j++;
		}
		for(i=0;i<npr;i++){
			aux = aux->prox;
		}
		for (i=0;i<5;i++){
			aux->info = 1;
			aux = aux->prox;
		}
	}
	else{
		for(i = inicio_r;i<((inicio_r)+5);i++){
			matriz_setar_elemento(m,1,j,0);
			j++;
		}
	}
	//preenchendo o bit verificador
	if (local == 1){
		for(i=0;i<5;i++){
			matriz_setar_elemento(m,2,i,1); //caso esteja na mp coloca 1 no bit verificador
		}	
	}
	else {
		for(i=0;i<5;i++){
			matriz_setar_elemento(m,2,i,0); //caso não esteja, coloca 0 no bit verificador
		}
	}
	
	//preenchendo o Bit M
	j = 0;
	matriz_setar_elemento(m,3,0,1); // primeiro bit M com valor 1
	for(i=1;i<5;i++){
			matriz_setar_elemento(m,3,i,0); // o resto seta como 0
		}
	
	//preenchendo o local
	j = 0;
	if(local==1){
		for(i=0;i<5;i++){
			matriz_setar_elemento(m,4,i,1); //valor 1 representa a MP na coluna [i][4] da matriz
		}
	}
	else{
		for(i=0;i<5;i++){
			matriz_setar_elemento(m,4,i,2); //valor 2 representa a MS na coluna [i][4] da matriz
		}
	}

}

int mapeamento (Lista* l){
	// vai mapear para ver qual posicao da pag esta livre
	int i,j;
	Lista* aux;
	aux = l;
	for (i=0;i<100;i++){
		if(aux->info == 1){
			aux = aux->prox;
		}
		else{
			break;
		}
	}
	// esse if precisa ser alterado para que bloqueie a entrada
	// de novos processos na mp
	if(i==99){
		i = 101; //sai do range da matriz, disfarcando a entrada de novos elementos
	}
	return i;
}

matriz_t* seta_processo(Lista* pr){
	matriz_t * m = matriz_criar(5,5);
	int id = 0; // colocar numero aleatorio
	int local = 1; // colocar fixo 1 que e a MP
	int npr = mapeamento(pr); // número da pagina real que esta livre
	criar_processo(m,id,npr,local,pr);
	
	return m;
}

matriz_t* seta_processo_ms(Lista* pr){
	matriz_t * m = matriz_criar(5,5);
	int id = 0; // colocar numero aleatorio
	int local = 2; // colocar fixo 2 que e a MS
	int npr = mapeamento(pr); // número da pagina real que esta livre
	criar_processo(m,id,npr,local,pr);
	
	return m;
}
