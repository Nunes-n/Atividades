#include <stdio.h>
#include <string.h>
#define MAX 25

enum unidademedida
{
	UN,
	KG,
	LT,
	MT
};
typedef enum unidademedida uniMedida;

union quantidade
{
	int qtdeInteira;
	float qtdeReal;
};
typedef union quantidade qtde;

struct produto
{
	int codigo;
	char descricao[21];
	uniMedida unidade;
	qtde estoque;
	float precoUnitario;
};
typedef struct produto prod;

prod produtos[MAX];

int main(void)
{
	int n = 5;
	float precoTotal = 0.0;
	
	produtos[0].codigo = 1;
	strcpy(produtos[0].descricao, "salsicha");
	produtos[0].unidade = KG;
	produtos[0].estoque.qtdeReal = 10.5;
	produtos[0].precoUnitario = 10.9;
	
	produtos[1].codigo = 2;
	strcpy(produtos[1].descricao, "manteiga");
	produtos[1].unidade = UN;
	produtos[1].estoque.qtdeInteira = 25;
	produtos[1].precoUnitario = 6.0;
	
	produtos[2].codigo = 3;
	strcpy(produtos[2].descricao, "lasanha");
	produtos[2].unidade = UN;
	produtos[2].estoque.qtdeInteira = 15;
	produtos[2].precoUnitario = 9.0;
	
	produtos[3].codigo = 4;
	strcpy(produtos[3].descricao, "frango");
	produtos[3].unidade = KG;
	produtos[3].estoque.qtdeReal = 20.0;
	produtos[3].precoUnitario = 13.0;
	
	produtos[4].codigo = 5;
	strcpy(produtos[4].descricao, "suco de uva");
	produtos[4].unidade = LT;
	produtos[4].estoque.qtdeReal = 30.0;
	produtos[4].precoUnitario = 5.0;
	
	int codigo = 1;
	float qtdeVendida;
	
	while (codigo != 0)
	{
		printf ("Insira o codigo do produto (0 para encerrar): ");
		scanf ("%d", &codigo);
		
		if (codigo <= 0)
			break;
		
		int i = 0;
		while (i < n)
		{
			if (produtos[i].codigo == codigo) //achou
			{
				printf ("Produto: %s", produtos[i].descricao);
				printf ("\nInsira a quantidade: ");
				scanf ("%f", &qtdeVendida);
				
				if (produtos[i].unidade == UN)
				{
					if (qtdeVendida > produtos[i].estoque.qtdeInteira)
					{
						printf ("\nEstoque insuficiente");
						break;
					}
					else
					{
						precoTotal += (qtdeVendida * produtos[i].precoUnitario);
						produtos[i].estoque.qtdeInteira -= (int)qtdeVendida;
						break;
					}
				}
				else
				{
					if (qtdeVendida > produtos[i].estoque.qtdeReal)
					{
						printf ("\nEstoque insuficiente");
						break;
					}
					else
					{
						precoTotal += (qtdeVendida * produtos[i].precoUnitario);
						produtos[i].estoque.qtdeReal -= qtdeVendida;
						break;
					}
				}
			}
			else
			{
				if (i == n - 1) //nao achou
				{
					printf ("\nProduto nao encontrado");
				}
			}
			
			i += 1;
		}
	}
	
	printf ("\nPreco total da venda: %.2f", precoTotal);
	
	return 0;
}