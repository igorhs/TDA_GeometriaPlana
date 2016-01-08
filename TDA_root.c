#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TDA.h"

/*Calculo da distancia entre 2 pontos*/
float CalcDist(ponto p1, ponto p2)
{
	float D;
	
	D = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y), 2));
	
	return D;
}


void EquacaoRetaInicial(ponto A, ponto B)
{
	Linha LinA;
	if(A.x == B.x)
	{
		LinA.a = 1;
		LinA.b = 0;
		LinA.c = -A.x;
	}
	else
	{
		LinA.b = 1;
		LinA.a = -(A.y - B.y) / (A.x - B.x);
		LinA.c = -(LinA.a * A.x) - (LinA.b * A.y);
	}
	printf("A equacao e: %.2lfx+%.2lfy+%.2lf\n\n", LinA.a, LinA.b, LinA.c);
}


float EquacaoRetaFinal(Linha Reta)
{
	ponto A, B;
	float Comprimento;
	
	A.x = 0;
	A.y = (Reta.c * -1) / Reta.b;	
	B.x = (Reta.c * -1) / Reta.a;
	B.y = 0;
	
	Comprimento = CalcDist(A, B);
	
	return Comprimento;	
}

/*Validação de poligono com 4 ou 3 lados*/
void ValidaPoligono(struct poligono_plano poli)
{
	int a, b, c, d;
	
	printf("Digite o numero de lados do poligono\n");
	scanf(" %d", &poli.ValLado[0]);
	printf("Digite os lados do poligono:\n");
	if(poli.ValLado[0] == 3)
	{
		scanf("%d %d %d", &poli.ValLado[1], &poli.ValLado[2], &poli.ValLado[3]);
		
		a = poli.ValLado[1];
		b = poli.ValLado[2];
		c = poli.ValLado[3];
		poli.ValLado[4] = 0;
		if (a < b + c && b < c + a && c < a + b)
			printf(" POLIGONO: TRIANGULO\n POLIGONO VALIDO\n");
		else
		{
			printf("POLIGONO : TRIANGULO\n POLIGONO INVALIDO\n");
			a = 0;
			b = 0;
			c = 0;
		}
			
	}
	if(poli.ValLado[0] == 4)
	{
		
		scanf("%d %d %d %d", &poli.ValLado[1], &poli.ValLado[2], &poli.ValLado[3], &poli.ValLado[4]);
		
		a = poli.ValLado[1];
		b = poli.ValLado[2];
		c = poli.ValLado[3];
		d = poli.ValLado[4];
		
		if (a < b + c + d && b < a + c + d && c < a + b + d && d < a + b + c)
			printf("POLIGONO: QUADRILATERO\n POLIGONO VALIDO\n");
		else
		{
			printf("POLIGONO: QUADRILATERO\n POLIGONO INVALIDO\n");
			a = 0;
			b = 0;
			c = 0;
			d = 0;
		}
	}
}

/*Calculo da Area de um triangulo*/
float calcAREAtri(struct poligono_plano poli)
{
	int a,b,c;
	float area,altura;
	int tipo;
	
	a = poli.ValLado[1];
	b = poli.ValLado[2];
	c = poli.ValLado[3];
	
	printf("Digite os lados de um triangulo valido:\n");
	scanf("%d %d %d",&a,&b,&c);
	
	if((a == b) && (b == c))
	{
		tipo = 1;
		printf("Triangulo equilatero.\n");
		altura = descobre_altura(a,b,c,tipo);
		area = (a * altura) / 2;
	}
	else if((a == b) || (a == c) || (b == c))
	{
		tipo = 2;
		printf("Triangulo isosceles.\n");
		altura = descobre_altura(a,b,c,tipo);
		if(a == b)
		{
		area = (c * altura) / 2;
		}
		else if(a == c)
		{
			area = (b * altura) / 2;
		}
		else
		{
			area = (a * altura) / 2;
		}
	}
	else
	{
		tipo = 3;
		printf("Triangulo escaleno.\n");
		altura = descobre_altura(a,b,c,tipo);
		area = altura; 
	}
	return area;
}

/*Descobre a altura de triangulos*/
float descobre_altura(int a, int b, int c, int tipo)
{
	float altura;
	int perimetro;
	
	if(tipo == 1)
	{
		altura = (a * sqrt(3)) / 2;
	}
	else if(tipo == 2)
	{
		if(a == b)
		{
			altura = sqrt(pow(a,2) - pow(c,2) / 4);
		}
		else if(a == c)
		{
			altura = sqrt(pow(a,2) - pow(b,2) / 4);
		}
		else
		{
			altura = sqrt(pow(b,2) - pow(a,2) / 4);
		}
	}
	else
	{
		perimetro = a + b + c;
		altura = sqrt(perimetro * (perimetro - a) * (perimetro - b) * (perimetro - c));
	}
	
	return altura;
}
/*Calculo da area de um quadrilatero*/
float calcAREAQuad(struct poligono_plano poli, int Opcao)
{
	int a, b, c, d;
	float area;
	
	a = poli.ValLado[1];
	b = poli.ValLado[2];
	c = poli.ValLado[3];
	d = poli.ValLado[4];
	
	if(Opcao == 1)
		area = a*a;
	if(Opcao == 2)
		area = a*b;
	if(Opcao == 3)
		area = ((a+b)*c)/2;
	
	return area;

}

/*Verifica se 3 pontos sao colineares*/
void VerificaColinear (ponto A, ponto B, ponto C)
{
	float Col;
	
	Col = (A.x * B.y * 1) + (A.y * 1 * C.x) + (1 * B.x * C.y) - (1 * B.y * C.x) - (A.x * 1 * C.y) - (A.y * B.x * 1);
	if(Col == 0)
		printf("Sao colineares\n\n");
	else 
		printf("Nao sao colineares\n\n");
}
/*Verifica se 2 retas se interceptam*/
void Intercep (ponto A, ponto B, ponto C, ponto D)
{
	float result, result2;
	ponto Cruza;
	
	result = ((D.x - C.x)*(A.y - C.y) - (D.y - C.y)*(A.x - C.x)) / ((D.y - C.y)*(B.x - A.x) - (D.x - C.x)*(B.y - A.y));
	result2 = ((B.x - A.x)*(A.y - C.y) - (B.y - A.y)*(A.x - C.x)) / ((D.y - C.y)*(B.x - A.x) - (D.x - C.x)*(B.y - A.y));
	
	if(((D.y - C.y)*(B.x - A.x) - (D.x - C.x)*(B.y - A.y)) == 0 || ((D.y - C.y)*(B.x - A.x) - (D.x - C.x)*(B.y - A.y)) == 0)
	printf("Sao paralelas\n\n");
	else
	{
		Cruza.x = A.x + result*(B.x - A.x);
		Cruza.y = A.y + result*(B.y - A.y);
		printf("\nSe interceptam no ponto P(%.2f, %.2f)\n\n", Cruza.x, Cruza.y);
	}


}
