#include <stdio.h>
#include <math.h>
#include "exercicio4header.h"

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