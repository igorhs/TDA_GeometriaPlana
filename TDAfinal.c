#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TDA.h"

int main()
{
	int Opcao;
	ponto a, b, c, d;
	struct poligono_plano poli;
	float Area, Comprimento, D;
	Linha EqA;
	printf("-------------Digite a operação:-------------\n\n");
	printf("1 - Distancia entre dois pontos\n");
	printf("2 - Comprimento de uma linha\n");
	printf("3 - Verificar se um poligono eh Valido\n");
	printf("4 - Determinar a area de um triangulo ou de um quadrilatero\n");
	printf("5 - Verificar se 3 pontos sao colineares\n");
	printf("6 - Verificar onde 2 retas se interceptam\n");
	printf("0 - Sair\n");
	
	scanf("%d", &Opcao);
	while(Opcao != 0)
	{
		switch (Opcao)
		{
			case 1:
				printf("Digite o ponto A:\n");
				scanf("%f %f", &a.x, &a.y);
				printf("Digite o ponto B:\n");
				scanf("%f %f", &b.x, &b.y);
				D = CalcDist( b, a);
				printf("\n\n%.2f\n\n", D);
				
				break;
			case 2:
				printf("Digite os valores de a, b e c da equação da reta: \n");
				scanf("%lf %lf %lf", &EqA.a, &EqA.b, &EqA.c);

				Comprimento = EquacaoRetaFinal(EqA);

				printf("Comprimento e: %.2f\n\n", Comprimento);
				break;
			case 3:
				ValidaPoligono(poli);
					
				break;
			case 4:
				printf("-----Digite a opcao-----\n");
				printf("1 - Triangulo\n");
				printf("2 - Quadrilatero\n");
				scanf("%d", &Opcao);
				if(Opcao == 1)
				{
					Area = calcAREAtri(poli);
					printf("Area do triangulo = %.2f\n\n", Area);
				}
				if(Opcao == 2)
				{
					printf("Digite o quadrilatero desejado:\n");
					printf("1 - Quadrado\n");
					printf("2 - Retangulo\n");
					printf("3 - Trapezio\n");
					scanf("%d", &Opcao);
					if(Opcao == 1)
					{
						printf("Digite o lado do Quadrado\n");
						scanf("%d", &poli.ValLado[1]);
						poli.ValLado[2] = 0;
						poli.ValLado[3] = 0;
						poli.ValLado[4] = 0;
						Area = calcAREAQuad(poli, Opcao);
						printf("Area do Quadrado: %.2f\n\n", Area);
					}
					if(Opcao == 2)
					{
						printf("Digite os lados do Retangulo\n");
						printf("Insira o Lado Maior:\n");
						scanf("%d", &poli.ValLado[1]);
						printf("Insira o Lado Menor:\n");
						scanf("%d", &poli.ValLado[2]);
						poli.ValLado[3] = 0;
						poli.ValLado[4] = 0;
						Area = calcAREAQuad(poli, Opcao);
						printf("Area do Retangulo: %.2f\n\n", Area);
					}
					if(Opcao == 3)
					{
						printf("Digite os lados do Trapezio\n");
						printf("Insira o Lado Maior:\n");
						scanf("%d", &poli.ValLado[1]);
						printf("Insira o Lado Menor:\n");
						scanf("%d", &poli.ValLado[2]);
						printf("Insira a Altura:\n");
						scanf("%d", &poli.ValLado[3]);
						poli.ValLado[4] = 0;
						Area = calcAREAQuad(poli, Opcao);
						printf("Area do Trapezio: %.2f\n\n", Area);
					}
					
				}
				break;
			case 5:
				printf("Digite o ponto A:\n");
				scanf("%f %f", &a.x, &a.y);	
				printf("Digite o ponto B:\n");
				scanf("%f %f", &b.x, &b.y);
				printf("Digite o ponto C:\n");
				scanf("%f %f", &c.x, &c.y);
	
				VerificaColinear(a, b, c);
				break;
			case 6:
				printf("Digite o primeiro ponto\n");
				scanf("%f %f", &a.x, &a.y);	
				printf("Digite o segundo ponto\n");
				scanf("%f %f", &b.x, &b.y);	
				printf("Digite o terceiro ponto\n");
				scanf("%f %f", &c.x, &c.y);	
				printf("Digite o quarto ponto\n");
				scanf("%f %f", &d.x, &d.y);
	
				Intercep(a, b, c, d);	
				break;
		}
		
		printf("-------------Digite a operação:-------------\n\n");
		printf("1 - Distancia entre dois pontos\n");
		printf("2 - Comprimento de uma linha\n");
		printf("3 - Verificar se e um poligono\n");
		printf("4 - Determinar a area do triangulo ou do quadrilatero\n");
		printf("5 - Verificar se 3 pontos sao colineares\n");
		printf("6 - Verificar onde 2 retas se interceptam\n");
		printf("0 - Sair\n");
		scanf("%d", &Opcao);
	}

	return 0;
}