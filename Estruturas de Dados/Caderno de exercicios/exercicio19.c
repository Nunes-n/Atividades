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
int iguais(TNo *, TNo *);

int main(void)
{
    int valor;
    int enc = 1;
    TNo *raiz1 = NULL;
    TNo *raiz2 = NULL;

    printf ("[-9999 para ir para a segunda arvore e para encerrar]\n");

    while (1)
    {
        printf ("valor do no (arvore %d): ", enc);
        scanf ("%d", &valor);

        if (valor != -9999)
        {
            if (enc == 1)
            {
                if (insereValor(&raiz1, valor) == 1)
                    printf ("erro: memoria insuficiente\n");
            }
            else
            {
                if (insereValor(&raiz2, valor) == 1)
                    printf ("erro: memoria insuficiente\n");
            }
        }
        else
            if (enc == 1)
                enc++;
            else
                break;
    }

    if (iguais(raiz1, raiz2) == 0)
        printf ("as arvores sao equivalentes\n");
    else
        printf ("as arvore nao sao equivalentes\n");

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

int iguais (TNo *r1, TNo *r2)
{
    if (r1 == NULL && r2 == NULL)
        return 0;
    else
        if (r1 == NULL || r2 == NULL)
            return 1;

    if (r1->valor == r2->valor)
        return iguais(r1->esq, r2->esq) + iguais(r1->dir, r2->dir);
    else return 1;
}