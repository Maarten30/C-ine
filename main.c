/*
 * main.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestor.h"
#include "cartelera.h"

#define TAMANYO_descr 200
#define TAMANYO_titulo 100

void comprarEntradas();

int main(void)
{
	char caracter;

	do
	{
		printf("Menu Principal: \n");
		printf("1.- Cartelera\n2.- Compra de entradas\n3.- Pulse 'g' si eres gestor");
		scanf(" %c", &caracter);
		printf("%c\n", caracter);

		if(caracter == 'g' || caracter == 'G')
		{
			menuGestor();
		}
		else if(caracter == '1')
		{
			char *cine = malloc(TAMANYO_titulo*sizeof(char));
			printf("Elija el cine del que desea ver la cartelera:\n");
			scanf("%s", cine);

			Cartelera cartel;
			for (int i = 0; i < strlen(cine); i++)
			{
				cine[i] = toupper(cine[i]);
			}

			printf("EL nombre del cine es: %s\n", cine);
			cartel = leerCartelera(cine);

			imprimirCartelera(cartel);

		}
		else if(caracter == '2')
		{
			comprarEntradas();
		}

	}
	while(caracter!='q');
}

void comprarEntradas()
{
	char *nombrecart = malloc(TAMANYO_titulo*sizeof(char));
	printf("Elija el cine:\n");
	scanf("%s", nombrecart);
	printf("%s", nombrecart);

	for (int i = 0; i < strlen(nombrecart); i++)
	{
	    nombrecart[i] = toupper(nombrecart[i]);
	}

	strcat(nombrecart, "Cartelera.txt");
	int existe = exists(nombrecart);
	Cartelera cart = leerCartelera(nombrecart);

	if (existe ==0)
	{
		printf("El cine introducido no existe, vuelva a introducirlo:\n");
		comprarEntradas();
	}
	else
	{
		char *nombrePeli = malloc(TAMANYO_titulo*sizeof(char));
		imprimirCartelera(cart);
		printf("Elija la pelicula:\n ");
		for(int i=0; i<cart.numPelis; i++)
		{
			printf("%s\n", cart.peliculas[i].titulo);
		}
		scanf("%s", nombrePeli);
		printf("¿Esta seguro de que quiere comprarla?\nS(Si)\nN(No)");
		char c;
		scanf("%c", &c);
		if(c=='S'|| c=='s')
		{
			printf("Compra realizada");
		}
		else if(c=='N' || c=='n')
		{
			printf("Operacion cancelada");
			comprarEntradas();
		}

	}
}




