#include <stdio.h>

int emax(int[], int, int);
int emin(int[], int, int);

int main (void)
{
    int lista[26];
    int qtde, valor;

    while (1)
    {
        printf ("quantidade de nos: ");
        if (scanf("%d", &qtde) == EOF)
            return 0;

        if (qtde < 2 || qtde > 25)
        {
            printf ("quantidade de nos incopativel\n");
        }
        else
        {
            for (int i = 1; i <= qtde; i++)
            {
                printf ("valor do no: ");
                scanf ("%d", &valor);
                if (valor < -1000 || valor > 1000)
                {
                    printf ("valor incopativel\n");
                    qtde--;
                }
                else
                {
                    lista[i] = valor;
                }
            }

            if (emax(lista, 1, qtde) == 0)
            {
                printf ("max\n");
            }
            else
                if (emin(lista, 1, qtde) == 0)
                {
                    printf ("min\n");
                }
                else
                {
                    printf ("nada\n");
                }

        }
    }

    return 0;
}

int emax (int lista[], int n, int qtde)
{
    int filhoesq;
    int filhodir;

    if (n * 2 > qtde) //nao tem filhos
    {
        return 0;
    }
    else
        if (n * 2 + 1 > qtde) //tem apenas o da esquerda
        {
            if (lista[n] > lista[n * 2])
            {
                return emax(lista, n * 2, qtde);
            }
            else return 1;
        }
        else //possui os dois filhos
            if (lista[n] > lista[n * 2] && lista[n] > lista[n * 2 + 1])
            {
                filhoesq = emax(lista, n * 2, qtde);
                filhodir = emax(lista, n * 2 + 1, qtde);

                if (filhoesq == 0 && filhodir == 0)
                {
                    return 0;
                }
                else return 1;
            }
            else return 1;
}

int emin (int lista[], int n, int qtde)
{
    int filhoesq;
    int filhodir;

    if (n * 2 > qtde) //nao tem filhos
    {
        return 0;
    }
    else
        if (n * 2 + 1 > qtde) //tem apenas o da esquerda
        {
            if (lista[n] < lista[n * 2])
            {
                return emin(lista, n * 2, qtde);
            }
            else return 1;
        }
        else //possui os dois filhos
            if (lista[n] < lista[n * 2] && lista[n] < lista[n * 2 + 1])
            {
                filhoesq = emin(lista, n * 2, qtde);
                filhodir = emin(lista, n * 2 + 1, qtde);

                if (filhoesq == 0 && filhodir == 0)
                {
                    return 0;
                }
                else return 1;
            }
            else return 1;
}
