/*OBJETIVOS:
	-Implementar listas encadeadas simples, permitindo ao usuário inserir némeros reais positivos em duas listas separadas e, a partir delas, criar uma terceira lista que é uma concatenação das duas listas;
	-A terceira lista deve ter os elementos da segunda lista e em seguida os elementos da primeira;
	-Após a criação da terceira lista, destruir as duas primeiras e então imprimi-la;
*/

#include <stdio.h>
#include <stdlib.h>

		struct elemento { float valor; struct elemento* prox; };
typedef struct elemento TElemento;
typedef struct { TElemento *inicio, *final; int qtde;} TLista;

TLista lst1, lst2, lst3;
float vrdig = 0;

void IniciaLista (TLista *);
int IncluiElemento (TLista *, float);
void ConstroiLista (TLista *, TLista *, TLista *);
void DestroiLista(TLista *);
void ImprimeLista (TLista *);


int main(void)
{
	float numero;
	
	IniciaLista(&lst1);
	IniciaLista(&lst2);
	IniciaLista(&lst3);
	
	while (1)
	{
		printf ("\nInforme o elemento (lista 1): ");
		scanf ("%f", &numero);
		
		if (numero < 0)
		{
			break;
		}
		if (IncluiElemento(&lst1,numero) == 1)
		{
			printf ("\nErro fatal: memoria insuficiente");
			return 9;
		}
	}
	
	while (1)
	{
		printf ("\nInforme o elemento (lista 2): ");
		scanf ("%f", &numero);
		
		if (numero < 0)
		{
			break;
		}
		if (IncluiElemento(&lst2,numero) == 1)
		{
			printf ("\nErro fatal: memoria insuficiente");
			return 9;
		}
	}
	
	ConstroiLista(&lst2, &lst1, &lst3);
	
	ImprimeLista(&lst3);
	
	return 0;
}

void IniciaLista (TLista *lista)
{
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
}

int IncluiElemento (TLista *lista, float numero)
{
	TElemento *aux;
	
	aux = (TElemento *) malloc(sizeof(TElemento));
	
	if (aux == NULL)
	{
		return 1;
	}
	
	aux->valor = numero;
	aux->prox = NULL;
	
	if (lista->inicio == NULL)
	{
		lista->inicio = aux;
	}
	else
	{
		lista->final->prox = aux;
	}
	
	lista->qtde = lista->qtde + 1;
	lista->final = aux;
	
	return 0;
}

void ConstroiLista (TLista *lista2, TLista *lista1, TLista *lista3)
{
	TElemento *aux;
	
	aux = lista2->inicio;
	while (aux != NULL)
	{
		IncluiElemento(lista3, aux->valor);
		aux = aux->prox;
	}
	
	aux = lista1->inicio;
	while (aux != NULL)
	{
		IncluiElemento(lista3, aux->valor);
		aux = aux->prox;
	}
	
	DestroiLista(lista2);
	DestroiLista(lista1);
}

void DestroiLista(TLista *lista)
{
	TElemento *aux, *seg;
	
	aux = lista->inicio;
	while (aux != NULL)
	{
		seg = aux->prox;
		free(aux);
		aux = seg;
	}
	
	IniciaLista(lista);
}

void ImprimeLista (TLista *lista)
{
	TElemento *aux;
	
	if (lista->inicio == NULL)
	{
		printf ("\nLista Vazia");
	}
	else
	{
		printf ("\n\nConteudo da lista 3:\n");
		
		aux = lista->inicio;
		while (aux != NULL)
		{
			printf ("\n%.2f", aux->valor);
			aux = aux->prox;
		}
	}

}
