#include <stdio.h>
#define MAX 100

void maxheap(int *, int);
void imprimeArvoreC (int*);

int main (void)
{
    int arvore[MAX];
    for (int j = 1; j <= MAX; j++)
        arvore[j] = -9999;
    int valor;
    int i = 1;

    printf ("[-9999] para encerrar\n\n");

    while (i < MAX)
    {
        printf ("valor do no %d (maximo: %d): ", i, MAX - 1);
        scanf ("%d", &valor);

        if (valor == -9999)
            break;
        else
        {
            arvore[i] = valor;
            maxheap(arvore, i);
            imprimeArvoreC(arvore);
            printf ("\n");
        }

        i++;
    }

    return 0;
}

void maxheap (int *arv, int n)
{
    int f = n;

    while (f > 1 /*nao é a raiz*/ && arv[f / 2] /*pai*/ < arv[f] /*filho*/)
    {
        int aux = arv[f / 2];
        arv[f / 2] = arv[f];
        arv[f] = aux;
        f = f / 2;
    }
}

void imprimeArvoreC (int *arv)
{
    int i = 1;

    while (arv[i] != -9999)
    {
        printf ("%d ", arv[i]);
        i++;
    }
}