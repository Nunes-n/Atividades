/*
	Programa que opera uma arvore binaria nao ordenada com a inclusao 
	ocorrendo por nivel (so inicia um nivel apos o nivel anterior estar
	totalmente preenchido)
	Lista 2 exercicio 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE  1
#define FALSE 0
#define QTDE_MAX 500

struct regNo
{ 	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
int AlturaArv(TNo *);
int ContaNos(TNo *);
int ContaPares(TNo *);
void ImprimeArvoreNvl(TNo *);
int IncluiItem(TNo **, int);
int PesquisaValor(TNo *, int);

int main(void)
{ 	TNo *raiz = NULL;
	int numero;

	while (TRUE)
	{	printf("\nInforme o valor:\n"); scanf("%d", &numero);

		if (numero == -999) break;

		if (IncluiItem(&raiz, numero) == FALSE)
		{	puts("Memoria insuficiente para inclusao");
			return 2;
		}
	}
		
	printf("\n\nConteudo da arvore\n");
	ImprimeArvoreNvl(raiz);
	printf("Resumo\n");
	printf("  Qtde nos: %3d\n", ContaNos(raiz));
	printf("  Altura .: %3d\n", AlturaArv(raiz));
	printf("  Pares ..: %3d\n", ContaPares(raiz));
	printf("\n");
	
	while (TRUE)
	{	printf("\nInforme o valor:\n"); scanf("%d", &numero);

		if (numero == -999) break;

		if (PesquisaValor(raiz, numero) == FALSE)
			printf("Valor %d nao existe na arvore\n", numero);
		else
			printf("%d encontrado\n", numero);
	}
	
	return 0;
}

TNo *AchaPai(TNo *r, int n)
{	TNo *fila[QTDE_MAX], *aux;
	int inicio, final;

	if (r == NULL)
		return NULL;

	inicio = final = 0;
	aux = r;
	while (aux->esq != NULL && aux->dir != NULL)
	{	fila[final++] = aux->esq;
		fila[final++] = aux->dir;
	
		aux = fila[inicio++];
	}
	
	return aux;
}

int IncluiItem(TNo **r, int n)
{	TNo *aux, *pai;

	aux = (TNo *) malloc(sizeof(TNo));
	if (aux == NULL)
		return FALSE;

	aux->valor = n;
	aux->dir = NULL;
	aux->esq = NULL;

	/* Fazendo o encadeamento do novo noh */
	pai = AchaPai(*r, n);
	if (pai == NULL)
		*r = aux;
	else
		if (pai->esq == NULL)
			pai->esq = aux;
		else
			pai->dir = aux;

	return TRUE;
}

int PesquisaValor (TNo *r, int n)
{
	if (r == NULL)
		return FALSE;
	
	if (r->valor == n)
		return TRUE;
	else
		if (PesquisaValor(r->esq, n) == TRUE || PesquisaValor(r->dir, n) == TRUE)
			return TRUE;
		else return FALSE;
}

int ContaNos (TNo *r)
{
	if (r != NULL)
		return 1 + ContaNos(r->esq) + ContaNos(r->dir);
	else
		return 0;
}

int ContaPares (TNo *r)
{
	if (r == NULL)
		return 0;
	else
		if (r->valor % 2 == 0)
			return 1 + ContaPares(r->esq) + ContaPares(r->dir);
		else
			return 0 + ContaPares(r->esq) + ContaPares(r->dir);;
}

int AlturaArv (TNo *r)
{
	int lvl = 0;
	
	if (r != NULL)
	{
		while (aux->esq != NULL)
		{
			lvl++;
			r = r->esq;
		}
		return lvl;
	}
	else return lvl;
}

void ImprimeArvoreNvl(TNo *r)
{
	printf ("Nivel Valores\n");
	printf ("----------------------------------------\n");
	
	TNo *fila[QTDE_MAX], *aux;
	int inicio, final, qtde;
	int altura = AlturaArv(r);
	
}
