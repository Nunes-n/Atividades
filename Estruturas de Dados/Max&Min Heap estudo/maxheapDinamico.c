/*
    programa onde você escolhe o tipo de heap e, conforme vai inserindo os nós
    a árvore vai se atualizando de acordo com o heap escolhido.
    a impressão e inserção é por niveis.
*/

#include <stdio.h>
#define MAX 100

void minheap(int *, int);
void maxheap(int *, int);
void imprimeArvoreC (int*);

int main (void)
{
    int arvore[MAX];
    int valor;
    int i = 1;
    char tipoheap;

    for (int j = 1; j <= MAX; j++)
        arvore[j] = -9999;


    while (1)
    {
        printf ("[m] = max heap\n[n] = min heap\n");
        scanf (" %c", &tipoheap);
        if ((tipoheap == 'm' || tipoheap == 'M') || (tipoheap == 'n' || tipoheap == 'N'))
            break;
        else
            printf ("tipo invalidp\n");
    }

    printf ("\n[-9999] para encerrar\n\n");

    while (i < MAX)
    {
        printf ("valor do no %d (maximo: %d): ", i, MAX - 1);
        scanf ("%d", &valor);

        if (valor == -9999)
            break;
        else
        {
            arvore[i] = valor;

            if (tipoheap == 'm' || tipoheap == 'M')
                maxheap(arvore, i);
            else
                minheap(arvore, i);

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

void minheap (int *arv, int n)
{
    int f = n;

    while (f > 1 /*nao é a raiz*/ && arv[f / 2] /*pai*/ > arv[f] /*filho*/)
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
    int qtdelvl = 1;
    int lvl = 0;

    while (1)
    {
        if (arv[i] == -9999)
            break;
        else
            printf ("nivel %d: ", lvl);

        for (int j = 0; j < qtdelvl; j++)
        {
            if (arv[i] != -9999)
            {
                printf ("%d ", arv[i]);
            }
            i++;
        }
        printf ("\n");
        lvl++;
        qtdelvl = qtdelvl * 2;
    }
}
