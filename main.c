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
		printf("1.- Ver cartelera\n2.- Compra de entradas\n3.- Pulse 'g' si eres gestor\n4.- Pulse 'q' para salir\n");
		scanf(" %c", &caracter);

		if(caracter == 'g' || caracter == 'G')
		{
			menuGestor();
		}
		else if(caracter == '1')
		{
			char *cine = malloc(TAMANYO_titulo*sizeof(char));
			char *cine2 = malloc(TAMANYO_titulo*sizeof(char));

			printf("Elija el cine del que desea ver la cartelera:\n");
			scanf("%s", cine);

			strcpy(cine2, cine);

			for (int i = 0; i < strlen(cine); i++)
			{
				cine[i] = toupper(cine[i]);
			}

			strcat(cine, "Cartelera.txt");
			int existe = exists(cine);

			if(existe == 0)
			{
				printf("El cine introducido no existe, vuelva a intentarlo\n");
			}
			else
			{
				Cartelera cartel = leerCartelera(cine2);
				imprimirCartelera(cartel);
			}
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
	char *nombrecart2 = malloc(TAMANYO_titulo*sizeof(char));

	printf("Elija el cine:\n");
	scanf("%s", nombrecart);

	strcpy(nombrecart2, nombrecart);

	for (int i = 0; i < strlen(nombrecart); i++)
	{
	    nombrecart[i] = toupper(nombrecart[i]);
	}

	strcat(nombrecart, "Cartelera.txt");
	int existe = exists(nombrecart);

	if (existe ==0)
	{
		printf("El cine introducido no existe, vuelva a introducirlo:\n");
		comprarEntradas();
	}
	else
	{
		Cartelera cart = leerCartelera(nombrecart2);

		int indice=0;
		int indSesion=-1;
		int numEntradas=0;
		double hora = 0.0;

		printf("Escoja el titulo de la pelicula que desea ver: \n");

		for(int i=0; i<cart.numPelis; i++)
		{
			printf("Titulo: %s\n", cart.peliculas[i].titulo);
		}

		char *titulo = malloc(sizeof(char)*TAMANYO_titulo);
		scanf(" %[^\t\n]s", titulo);

		for (int i = 0; i < strlen(titulo); i++)
		{
			titulo[i] = toupper(titulo[i]);
		}
		char *titulo2= malloc(sizeof(char)*TAMANYO_titulo);

		for(int i=0; i<cart.numPelis; i++)
		{
			strcpy(titulo2, cart.peliculas[i].titulo);
			for (int j = 0; j < strlen(titulo2); j++)
			{
				titulo2[j] = toupper(titulo2[j]);
			}
			if(strcmp(titulo, titulo2) == 0)
			{
				indice=i;
				break;
			}
		}
		do
		{
			for(int j=0; j<cart.peliculas[indice].numSesiones; j++)
			{
				printf("Hora: %.2f || ", cart.peliculas[indice].sesiones[j].hora);
				printf("Sitios libres: %i\n", cart.peliculas[indice].sesiones[j].plazas);
			}
			printf("Escoja la hora a la que desea ver la pelicula: \n");
					scanf("%lf", &hora);

					for(int j=0; j<cart.peliculas[indice].numSesiones; j++)
					{
						if(hora == cart.peliculas[indice].sesiones[j].hora)
						{
							indSesion = j;
						}
					}
			if(indSesion==-1)
			{
				printf("Escoja un horario valido:\n");
			}
		}while(indSesion == -1);


		do
		{
			printf("Introduzca el numero de entradas que desea comprar:\n ");
			scanf("%i", &numEntradas);
			if(numEntradas<=0)
			{
				printf("El numero de entradas debe ser superior a 0\n");
			}
			if(numEntradas<=cart.peliculas[indice].sesiones[indSesion].plazas && numEntradas>0)
			{
				cart.peliculas[indice].sesiones[indSesion].plazas = cart.peliculas[indice].sesiones[indSesion].plazas-numEntradas;
				printf("La compra se ha realizado correctamente\n");
			}
			if(numEntradas>cart.peliculas[indice].sesiones[indSesion].plazas)
			{
				printf("La plazas disponibles son unicamente de: %i\n", cart.peliculas[indice].sesiones[indSesion].plazas);
			}
		}while(numEntradas<=0 || numEntradas>cart.peliculas[indice].sesiones[indSesion].plazas);

		ficheroCartelera(cart);

	}
}
