/* lista.h */
/* TAD: lista de inteiros */

/* Tipo exportado */
typedef struct lista Lista;

/* Fun��es exportadas */

/* Fun��o cria
** Retorna um ponteiro nulo para inicializar a lista
*/
Lista* lst_cria();

/* Fun��o insere
** Insere um novo n� na lista, contendo a informa��o passada como argumento
** Retorna o ponteiro para a pr�pria lista
*/
Lista* lst_insere(Lista* l, int i);

/* Fun��o imprime
** Percorre a lista, imprimindo o conte�do de cada n�
*/
void lst_imprime(Lista* l);

/* Fun��o vazia
** Retorna um valor l�gico, indicando se a lista est� vazia ou n�o
*/
int lst_vazia(Lista* l);

/* Fun��o busca
** Percorre a lista, buscando o valor passado como par�metro
** Retorna o ponteiro para o n� que cont�m o valor, ou NULL, caso n�o exista
*/
Lista* lst_busca(Lista* l, int valor);

/* Fun��o retira
** Percorre a lista, buscando o valor passado como par�metro para que seja removido da lista
** Retorna o ponteiro para a pr�pria lista, atualizando-o
*/
Lista* lst_retira(Lista* l, int valor);

Lista* lst_pagina(Lista* l);

void lst_imprime_matriz(Lista* l);

/* Fun��o libera
** Libera a lista completamente, n� a n�
*/
void lst_libera(Lista* l);
