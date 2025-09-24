#include <stdio.h>
#include <stdlib.h>
#include <string.h>

		struct itens {char nome[26]; float qtde; int comprado; struct itens *prox, *ant;};
typedef struct itens TItem;
typedef struct {TItem *inicio, *final; int qtdeItens, qtdeComprados;} TLista;

TLista lista;

void iniciaLista (TLista *);
int IncluiItem (TLista *, char *, float);
void ImprimeLista (TLista *, char);
int AtualizaItem (TLista *, char *);

int main(void)
{
	char operacao = ' ';
	char op;
	char nome[26];
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
				printf ("\nErro fatal: memoria insuficiente\n");
			}
			else
			{
				printf ("\nIncluiu %s\n", nome);
			}
		}
		else
			if (operacao == 'A' || operacao == 'a')
			{
				scanf ("%s", nome);
				if (AtualizaItem(&lista, nome) == 1)
				{
					printf ("\nItem nao encontrado");
				}
				else
				{
					printf ("\nAtualizou %s", nome);
				}
			}
			else
				if (operacao == 'X' || operacao == 'x')
				{
					return 0;
				}
				else
					if (operacao == 'P' || operacao == 'p')
					{
						scanf (" %c", &op);
						ImprimeLista (&lista, op);
					}
					else
					{
						if (operacao != '*')
							printf ("\nOperacao invalida\n");
					}
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

int IncluiItem (TLista *lista, char *nome, float qtde)
{
	TItem *aux;
	
	aux = (TItem *) malloc(sizeof(TItem));
	
	if (aux == NULL)
	{
		return 1;
	}
	
	strcpy(aux->nome, nome);
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
		TItem *cmp = lista->inicio;
		
		if (strcmp(aux->nome, cmp->nome) < 0)
		{
			//esta no inicio
			aux->prox = cmp;
			aux->ant = NULL;
			cmp->ant = aux;
			lista->inicio = aux;
		}
		else
		{
			while (cmp->prox != NULL && strcmp(aux->nome, cmp->prox->nome) > 0)
			{
				cmp = cmp->prox;
			}
			
			if (cmp->prox == NULL)
			{
				//esta no final
				aux->prox = NULL;
				aux->ant = cmp;
				cmp->prox = aux;
				lista->final = aux;
			}
			else
			{
				//esta no meio
				aux->prox = cmp->prox;
				aux->ant = cmp;
				cmp->prox->ant = aux;
				cmp->prox = aux;
			}
		}
	}
	
	lista->qtdeItens += 1;
	
	return 0;
}

void ImprimeLista (TLista *lista, char op)
{
	TItem *aux;
	
	if (lista->inicio == NULL)
	{
		printf ("\nLista Vazia");
	}
	else
	{
		if (op == 'f' || op == 'F')
		{
			printf ("\nLista de compras (do inicio):");
			
			aux = lista->inicio;
			while (aux != NULL)
			{
				printf ("\n%s %.2f %d", aux->nome, aux->qtde, aux->comprado);
				aux = aux->prox;
			}
		}
		else
		{
			if (op == 'r' || op == 'R')
			{
				printf ("\nLista de compras (do final)");
				
				aux = lista->final;
				while (aux != NULL)
				{
					printf ("\n%s %.2f %d", aux->nome, aux->qtde, aux->comprado);
					aux = aux->ant;
				}
			}
			else
			{
				printf ("\nOperacao invalida");
			}
		}
		
		printf ("\n");
	}
}

int AtualizaItem (TLista *lista, char *nome)
{
	TItem *aux = lista->inicio;
	
	while (aux != NULL && aux->nome != nome)
	{
		aux = aux->prox;
	}
	
	if (aux == NULL)
	{
		return 1;
	}
	else
	{
		aux->comprado = 1;
		return 0;
	}
}
