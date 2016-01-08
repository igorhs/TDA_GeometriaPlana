#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {float x, y;} ponto;
typedef struct {double a;double b;double c;} Linha;
struct poligono_plano {int ValLado[5];};


float CalcDist( ponto p1, ponto p2);
float EquacaoRetaFinal (Linha);
void EquacaoRetaInicial (ponto A, ponto B);
void ValidaPoligono(struct poligono_plano P);
float calcAREAtri(struct poligono_plano poli);
float calcAREAQuad(struct poligono_plano poli, int Opcao);
void VerificaColinear (ponto A, ponto B, ponto C);
void Intercep (ponto A, ponto B, ponto C, ponto D);
//rotinas a mais...
float descobre_altura(int a, int b, int c, int tipo);