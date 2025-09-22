#include <stdio.h>
#include <stdlib.h>

		struct itens {char nome[26]; float qtde; int comprado; struct itens *prox, *ant;};
typedef struct itens TItem;
typedef struct {TItem *inicio, *final; int qtdeItens, qtdeComprados;} TLista;

TLista lista;

void iniciaLista (TLista *);
int IncluiItem (TLista *, char, float);

int main(void)
{
	char operacao = NULL, nome[26];
	float qtde;
	
	iniciaLista(&lista);
	
	while (operacao != '*')
	{
		scanf (" %c", &operacao);
		
		if (operacao == 'I' || operacao == 'i')
		{
			scanf ("%s %f", nome, &qtde);
			if (IncluiItem(&lista, nome, qtde) == 1)
			{
				printf ("\nErro fatal: memoria insuficiente");
			}
		}
		else
			if (operacao == 'A' || operacao == 'a')
			{
				return 0;
			}
			else
				if (operacao == 'X' || operacao == 'x')
				{
					return 0;
				}
				else
					if (operacao == 'P' || operacao == 'p')
					{
						return 0;
					}
					else
						printf ("\nOperacao invalida");
	}
	
	return 0;
}






void iniciaLista (TLista *lista)
{
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtdeItens = 0;
	lista->qtdeComprados = 0;
}

int IncluiItem (TLista *lista, char nome[26], float qtde)
{
	TItem *aux;
	
	aux = (TItem *) malloc(sizeof(TItem));
	
	if (aux == NULL)
	{
		return 1;
	}
	
	strcopy(aux->nome, nome);
	aux->qtde = qtde;
	aux->comprado = 0;
	aux->prox = NULL;
	aux->ant = NULL;
	
	if (lista->inicio == NULL)
	{
		lista->inicio = aux;
		lista->final = aux;
	}
	else
	{
		lista->final->prox = aux; //ainda nao sei
	}
	
	return 0;
}