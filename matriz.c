#include <stdio.h>
#include <stdlib.h>


typedef struct elemento_s elemento_t;
typedef struct matriz_s matriz_t;


struct elemento_s
{
    int valor;
    elemento_t * abaixo;
    elemento_t * direita;
};


struct matriz_s
{
    elemento_t * inicio;
    int linhas;
    int colunas;
};


matriz_t * matriz_criar( int linhas, int colunas )
{
    int l = 0;
    int c = 0;
    elemento_t * esq = NULL;
    elemento_t * prim = NULL;
    elemento_t * ant = NULL;
    elemento_t * inicio = NULL;

    for( l = 0; l < linhas; l++ )
    {
        esq = NULL;

        for( c = 0; c < colunas; c++ )
        {
            elemento_t * el = (elemento_t*) calloc( 1, sizeof(elemento_t) );

            el->valor = 0;

            if( !inicio )
                inicio = el;

            if( esq )
                esq->direita = el;

            esq = el;

            if( ant )
            {
                int i = 0;
                elemento_t * aux = ant;

                for( i = 0; i < c; i++ )
                    aux = aux->direita;

                aux->abaixo = el;
            }

            if( c == 0 )
                prim = el;
        }

        ant = prim;
    }

    matriz_t * m = (matriz_t*) calloc( 1, sizeof(matriz_t) );

    m->inicio = inicio;
    m->colunas = colunas;
    m->linhas = linhas;

    return m;
}


void matriz_destruir( matriz_t * m )
{
    elemento_t * ec = m->inicio;
    elemento_t * el = NULL;
    elemento_t * aux = NULL;

    while( ec )
    {
        el = ec->direita;

        while(el)
        {
            aux = el->direita;
            free(el);
            el = aux;
        }

        aux = ec->abaixo;
        free(ec);
        ec = aux;
    }

    free(m);
}


elemento_t * matriz_obter_elemento( matriz_t * m, int col, int linha )
{
    int i = 0;
    elemento_t * e = m->inicio;

    for( i = 0; i < linha; i++ )
        e = e->abaixo;

    for( i = 0; i < col; i++ )
        e = e->direita;

    return e;
}


void matriz_setar_elemento( matriz_t * m, int col, int linha, int valor )
{
    elemento_t * e = matriz_obter_elemento( m, col, linha );
    e->valor = valor;
}


void matriz_debug( matriz_t * m )
{
    int l = 0;
    int c = 0;

    printf("matriz=%p, colunas=%d, linhas=%d, inicio=%p\n", m, m->colunas, m->linhas, m->inicio );

    for( l = 0; l < m->linhas; l++ )
    {
        for( c = 0; c < m->colunas; c++ )
        {
            elemento_t * e = matriz_obter_elemento( m, c, l );
            printf("    col=%d, linha=%d, elemento=%p, abaixo=%p, direita=%p, valor=%d\n", c, l, e, e->abaixo, e->direita, e->valor );
        }
    }

}

void matriz_imprimir( matriz_t * m )
{
    int l = 0;
    int c = 0;

    printf("matriz=%p, colunas=%d, linhas=%d, inicio=%p\n", m, m->colunas, m->linhas, m->inicio );

    for( l = 0; l < m->linhas; l++ )
    {
        for( c = 0; c < m->colunas; c++ )
        {
            elemento_t * e = matriz_obter_elemento( m, c, l );
            printf("[%d] ", e->valor);
        }
        printf("\n");
    }

}
