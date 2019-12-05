#include <stdio.h>
#include <stdlib.h>
#include "matriz.c"
#include "lista.c"

//  inicio do struct de processos
struct processo{
	int id;
	int info[5][5];
};
typedef struct processo Processo;

// Assinatura das funcoes
void criar_processo (matriz_t* p, int id, int npr, int local);
void mapeamento (matriz_t* p);
void imprime_processo (matriz_t* p);

//  Processo 2112
/*  [npv][npr][bitv][bitm][local]
    [ 0 ][ 0 ][ 1  ][ 1  ][ mp  ]
	[ 1 ][ 1 ][ 1  ][ 0  ][ mp  ]
	[ 2 ][ 2 ][ 1  ][ 0  ][ mp  ]
	[ 3 ][ 3 ][ 1  ][ 0  ][ mp  ]
	[ 4 ][ 4 ][ 1  ][ 0  ][ mp  ]
*/    

//  vetor que será a "página real"

//  inicio da função main
int main(void){
	Lista* l;
	//l = lst_pagina; //cria a pagina com 100 posicoes
	//lst_imprime_matriz(l); //imprime a pagina completa
	
	matriz_t * m = matriz_criar(5,5); // linhas x colunas
	criar_processo(m,2,0,1);
	matriz_imprimir(m);
	return 0;
}

/* Processo p -> será o processo criado que vai ser preenchido.
// int id -> é o id único do processo.	
// int npr -> será o primeiro valor disponível na página real
// e aumentará +5 a partir deste valor inicial.
// int local -> indica o local que o processo está
// sendo 1 = MP, 2 = MS.
*/

void criar_processo (matriz_t* m, int id, int npr, int local){
	//p.id = id;
	int inicio_r = npr;
	int i,j;
	//preenchendo NPV
	for(i=0;i<5;i++){
		matriz_setar_elemento(m,0,i,i);
	}
	
	//preenchendo NPR
	j = 0;
	for(i = inicio_r;i<((inicio_r)+5);i++){
		matriz_setar_elemento(m,1,j,i);
		j++;
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

void mapeamento (matriz_t* p){
	
}
