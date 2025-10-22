#include <stdio.h>
#include "exercicio4header.h"

int main(void)
{
	float x, y;
	char op;
	int cont1 = 0;
	int cont2 = 0;
	int ponto;
	int quad;
	
	while (1)
	{
		printf ("\nC - criar ponto (max: 2)");
		printf ("\nX - excluir ponto");
		printf ("\nQ - dizer o quadrante");
		printf ("\nD - calcular a distancia entre dois pontos");
		printf ("\nZ - encerrar\n\n");
		
		scanf (" %c", &op);
		
		if (op == 'c' || op == 'C')
		{	
			printf ("\nDigite o valor de x: ");
			scanf ("%f", &x);
			printf ("\nDigite o valor de y: ");
			scanf ("%f", &y);
			
			criaPonto(x, y, &cont1, &cont2);
		}
		else
			if (op == 'x' || op == 'X')
			{
				if (cont1 == 0 && cont2 == 0)
					printf ("\nNao criou nenhum ponto ainda");
				else
					printf ("\nQual ponto deseja excluir? (1 ou 2)");
					scanf ("%d", &ponto);
					if (ponto == 1 && cont1 == 1)
					{
						excluiPonto(&p1);
						cont1 = 0;
					}
					else
						if (ponto == 2 && cont2 == 1)
						{
							excluiPonto(&p2);
							cont2 = 0;
						}
						else
							printf ("\nValor Invalido");
			}
			else
				if (op == 'q' || op == 'Q')
				{
					printf ("\nQual ponto deseja saber?");
					scanf ("%d", &ponto);
					
					if (ponto == 1 && cont1 == 1)
					{
						quad = dizQuadrante(p1);
						interpretaQuad(quad);
					}
					else
					{
						if (ponto == 2 && cont2 == 1)
						{
							quad = dizQuadrante(p2);
							interpretaQuad(quad);
						}
						else
						{
							printf ("\nPonto invalido");
						}
					}
				}
				else
					if (op == 'd' || op == 'D')
					{
						if ((cont1 + cont2) < 2)
						{
							printf ("\nNao possui dois pontos para comparar");
						}
						else
						{
							printf ("\nDistancia: %.2f", distancia(p1, p2));
						}
					}
					else
						if (op == 'z' || op == 'Z')
						{
							break;
						}
						else
						{
							printf ("\nOperacao invalida");
						}
	}
	
	return 0;
}