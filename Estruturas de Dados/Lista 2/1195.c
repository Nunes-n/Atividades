#include <stdio.h>
#include <stdlib.h>

struct regNo
{	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void ImprimePre(TNo *, int);
int IncluiItem(TNo **, int);
void ImprimeIn(TNo *, int);
void ImprimePost(TNo *, int);

int main(void) {
	int casos, quantidade, numero;
	int aux = 1;
	
	scanf ("%d", &casos);
	while (aux <= casos)
	{
		scanf ("%d", &quantidade);
		
		TNo *raiz = NULL;
		for (int n = 1; n <= quantidade; n++)
		{
			scanf ("%d", &numero);
			IncluiItem(&raiz, numero);
		}
		
		printf ("Case %d:", aux);
		printf ("\nPre.:");
		ImprimePre(raiz, 0);
		
		printf ("\nIn..:");
		ImprimeIn(raiz, 0);
		
		printf ("\nPost:");
		ImprimePost(raiz, 0);
		
		printf ("\n\n");
		
		aux++;
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

void ImprimePre(TNo *r, int n)
{
	if (r != NULL)
	{	
		printf(" %d", r->valor);
		ImprimePre(r->esq, n + 1);
		ImprimePre(r->dir, n + 1);
	}
}

void ImprimeIn(TNo *r, int n)
{
	if (r != NULL)
	{	
		ImprimeIn(r->esq, n + 1);
		printf(" %d", r->valor);
		ImprimeIn(r->dir, n + 1);
	}
}

void ImprimePost(TNo *r, int n)
{
	if (r != NULL)
	{	
		ImprimePost(r->esq, n + 1);
		ImprimePost(r->dir, n + 1);
		printf(" %d", r->valor);
	}
}

int IncluiItem(TNo **r, int n)
{
	TNo *aux;
	TNo *pai;
	aux = (TNo *) malloc(sizeof(TNo));
	if (aux == NULL)
		return 1;
	
	aux->valor = n;
	aux->dir = NULL;
	aux->esq = NULL;
	
	/* Fazendo o encadeamento do novo noh */
	pai = AchaPai(*r, n);
	if (pai == NULL)
		*r = aux;
	else
		if (n <= pai->valor)
			pai->esq = aux;
		else
			pai->dir = aux;

	return 0;
}