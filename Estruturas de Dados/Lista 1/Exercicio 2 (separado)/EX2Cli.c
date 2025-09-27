#include <stdio.h>
#include "EX2Hea.h"

TLista lista;

int main(void)
{
	char operacao = ' ';
	char op;
	char nome[26];
	float qtde;
	
	iniciaLista(&lista);
	
	while (operacao != '*')
	{
		printf ("Digite a operacao: ");
		scanf (" %c", &operacao);
		
		if (operacao == 'I' || operacao == 'i')
		{
			printf ("Digite o nome e quantidade do produto: ");
			scanf ("%s %f", nome, &qtde);
			if (IncluiItem(&lista, nome, qtde) == 1)
			{
				printf ("\nErro fatal: memoria insuficiente\n\n");
			}
			else
			{
				printf ("\nIncluiu %s\n\n", nome);
			}
		}
		else
			if (operacao == 'A' || operacao == 'a')
			{
				printf ("Digite o nome do produto: ");
				scanf ("%s", nome);
				int retorno = AtualizaItem(&lista, nome);
				if (retorno == 1)
				{
					printf ("\nItem nao encontrado\n\n");
				}
				else
				{
					if (retorno == 2)
						printf ("\nErro: %s ja foi comprado\n\n", nome);
					else
						printf ("\nComprou %s\n\n", nome);
				}
			}
			else
				if (operacao == 'X' || operacao == 'x')
				{
					printf ("Digite o nome do produto: ");
					scanf ("%s", nome);
					if (ExcluiItem(&lista, nome) == 1)
					{
						printf ("\nProduto nao encontrado\n");
					}
					else
					{
						printf ("\n%s foi excluido\n", nome);
					}
				}
				else
					if (operacao == 'P' || operacao == 'p')
					{
						printf ("Digite o tipo de impressao: ");
						scanf (" %c", &op);
						ImprimeLista (&lista, op);
					}
					else
					{
						if (operacao != '*')
							printf ("\nOperacao invalida\n\n");
					}
	}
	
	return 0;
}
