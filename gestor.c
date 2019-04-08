/*
 * gestor.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include"cartelera.h"
#include "gestor.h"

#define TAMANYO_tit 100
#define TAMANYO_descr 200

void menuGestor(Cartelera *cart)
{
	char caracter;
	Pelicula peli;

	do
	{
		printf("Menu Gestor: \n");
		printf("1.- Anyadir Pelicula\n2.- Retirar Pelicula\n");
		scanf(" %c", &caracter);
		printf("%c\n", caracter);
		if(caracter == '1')
		{
			char *titulo=malloc(TAMANYO_tit*sizeof(char));
			fflush(stdin);

			printf("Inserte el nombre de la pelicula que desee anyadir\n");
			fgets(titulo,TAMANYO_tit,stdin);

			peli.titulo = malloc((strlen(titulo)+1)*sizeof(char));
			peli.titulo = strcpy(peli.titulo, titulo);
			printf("El titulo que has introducido es: %s", titulo);

			char *descr = malloc(TAMANYO_descr*sizeof(char));
			fflush(stdin);

			printf("Inserte la descripcion de la pelicula %s\n", peli.titulo);
			fgets(descr,TAMANYO_descr,stdin);

			peli.descripcion = malloc((strlen(descr)+1)*sizeof(char));
			peli.descripcion = strcpy(peli.descripcion, descr);
			printf("La descripcion que has introducido es: %s", descr);
			anyadirPelicula(cart,peli);
		}
		else if(caracter == '2')
		{
			Pelicula *PeliABorrar = malloc(1*sizeof(Pelicula));
//			imprimirCartelera(cart);
			printf("Introduce el titulo de la pel�cula que quieres borrar:\n");

			char *tituloABorrar=malloc(TAMANYO_tit*sizeof(char));
			fflush(stdin);
			fgets(tituloABorrar,TAMANYO_tit,stdin);

			PeliABorrar->descripcion = malloc((strlen(tituloABorrar)+1)*sizeof(char));
			PeliABorrar->descripcion = strcpy(peli.descripcion, tituloABorrar);

			printf("�Est�s seguro? Pulsa 's'= SI // 'n'=NO: %s");
			char opcion;
			scanf("%c", opcion);
			if (opcion == 's')
			{
				quitarPelicula(cart, &PeliABorrar);
			}
			else if (opcion == 'n')
			{
				menuGestor(cart);
			}
		}

	}while(caracter!='q');

}

void anyadirPelicula(Cartelera *cartelera, Pelicula peli)
{
	int numPelis2 = cartelera->numPelis+1;
	Cartelera *carte = (Cartelera*)malloc(numPelis2* sizeof(Cartelera));

	for(int i = 0; i<numPelis2;i++)
	{
		if (i==numPelis2-1)
		{
			(carte->peliculas[i]).titulo = peli.titulo;
			(carte->peliculas[i]).descripcion = peli.descripcion;
		}
		else
		{
			(carte->peliculas[i]).titulo = (cartelera->peliculas[i]).titulo;
			(carte->peliculas[i]).descripcion = (cartelera->peliculas[i]).descripcion;
		}
	}

	cartelera->numPelis=numPelis2;
	cartelera->peliculas = carte->peliculas;
	printf("La pelicula se ha anyadido a la cartelera\n");

}


void quitarPelicula(Cartelera *cartelera, Pelicula PeliABorrar)
{
	int numPelis2 = cartelera->numPelis +1;
	Cartelera *carte = (Cartelera*)malloc(numPelis2* sizeof(Cartelera));

	for(int i=0; i<numPelis2; i++)
	{
		if(strcpy(PeliABorrar.titulo, (carte->peliculas[i]).titulo))
		{
			(carte->peliculas[i]).titulo = (carte->peliculas[i-1].titulo);
			(carte->peliculas[i]).descripcion = (carte->peliculas[i-1]).descripcion;
			numPelis2--;
		}
	}

	cartelera->numPelis = numPelis2;
	printf("La pelicula se ha borrado de la cartelera\n");
}
