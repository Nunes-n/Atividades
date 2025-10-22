#include <stdio.h>
#include <math.h>

struct ponto
{
	float x;
	float y;
};
typedef struct ponto ponto;

ponto p1;
ponto p2;

void criaPonto(float, float, int *, int *);
void excluiPonto(ponto *);
int dizQuadrante (ponto);
void interpretaQuad(int);
float distancia(ponto, ponto);

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

void criaPonto(float valorX, float valorY, int *cont1, int *cont2)
{	
	if (*cont1 == 0) // vai criar o primeiro
	{
		p1.x = valorX;
		p1.y = valorY;
		*cont1 = 1;
	}
	else
	{
		if (*cont2 == 0) // ja existe um, vai criar o segundo
		{
			p2.x = valorX;
			p2.y = valorY;
			*cont2 = 1;
		}
		else // ja possui dois pontos
		{
			printf ("\nNumero maximo de pontos ja foi atingido");
		}
	}
}

void excluiPonto(ponto *p)
{
	p->x = 0;
	p->y = 0;
}

int dizQuadrante (ponto p)
{
	if (p.x == 0 && p.y == 0)
	{
		return 0;
	}
	if (p.x == 0 && p.y != 0)
	{
		return 6;
	}
	if (p.x != 0 && p.y == 0)
	{
		return 5;
	}
	
	if (p.x > 0 && p.y > 0)
	{
		return 1;
	}
	if (p.x < 0 && p.y > 0)
	{
		return 2;
	}
	if (p.x < 0 && p.y < 0)
	{
		return 3;
	}
	if (p.x > 0 && p.y < 0)
	{
		return 4;
	}
}

void interpretaQuad(int quadrante)
{
	if (quadrante == 0)
	{
		printf ("\nOrigem");
	}
	else
		if (quadrante == 6)
		{
			printf ("\nEixo x");
		}
		else
			if (quadrante == 5)
			{
				printf ("\nEixo y");
			}
			else
				printf ("\nQuadrante %d", quadrante);
}

float distancia(ponto p1, ponto p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}