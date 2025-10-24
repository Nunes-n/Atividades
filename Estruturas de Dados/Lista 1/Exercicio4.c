/* Fazer um programa em C que recebe uma string de até 20 caracteres contendo uma 
expressão aritmética digitada pelo usuário. Essa expressão poderá conter 3 tipos de 
delimitadores de escopo e precedência: parênteses, colchetes e chaves. O programa 
deverá verificar se os delimitadores estão corretamente balanceados ou não, utilizando 
uma pilha para essa finalidade. 
Exemplos de expressões válidas:
(A+B)/C
A+(B/C)
[a-2]*(5+c)
{a*[c+d*(4*x)]}
(A)
Exemplos de expressões inválidas:
)A+B(/C
A+B/C)
[a-2)+(5+c]
{a*[c+d*(4*x)}]
(A

Observações:
a) Considere que não há qualquer tipo de hierarquia entre os delimitadores, ou 
seja, o usuário pode, a qualquer momento, iniciar uma expressão com qualquer 
um dos 3 tipos permitidos. 
b) Usar subrotinas para empilhar e desempilhar os elementos. 
c) Use a pilha para nela acrescentar (apenas) os delimitadores de abertura, ou seja, 
‘(’, ‘[’, ‘{’ encontrados na string. Ao encontrar um delimitador de fechamento, ou 
seja, ‘)’, ‘]’, ‘}’, retire o elemento do topo da pilha e verifique se ele é compatível 
com o delimitador que foi encontrado na cadeia. Se for, prossiga o 
processamento, se não for, encerre emitindo mensagem de erro. Se, ao final, a 
pilha estiver vazia, concluímos que a expressão contida na string é válida, pois 
está balanceada, e o programa deverá emitir uma mensagem informando isso. */

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
