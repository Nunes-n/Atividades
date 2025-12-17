/*
    a) Recebe uma sequência de inteiros e monta a árvore binária ordenada correspondente. Em
seguida exibir a descrição da árvore na notação textual indicada anteriormente.
*/

#include <stdio.h>
#include <stdlib.h>

struct TNo
{
    struct TNo *esq;
    int valor;
    struct TNo* dir;
};
typedef struct TNo TNo;

int insereValor (TNo **, int);
TNo* achaPai(TNo *, int);
void imprimeDescr(TNo *);

int main(void)
{
    int valor;
    TNo *raiz = NULL;

    printf ("[-9999 para encerrar]\n");

    while (1)
    {
        printf ("valor do no: ");
        scanf ("%d", &valor);

        if (valor != -9999)
        {
            if (insereValor(&raiz, valor) == 1)
                printf ("erro: memoria insuficiente\n");
        }
        else break;
    }

    imprimeDescr(raiz);
    printf ("\n");

    return 0;
}

int insereValor (TNo **r, int n)
{
    TNo *aux = (TNo *) malloc(sizeof(TNo));
    if (aux == NULL)
        return 1;

    aux->valor = n;
    aux->esq = NULL;
    aux->dir = NULL;

    TNo *pai = achaPai(*r, n);
    if (pai == NULL)
        *r = aux;
    else
        if (aux->valor > pai->valor)
            pai->dir = aux;
        else
            pai->esq = aux;

    return 0;
}

TNo* achaPai(TNo *r, int n)
{
    if (r == NULL) //arvore vazia, é a raiz
        return NULL;

    if (r->valor < n) // é o filho da direita
    {
        if (r->dir == NULL)
            return r;
        else
            return achaPai(r->dir, n);
    }
    else //é o filho da esquerda
    {
        if (r->esq == NULL)
            return r;
        else
            return achaPai(r->esq, n);
    }
}

void imprimeDescr(TNo *r)
{
    if (r == NULL)
    {
        printf ("< >");
    }
    else
    {
        printf ("<%d", r->valor);
        imprimeDescr(r->esq);
        imprimeDescr(r->dir);
        printf (">");
    }
}
