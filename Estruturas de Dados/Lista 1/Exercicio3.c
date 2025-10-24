/*Um programa escrito em C constrói duas listas encadeadas simples utilizando os 
valores digitados pelo usuário. A primeira lista é referenciada pelo descritor lst1 e a 
segunda lista é referenciada pelo descritor lst2. Escreva uma rotina que constrói uma 
terceira lista, referenciada pelo descritor lst3, cujo conteúdo é a concatenação das 
duas primeiras listas, ou seja, uma lista cujos elementos iniciais provêm da segunda 
lista, e após estes, os elementos da primeira lista, conforme o exemplo abaixo. Após 
criar a terceira lista, destruir as listas 1 e 2 e imprimir o conteúdo da nova lista por 
meio de uma subrotina. Considere as definições de tipos de dados e variáveis abaixo, 
que foram feitas fora da rotina main() do programa. Para destruir uma lista utilize uma 
subrotina que desaloca todos os seus itens da memória e reinicializa seus descritores. 
struct elemento {float valor ; struct elemento* prox ;}; 
typedef struct elemento TElemento; 
typedef struct {TElemento *inicio, *final; int qtde;} TLista;
TLista lst1, lst2, lst3; 
float vrdig = 0; */

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
	
	lista3->qtde = lista1->qtde + lista2->qtde;
	
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
		
		printf ("\nQuantidade : %d", lista->qtde);
	}
}

