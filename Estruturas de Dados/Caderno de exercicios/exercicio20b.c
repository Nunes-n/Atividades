#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

struct TNo
{
    struct TNo *esq;
    int valor;
    struct TNo* dir;
};
typedef struct TNo TNo;

int insereValor (TNo **, int);
TNo* achaPai(TNo *, int);
void imprimeArvore(TNo *, int);

int main(void)
{
    char descr[MAX];
    char val[MAX];
    int i = 0;
    TNo *raiz = NULL;

    printf ("[-9999 para encerrar]\n");

    printf ("descricao textual da arvore: ");
    scanf ("%s", descr);

    if (strcmp(descr,"-9999") != 0)
    {
        while (descr[i] != '\0')
        {
            int j = 0;

            if (descr[i] != '<' && descr[i] != '>' && descr[i] != ' ' && descr[i] != 32)
            {
                val[j] = descr[i];
                while (descr[i + 1] != '\0' && descr[i + 1] != '<' && descr[i + 1] != '>' && descr[i + 1] != ' ' && descr[i + 1] != 32)
                {
                    val[j + 1] = descr[i + 1];
                    i++;
                    j++;
                }
                val[j + 1] = '\0';

                int valor = atoi(val);

                if (insereValor(&raiz, valor) == 1)
                    printf ("erro: memoria insuficiente\n");

            }

            i++;
        }
    }

    printf ("\nImpressao da arvore (pre-order): \n");
    imprimeArvore(raiz, 0);
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

void imprimeArvore (TNo *r, int n)
{
    if (r != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            printf ("   ");
        }
        printf ("%d\n", r->valor);
        imprimeArvore(r->esq, n + 1);
        imprimeArvore(r->dir, n + 1);
    }
}