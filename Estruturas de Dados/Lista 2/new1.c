#include <stdio.h>
#include <stdlib.h>

struct regNo
{	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void ImprimeArvore(TNo *, int);
int ContaNos(TNo *);
int SomaNos(TNo *);
int ContaPares(TNo *);
int IncluiItem(TNo **, int);
TNo *MaiorValor(TNo *);
TNo *MenorValor (TNo *);
int AchaValor(TNo *, int);

int main(void)
{	TNo *raiz = NULL;
	int numero;
	
	while (1)
	{	printf("\nInforme o valor:\n"); scanf("%d", &numero);
		if (numero == -999) break;
		
		if (IncluiItem(&raiz, numero) == 1)
			printf ("\nErro de memoria");
	}
	printf("\n\nA arvore possui %d elementos:\n", ContaNos(raiz));
	ImprimeArvore(raiz, 0);
	
	printf ("\n\nA soma dos valores contidos na arvore e: %d", SomaNos(raiz));
	
	TNo *maior = MaiorValor(raiz);
	if (maior != NULL)
		printf ("\n\nO maior valor contido na arvore e: %d", maior->valor);
	
	TNo *menor = MenorValor(raiz);
	if (menor != NULL)
		printf ("\n\nO menor valor contido ma arvore e: %d", menor->valor);
	
	while (1)
	{
		printf ("\n\n\nInforme o valor a ser pesquisado: ");
		scanf ("%d", &numero);
		if (numero == -999) break;
		
		if (AchaValor(raiz, numero) == 1)
			printf ("\nValor nao encontrado");
		else
			printf ("\nValor encontrado");
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

void ImprimeArvore(TNo *r, int n)
{	int c;

	if (r != NULL)
	{	for (c = 0; c < n; c++) printf("\t");
		printf("%d\n", r->valor);
		ImprimeArvore(r->esq, n + 1);
		ImprimeArvore(r->dir, n + 1);
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

int SomaNos(TNo *r)
{
	if (r == NULL)
		return 0;
	else
		return r->valor + SomaNos(r->esq) + SomaNos(r->dir);
}

TNo *MaiorValor(TNo *r)
{
	if (r == NULL)
		return NULL;
	
	if (r->dir == NULL)
		return r;
	else
		return MaiorValor(r->dir);
}

TNo *MenorValor (TNo *r)
{
	if (r == NULL)
		return NULL;
	
	if (r->esq == NULL)
		return r;
	else
		return MenorValor(r->esq);
}

int AchaValor(TNo *r, int n)
{
	if (r == NULL)
		return 1;
	
	if (r->valor == n)
		return 0;
	else
		if (n <= r->valor)
			return AchaValor(r->esq, n);
		else
			return AchaValor(r->dir, n);
}