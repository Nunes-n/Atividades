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