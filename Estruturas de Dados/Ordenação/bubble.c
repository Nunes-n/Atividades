#include <stdio.h>
#include <unistd.h>

void imprimeLista(int[], int);
void bubblePrint(int[], int);

int main (void)
{
    int lista[16];
    int valor, tamanho;

    printf ("quantidade de elementos (max: 15): ");
    scanf ("%d", &tamanho);

    if (tamanho < 0 || tamanho > 15)
        return 0;

    for (int i = 0; i < tamanho; i++)
    {
        printf ("valor do elemento %d da lista (0 < x < 100): ", i + 1);
        scanf ("%d", &valor);

        if (valor > 0 && valor < 100)
        {
            lista[i] = valor;
        }
        else
        {
            printf ("valor invalido\n");
            i--;
        }
    }

    printf ("\nconteudo da lista atual\n");
    imprimeLista(lista, tamanho);

    printf ("iniciando ordenacao . . .\n");
    sleep(5);

    bubblePrint(lista, tamanho);

    return 0;
}

void imprimeLista (int lista[], int qtde)
{
    for (int i = 0; i < qtde; i++)
    {
        printf ("%2d", lista[i]);
        for (int j = 0; j < lista[i]; j++)
        {
            printf ("|");
        }
        printf ("\n");
    }
    printf ("\n");
}

void bubblePrint (int lista[], int qtde)
{
    int aux;

    for (int i = 0; i < qtde; i++)
    {
        for (int j = 0; j < qtde - 1 - i; j++)
        {
            if (lista[j] >= lista[j + 1])
            {
                aux = lista[j];
                lista[j] = lista[j+ 1];
                lista[j + 1] = aux;

                //impressao
                sleep(1);
                printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                imprimeLista(lista, qtde);
            }

        }
    }
}
