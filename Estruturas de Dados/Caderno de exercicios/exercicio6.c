/* Para se determinar o número de lâmpadas necessárias para cada cômodo de uma residência, 
existem normas que dão o mínimo de potência de iluminação exigida por metro quadrado (m2) 
conforme a utilização desse cômodo. Seja a seguinte tabela tomada como exemplo: 
Utilização | Classe | Potência / m2
-----------------------------------
  Quarto   |    1   |     15 
Sala de TV |    1   |     15 
   Salas   |    2   |     18 
 Cozinha   |    2   |     18 
 Varandas  |    2   |     18 
Escritório |    3   |     20 
 Banheiro  |    3   |     20
 ---------------------------------
Faça um programa que recebe e armazena em uma lista encadeada o nome do cômodo, a 
largura, o comprimento, a classe e a potência por m2 requerida. Exiba o conteúdo da lista. 
Depois, em um looping, receba do usuário qual a potência das lâmpadas a serem usadas e 
determine: 
a) Para cada cômodo: 
a.1. O cômodo; 
a.5. A área do cômodo; 
a.6. Número de lâmpadas necessárias. 
b) Para toda a residência: 
b.1. Total de lâmpadas; 
b.2. Total de potência requerida. 
Encerrar o programa quando o usuário informar uma potência de lâmpada ≤ 0. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct comodo
{
	char nome[31];
	float largura, comprimento;
	int classe, potenciaMq;
	struct comodo *prox;
};
typedef struct comodo comodo;

struct lista
{
	comodo *inicio, *final;
};
typedef struct lista lista;

int incluiItem(lista *, char[], float, float, int, int);
void imprimeLista(lista *);
void calculaLampadas(lista *, float);

int main(void)
{
	lista l;
	l.inicio = NULL;
	l.final = NULL;
	
	char nome[31];
	float largura, comprimento;
	int classe, potencia;
	float potLampada;
	
	printf ("Cadastro de comodos ('f' para encerrar)");
	
	while (1)
	{
		
		printf ("\nNome do comodo: ");
		scanf ("%s", nome);
		
		if (strcmp(nome, "f") == 0 || strcmp(nome, "F") == 0)
		{
			break;
		}
		
		printf ("Largura do comodo: ");
		scanf ("%f", &largura);
		
		printf ("Comprimento do comodo: ");
		scanf ("%f", &comprimento);
		
		printf ("Classe do comodo: ");
		scanf ("%d", &classe);
		
		printf ("Potencia por metro quadrado: ");
		scanf ("%d", &potencia);
		
		if (incluiItem(&l, nome, largura, comprimento, classe, potencia) == 1)
		{
			printf ("\nMemoria insuficiente");
		}
	}
	
	imprimeLista(&l);
	
	while (1)
	{
		printf ("\nInsira a Potencia das lampadas (0 ou menos para encerrar): ");
		scanf ("%f", &potLampada);
		if (potLampada <= 0)
		{
			break;
		}
		calculaLampadas(&l, potLampada);
	}
	
	return 0;
}

int incluiItem(lista *l, char nome[], float largura, float comprimento, int classe, int potencia)
{
	comodo *aux = (comodo *) malloc(sizeof(comodo));
	if (aux == NULL)
	{
		return 1;
	}
	
	strcpy(aux->nome, nome);
	aux->largura = largura;
	aux->comprimento = comprimento;
	aux->classe = classe;
	aux->potenciaMq = potencia;
	aux->prox = NULL;
	
	if (l->inicio == NULL)
	{
		l->inicio = aux;
		l->final = aux;
	}
	else
	{
		l->final->prox = aux;
		l->final = aux;
	}
	
	return 0;
}

void imprimeLista(lista *l)
{
	printf ("\nImpressao dos comodos: ");
	comodo *aux = l->inicio;
	
	if (l->inicio == NULL)
	{
		printf ("\nNenhum comodo registrado");
	}
	else
	{
		while (aux != NULL)
		{
			printf ("\nNome: %s", aux->nome);
			printf ("\nLargura: %f", aux->largura);
			printf ("\nComprimento: %f", aux->comprimento);
			printf ("\nClasse: %d", aux->classe);
			printf ("\nPotencia por metro quadrado: %d\n", aux->potenciaMq);
			
			aux = aux->prox;
		}
	}
}

void calculaLampadas(lista *l, float potLampada)
{
	comodo *aux = l->inicio;
	float area, potComodo;
	int qtdeLampadas;
	
	float potTotal = 0.0;
	int totalLampadas = 0;
	
	while (aux != NULL)
	{
		area = aux->largura * aux->comprimento;
		potComodo = area * aux->potenciaMq;
		qtdeLampadas = ceil(potComodo / potLampada);
		
		printf ("\nNome: %s", aux->nome);
		printf ("\nArea: %.2f", area);
		printf ("\nLampadas necessarias: %d\n", qtdeLampadas);
		
		potTotal = potTotal + potComodo;
		totalLampadas = totalLampadas + qtdeLampadas;
		
		aux = aux->prox;
	}
	
	printf ("\nPotencia total: %.3f", potTotal);
	printf ("\nQuantidade total de lampadas: %d", totalLampadas);

}
