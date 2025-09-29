#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 21

		struct item {char caracter; struct item *prox, *ant;};
typedef struct item TItem;
typedef struct {TItem *final, *inicio;} TPilha;

TPilha pilha;

int Empilha(TPilha *, char);
int Desempilha(TPilha *, char);
void IniciaPilha (TPilha *);

int main (void)
{
	char exp[MAX];
	
	printf ("Insira a expressao: ");
	scanf ("%20s", exp);
	
	IniciaPilha(&pilha);
	
	int cont = 0;
	while (exp[cont] != '\0')
	{
		char elemento = exp[cont];
		
		if (exp[cont] == '(' || exp[cont] == '[' || exp[cont] == '{')
		{
			if (Empilha(&pilha, elemento) == 1)
			{
				printf ("\nErro: memoria insuficiente");
				return 1;
			}
		}
		else
			if (exp[cont] == ')' || exp[cont] == ']' || exp[cont] == '}')
			{
				if (Desempilha(&pilha, elemento) == 1)
				{
					printf ("\nExpressao nao eh valida");
					return 1;
				}
			}
			
		cont += 1;
	}
	
	if (pilha.inicio == NULL)
	{
		printf ("\nExpressao eh valida");
	}
	else
	{
		printf ("\nExpressao nao eh valida");
	}
	
	return 0;
}




void IniciaPilha (TPilha *pilha)
{
	pilha->inicio = NULL;
	pilha->final = NULL;
}

int Empilha(TPilha *pilha, char elemento)
{
	TItem *aux;
	
	aux = (TItem *) malloc(sizeof(TItem));
	
	if (aux == NULL)
	{
		return 1;
	}
	
	aux->caracter = elemento;
	aux->prox = NULL;
	aux->ant = NULL;
	
	if (pilha->inicio == NULL)
	{
		pilha->inicio = aux;
		pilha->final = aux;
	}
	else
	{
		pilha->final->prox = aux;
		aux->ant = pilha->final;
	}
	
	pilha->final = aux;
	
	return 0;
}

int Desempilha(TPilha *pilha, char elemento)
{
	if (pilha->final == NULL)
	{
		return 1;
	}
	
	if ((pilha->final->caracter == '(' && elemento != ')') || (pilha->final->caracter == '[' && elemento != ']') || (pilha->final->caracter == '{' && elemento != '}'))
	{
		return 1;
	}
	else
	{
		TItem *aux = pilha->final;
		
		pilha->final = pilha->final->ant;
		if (pilha->final == NULL)
		{
			pilha->inicio = NULL;
		}
		else
		{
			pilha->final->prox = NULL;
		}
		
		free(aux);
		
		return 0;
	}
}