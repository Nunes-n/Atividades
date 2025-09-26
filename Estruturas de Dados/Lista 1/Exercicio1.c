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
int ExcluiItem(TLista *, char *);

int main(void)
{
	char operacao = ' ';
	char op;
	char nome[26];
	float qtde;
	
	iniciaLista(&lista);
	
	while (operacao != '*')
	{
		printf ("Digite a operacao: ");
		scanf (" %c", &operacao);
		
		if (operacao == 'I' || operacao == 'i')
		{
			printf ("Digite o nome e quantidade do produto: ");
			scanf ("%s %f", nome, &qtde);
			if (IncluiItem(&lista, nome, qtde) == 1)
			{
				printf ("\nErro fatal: memoria insuficiente\n\n");
			}
			else
			{
				printf ("\nIncluiu %s\n\n", nome);
			}
		}
		else
			if (operacao == 'A' || operacao == 'a')
			{
				printf ("Digite o nome do produto: ");
				scanf ("%s", nome);
				int retorno = AtualizaItem(&lista, nome);
				if (retorno == 1)
				{
					printf ("\nItem nao encontrado\n\n");
				}
				else
				{
					if (retorno == 2)
						printf ("\nErro: %s ja foi comprado\n\n", nome);
					else
						printf ("\nComprou %s\n\n", nome);
				}
			}
			else
				if (operacao == 'X' || operacao == 'x')
				{
					printf ("Digite o nome do produto: ");
					scanf ("%s", nome);
					if (ExcluiItem(&lista, nome) == 1)
					{
						printf ("\nProduto nao encontrado\n");
					}
					else
					{
						printf ("\n%s foi excluido\n", nome);
					}
				}
				else
					if (operacao == 'P' || operacao == 'p')
					{
						printf ("Digite o tipo de impressao: ");
						scanf (" %c", &op);
						ImprimeLista (&lista, op);
					}
					else
					{
						if (operacao != '*')
							printf ("\nOperacao invalida\n\n");
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
		printf ("\nLista Vazia\n");
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
		
		printf ("\n\n");
	}
}

int AtualizaItem (TLista *lista, char *nome)
{
	TItem *aux = lista->inicio;
	
	while (aux != NULL && strcmp(aux->nome, nome) != 0)
	{
		aux = aux->prox;
	}
	
	if (aux == NULL)
	{
		return 1;
	}
	else
	{
		if (aux->comprado == 1)
		{
			return 2;
		}
		else
		{
			aux->comprado = 1;
			lista->qtdeComprados += 1;
			return 0;
		}
	}
}

int ExcluiItem(TLista *lista, char *nome)
{	TItem *aux;

	aux = lista->inicio;
	while (aux != NULL && strcmp(aux->nome,nome) != 0)
	{	
		aux = aux->prox;
	}
	
	if (aux == NULL)
	{
		return 1;
	}
	else
	{	
		if (aux->ant == NULL) //é o primeiro
		{
			lista->inicio = aux->prox;
			if (aux->prox == NULL) // é também o ultimo: lista fica vazia
			{
				lista->final = NULL;
			}
			else
			{
				aux->prox->ant = NULL;
			}
		}
		else
		{
			if (aux->prox == NULL) // é o ultimo
			{
				lista->final = aux->ant;
				aux->ant->prox = NULL;
			}
			else //está no meio
			{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
			}
		}
		
		lista->qtdeItens -= 1;
		if (aux->comprado == 1)
		{
			lista->qtdeComprados -= 1;
		}
		
		free(aux);
		
		return 0;
	}
}