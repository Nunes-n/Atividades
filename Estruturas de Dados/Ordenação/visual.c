#include <stdio.h>
#include <unistd.h>

void espaco();
void imprimeLista(int[], int, int);
void bubblePrint(int[], int);
void selectionPrint(int[], int);

int main (void)
{
    int lista[16];
    int valor, tamanho;
    char tipo;

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
    imprimeLista(lista, tamanho, 17);

    printf ("[b] = bubble sort\n");
    printf ("[s] = selection sort\n");
    scanf (" %c", &tipo);

    printf ("iniciando ordenacao . . .\n");
    sleep(5);

    if (tipo == 'b' || tipo == 'B')
        bubblePrint(lista, tamanho);
    else
        if (tipo == 's' || tipo == 'S')
            selectionPrint(lista, tamanho);

    return 0;
}

void imprimeLista (int lista[], int qtde, int vetor)
{
    for (int i = 0; i < qtde; i++)
    {
        printf ("%2d", lista[i]);
        for (int j = 0; j < lista[i]; j++)
        {
            printf ("|");
        }
        if (vetor == i)
            printf (" <");
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
            //impressao
            espaco();
            imprimeLista(lista, qtde, j);

            if (lista[j] >= lista[j + 1])
            {
                aux = lista[j];
                lista[j] = lista[j+ 1];
                lista[j + 1] = aux;
            }
        }
    }

    espaco();
    imprimeLista(lista, qtde, 17);
}

void selectionPrint (int lista[], int qtde)
{
    int menorvt, aux;

    for (int i = 0; i < qtde; i++)
    {
        int menor = lista[i];
        menorvt = i;

        for (int j = i; j < qtde; j++)
        {
            if (lista[j] <= menor)
            {
                menor = lista[j];
                menorvt = j;
            }

            espaco();
            imprimeLista(lista, qtde, j);
        }

        aux = lista[i];
        lista[i] = lista[menorvt];
        lista[menorvt] = aux;
    }

    espaco();
    imprimeLista(lista, qtde, 17);
}

void espaco()
{
    sleep(1);
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
