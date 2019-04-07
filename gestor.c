/*
 * gestor.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */

#include <stdio.h>
#include "pelicula.h"
#include"cartelera.h"
#include "gestor.h"


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
			printf("Inserte el nombre de la pelicula que desee anyadir\n");
			scanf(" %s", &peli.titulo);
			printf("Inserte la descripcion de la pelicula %s\n", peli.titulo);
			scanf(" %s", &peli.descripcion);
			anyadirPelicula(cart,peli);
		}
		else if(caracter == '2')
		{
			quitarPelicula();
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
			carte->peliculas[i].titulo = peli.titulo;
			carte->peliculas[i].descripcion = peli.descripcion;
		}
		else
		{
			carte->peliculas[i].titulo = cartelera->peliculas[i].titulo;
			carte->peliculas[i].descripcion = cartelera->peliculas[i].descripcion;
		}
	}

	cartelera->numPelis=numPelis2;
	cartelera->peliculas = carte->peliculas;
	printf("La pelicula se ha anyadido a la cartelera\n");

}

void quitarPelicula()
{

}
