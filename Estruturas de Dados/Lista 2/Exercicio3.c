#include <stdio.h>

int emax(int[], int);
int emin(int[], int);

int main (void)
{
    int lista[26];
    int qtde, valor;

    while (1)
    {
        for (int i = 0; i < 26; i++)
        {
            lista[i] = 9999;
        }

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
                printf ("\nvalor do no: ");
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

            if (emax(lista, 1) == 0)
            {
                printf ("max\n");
            }
            else
                if (emin(lista, 1) == 0)
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

int emax (int lista[], int n)
{
    int filho1, filho2;

    if (lista[n * 2] != 9999 && lista[n * 2 + 1] != 9999)
    {
        if (lista[n] > lista[n * 2] && lista[n] > lista[n * 2 + 1])
        {
            filho1 = emax(lista, n * 2);
            filho2 = emax(lista, n * 2 + 1);

            if (filho1 == 0 && filho2 == 0)
                return 0;
            else return 1;
        }
    }
    else
        if (lista[n * 2] != 9999)
        {
            if (lista[n] > lista[n * 2])
            {
                filho1 = emax(lista, n * 2);

                if (filho1 == 0)
                    return 0;
                else return 1;
            }
        }
        else
            if (lista[n * 2 + 1] != 9999)
            {
                if (lista[n] > lista[n * 2 + 1])
                {
                    filho2 = emax(lista, n * 2 + 1);

                    if (filho2 == 0)
                        return 0;
                    else return 1;
                }
            }
            else return 0;

/*
    if (lista[n] > lista[n * 2] && lista[n] > lista[n * 2 + 1])
    {
        if (lista[n * 2] != 9999) //filho da esquerda
            filho1 = emax(lista, n * 2);
        else
            filho1 = 0;

        if (lista[n * 2 + 1] != 9999) //filho da direita
            filho2 = emax(lista, n * 2 + 1);
        else
            filho2 = 0;


        if (filho1 == 0 && filho2 == 0) 
            return 0;
        else
            return 1;
    }
    else return 1;
    */
}

int emin (int lista[], int n)
{
    int filho1, filho2;

    if (lista[n] < lista[n * 2] && lista[n] < lista[n * 2 + 1])
    {
        if (lista[n * 2] != 9999) //filho da esquerda
            filho1 = emin(lista, n * 2);
        else
            filho1 = 0;

        if (lista[n * 2 + 1] != 9999) //dilho da direita
            filho2 = emin(lista, n * 2 + 1);
        else
            filho2 = 0;


        if (filho1 == 0 && filho2 == 0)
            return 0;
        else
            return 1;
    }
    else return 1;
}
