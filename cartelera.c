/*
 * cartelera.c
 *
 *  Created on: Apr 6, 2019
 *      Author: maarten
 */
#include "cartelera.h"
#include <stdio.h>

void imprimirCartelera(Cartelera cart)
{

}

Cartelera leerCartelera()
{
	Cartelera cart;
	FILE *f;
	char ch;
	int lonCharCine;
	int numPelis;
	int lonTitulo;
	int lonDescripcion;

	f = fopen("Cartelera.txt", "r");

	ch = getc(f);
	lonCharCine = ch - '0';

	cart.cine = malloc(sizeof(char)*lonCharCine);

	for(int i=0; i<lonCharCine; i++)
	{
		ch = getc(f);
		cart.cine[i] = ch;
	}

	ch = getc(f);
	numPelis = ch -'0';

	cart.numPelis = numPelis;

	cart.peliculas = malloc(sizeof(Pelicula)*numPelis);



	for(int i=0; i<numPelis; i++)
	{
		ch = getc(f);
		lonTitulo = ch -'0';
		cart.peliculas[i].titulo = malloc(sizeof(char)*lonTitulo);
		for(int j=0; j<lonTitulo; j++)
		{
			ch = getc(f);
			cart.peliculas[i].titulo[j] = ch;
		}

		ch = getc(f);
		lonDescripcion = ch -'0';
		cart.peliculas[i].descripcion = malloc(sizeof(char)*lonDescripcion);
		for(int j=0; j<lonDescripcion; j++)
		{
			ch = getc(f);
			cart.peliculas[i].descripcion[j] = ch;
		}
	}

	return cart;

}
