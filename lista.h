/* lista.h */
/* TAD: lista de inteiros */

/* Tipo exportado */
typedef struct lista Lista;

/* Funções exportadas */

/* Função cria
** Retorna um ponteiro nulo para inicializar a lista
*/
Lista* lst_cria();

/* Função insere
** Insere um novo nó na lista, contendo a informação passada como argumento
** Retorna o ponteiro para a própria lista
*/
Lista* lst_insere(Lista* l, int i);

/* Função imprime
** Percorre a lista, imprimindo o conteúdo de cada nó
*/
void lst_imprime(Lista* l);

/* Função vazia
** Retorna um valor lógico, indicando se a lista está vazia ou não
*/
int lst_vazia(Lista* l);

/* Função busca
** Percorre a lista, buscando o valor passado como parâmetro
** Retorna o ponteiro para o nó que contém o valor, ou NULL, caso não exista
*/
Lista* lst_busca(Lista* l, int valor);

/* Função retira
** Percorre a lista, buscando o valor passado como parâmetro para que seja removido da lista
** Retorna o ponteiro para a própria lista, atualizando-o
*/
Lista* lst_retira(Lista* l, int valor);

Lista* lst_pagina(Lista* l);

void lst_imprime_matriz(Lista* l);

/* Função libera
** Libera a lista completamente, nó a nó
*/
void lst_libera(Lista* l);
