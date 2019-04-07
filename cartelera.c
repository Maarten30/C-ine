/*
 * cartelera.c
 *
 *  Created on: Apr 6, 2019
 *      Author: maarten
 */
#include "cartelera.h"
#include <stdio.h>
#include <string.h>

void imprimirCartelera(Cartelera cart)
{

}

void ficheroCartelera(Cartelera cart)
{
	FILE *f;
	char *cine;

	printf("Llega aqui2\n");

//	cine = cart.cine;
//	strcat(cine, "Cartelera.txt");

	printf("Llega aqui3\n");

	f = fopen("CarteleraUrbil.txt", "w+");

	char *cine2 = cart.cine;

	int lonCharCine = strlen(cine2);

	printf("Llega aqui4\n");

	fprintf(f, lonCharCine);
	fprintf(f, cart.cine);
	fprintf(f, cart.numPelis);
	int lonPeli = 0;

	printf("Llega aqui5\n");

	for(int i=0; i<cart.numPelis; i++)
	{

		lonPeli = strlen(cart.peliculas[i].titulo);
		fprintf(f, lonPeli);
		fprintf(f, "%s", cart.peliculas[i].titulo);

	}



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
