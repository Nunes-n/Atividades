#include <stdio.h>
#include <stdlib.h>

#define FALSE	0
#define TRUE	1

struct regNo
{ 	struct regNo *esq;
	int valor;
	struct regNo *dir;
	int qtde;
	struct regNo *ancestral;
};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
int ContaNos(TNo *);
int ContaValores(TNo *);
void Impressao(TNo *);
void ImprimeAncestrais(TNo *);
void ImprimeArvore(TNo *, int);
int IncluiItem(TNo **, int);
TNo *PesquisaValor(TNo *, int);

TNo *raiz = NULL;

int main(void)
{	int numero;

	while (TRUE)
	{	printf("\nInforme o valor:\n"); scanf("%d", &numero);

		if (numero == -999) break;

		if (IncluiItem(&raiz, numero) == FALSE)
		{	puts("Memoria insuficiente para inclusao");
			return 2;
		}
	}

	Impressao(raiz);
		
	while (TRUE)
	{	printf("\nInforme o valor:\n"); scanf("%d", &numero);

		if (numero == -999) break;

		TNo *pesquisa = PesquisaValor(raiz, numero);
		
		if (pesquisa == NULL)
			printf("Valor %d nao encontrado na arvore\n", numero);
		else
			ImprimeAncestrais(pesquisa);
	}
	
	return 0;
}

TNo *AchaPai(TNo *r, int n)
{	if (r == NULL)
		return NULL;
	else
		if (n <= r->valor)
		/* n é descendente do lado esquerdo de r */
			if (r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, n);
		else
		/* n é descendente do lado direito de r */
			if (r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, n);
}

int ContaNos(TNo *r)
{	if (r == NULL)
		return 0;
	else
		return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

void Impressao(TNo *r)
{	if (r == NULL)
		puts("Arvore vazia");
	else
	{	printf("\n\nA arvore possui %d elementos:\n", ContaNos(r));
		ImprimeArvore(r, 0);
	}
}

void ImprimeArvore(TNo *r, int n)
{	int c;
	
	if (r != NULL)
	{	ImprimeArvore(r->esq, n + 1);

		for (c = 0; c < n; c++) printf("  ");
		if (r->qtde > 1)
			printf("%d [%d]\n", r->valor, r->qtde);
		else
			printf("%d\n", r->valor);

		ImprimeArvore(r->dir, n + 1);
	}
}

int IncluiItem(TNo **r, int n)
{	TNo *aux, *pai, *igual;

	igual = PesquisaValor(*r, n);
	if (igual != NULL)
	{
		igual->qtde = igual->qtde + 1;
		return TRUE;
	}
	
	aux = (TNo *) malloc(sizeof(TNo));
	if (aux == NULL)
		return FALSE;

	aux->valor = n;
	aux->dir = NULL;
	aux->esq = NULL;
	aux->qtde = 1;

	/* Fazendo o encadeamento do novo nó */
	pai = AchaPai(*r, n);
	if (pai == NULL)
	{
		*r = aux;
		aux->ancestral = NULL;
	}
	else
	{
		if (n <= pai->valor)
			pai->esq = aux;
		else
			pai->dir = aux;
		
		aux->ancestral = pai;
	}
	return TRUE;
}

TNo *PesquisaValor(TNo *r, int n)
{	if (r == NULL || r->valor == n)
		return r;
	
	if (n < r->valor)
		return PesquisaValor(r->esq, n);
	else
		return PesquisaValor(r->dir, n);
}

void ImprimeAncestrais(TNo *p)
{
	if (p->qtde > 1)
		printf ("%d [%d] <- ", p->valor, p->qtde);
	else
		printf ("%d <- ", p->valor);

	if (p->ancestral != NULL)
		ImprimeAncestrais(p->ancestral);
	else
		printf ("raiz\n");
}
