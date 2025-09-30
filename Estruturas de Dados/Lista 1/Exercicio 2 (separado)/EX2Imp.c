#include <stdio.h>
#include <string.h>
#include "EX2Hea.h"

void iniciaLista (TLista *lista)
{
	lista->qtdeItens = 0;
	lista->qtdeComprados = 0;
}

int IncluiItem (TLista *lista, char *nome, float qtde)
{
	if (lista->qtdeItens == MAX)
	{
		return 1;
	}
	
	int auxi = 0;
	
	while (auxi < lista->qtdeItens && strcmp(nome, lista->itens[auxi].nome) > 0)
	{
		auxi += 1;
	}
	
	int auxj = lista->qtdeItens;
	
	while (auxj > auxi)
	{
		lista->itens[auxj] = lista->itens[auxj -1];
		auxj -= 1;
	}
	
	strcpy(lista->itens[auxi].nome, nome);
	lista->itens[auxi].qtde = qtde;
	lista->itens[auxi].comprado = 0;
	
	lista->qtdeItens += 1;
	
	return 0;
}

void ImprimeLista (TLista *lista, char op)
{
	int aux;
	
	if (lista->qtdeItens == 0)
	{
		printf ("\nLista Vazia\n");
	}
	else
	{
		if (op == 'f' || op == 'F')
		{
			printf ("\nLista de compras (do inicio):");
			
			aux = 0;
			while (aux < lista->qtdeItens)
			{
				printf ("\n%s %.2f %d", lista->itens[aux].nome, lista->itens[aux].qtde, lista->itens[aux].comprado);
				aux += 1;
			}
		}
		else
		{
			if (op == 'r' || op == 'R')
			{
				printf ("\nLista de compras (do final)");
				
				aux = lista->qtdeItens - 1;
				while (aux >= 0)
				{
					printf ("\n%s %.2f %d", lista->itens[aux].nome, lista->itens[aux].qtde, lista->itens[aux].comprado);
					aux -= 1;
				}
			}
			else
			{
				printf ("\nOperacao invalida");
			}
		}
		
		printf ("\nTotal itens: %d Itens comprados: %d", lista->qtdeItens, lista->qtdeComprados);
		
		printf ("\n\n");
	}
}

int AtualizaItem (TLista *lista, char *nome)
{
	int aux = 0;
	
	while (aux < lista->qtdeItens && strcmp(lista->itens[aux].nome, nome) != 0)
	{
		aux += 1;
	}
	
	if (aux == lista->qtdeItens)
	{
		return 1;
	}
	else
	{
		if (lista->itens[aux].comprado == 1)
		{
			return 2;
		}
		else
		{
			lista->itens[aux].comprado = 1;
			lista->qtdeComprados += 1;
			return 0;
		}
	}
}

int ExcluiItem(TLista *lista, char *nome)
{
	int aux = 0;
	
	while (aux < lista->qtdeItens && strcmp(lista->itens[aux].nome, nome) != 0)
		aux += 1;
	
	if (aux == lista->qtdeItens)
		return 1;
	else
	{
		if (lista->itens[aux].comprado == 1)
		{
			lista->qtdeComprados -= 1;
		}
		
		while (aux < lista->qtdeItens - 1)
		{
			lista->itens[aux] = lista->itens[aux + 1];
			aux += 1;
		}
		
		lista->qtdeItens -= 1;
	}
	
	return 0;
}

void EncerraPrograma(TLista *lista)
{
	int itensF;
	
	itensF = lista->qtdeItens - lista->qtdeComprados;
	
	printf ("\nFim do programa (%d itens sem comprar)", itensF);
}
