/*
 * cartelera.c
 *
 *  Created on: Apr 6, 2019
 *      Author: maarten
 */
#include <stdlib.h>
#include "cartelera.h"
#include "gestor.h"
#include <stdio.h>
#include <string.h>
#define TAMANYO_tit 100
#define TAMANYO_descr 200

void imprimirCartelera(Cartelera cart)
{
	printf("\n");
	printf("Cine: %s\n",cart.cine);
	printf("--------------------------\n");

	for (int i =0; i<cart.numPelis;i++)
	{
		printf("Pelicula %i: ", i+1);
		imprimirPelicula(cart.peliculas[i]);

		printf("Sesiones:\n");
		for(int j=0; j<cart.peliculas[i].numSesiones; j++)
		{
			printf("Hora: %.2f, ", cart.peliculas[i].sesiones[j].hora);
			printf("Sitios libres: %i || ", cart.peliculas[i].sesiones[j].plazas);
		}
		printf("\n");
		printf("\n");

	}
	printf("\n");
}

void ficheroCartelera(Cartelera cart)
{
	FILE *f;
	char cine[100];

	strcpy(cine, cart.cine);
	for (int i = 0; i < strlen(cine); i++)
	{
		cine[i] = toupper(cine[i]);
	}
	strcat(cine, "Cartelera.txt");

	f = fopen(cine, "w+");

	char *cine2 = cart.cine;

	int lonCharCine = strlen(cine2);

	fprintf(f, cart.cine);
	fprintf(f, "\n");

	for(int i=0; i<cart.numPelis; i++)
	{
		fprintf(f, "%s", cart.peliculas[i].titulo);
		fprintf(f, "\n");
		fprintf(f, "%s", cart.peliculas[i].descripcion);
		fprintf(f, "\n");

		fprintf(f, "%i ", cart.peliculas[i].numSesiones);

		for(int j=0; j<cart.peliculas[i].numSesiones; j++)
		{
			fprintf(f, "%i ", cart.peliculas[i].sesiones[j].plazas);
			fprintf(f, "%lf ", cart.peliculas[i].sesiones[j].hora);
		}

		fprintf(f, "\n");
	}
	fclose(f);
}

Cartelera leerCartelera(char *cine)
{
	Cartelera cart;
	FILE *f;
	char fichero[100];
	int numPelis = 0;

	strcpy(fichero, cine);
	strcat(fichero, "Cartelera.txt");

	f = fopen(fichero, "r");

	cart.cine = malloc(sizeof(char)*TAMANYO_tit);

	numPelis = (lineasFichero(fichero)-1)/3;
	cart.numPelis = numPelis;

	cart.peliculas = malloc(sizeof(Pelicula)*numPelis);

	char buff[255];
	double hora=0.0;
	int plazas = 0;
	int numSesiones = 0;

	fscanf(f, " %[^\t\n]s", buff);
	strcpy(cart.cine, buff);

	for(int i=0; i<numPelis; i++)
	{
		cart.peliculas[i].titulo = malloc (sizeof(char)*TAMANYO_tit);
		fscanf(f, " %[^\t\n]s", buff);
		strcpy(cart.peliculas[i].titulo,buff);

		cart.peliculas[i].descripcion = malloc (sizeof(char)*TAMANYO_descr);
		fscanf(f, " %[^\t\n]s", buff);
		strcpy(cart.peliculas[i].descripcion,buff);

		fscanf(f, "%d", &numSesiones);

		cart.peliculas[i].numSesiones = numSesiones;

		cart.peliculas[i].sesiones = (Sesion*)malloc (sizeof(Sesion)*numSesiones);

		for(int j=0; j<numSesiones;j++)
		{
			fscanf(f, "%i", &plazas);
			fscanf(f, "%lf", &hora);
			cart.peliculas[i].sesiones[j].plazas = plazas;
			cart.peliculas[i].sesiones[j].hora = hora;
		}
	}
	return cart;
}

void anyadirPelicula(Cartelera *cartelera, Pelicula peli)
{

	int aux =0;
	int aux2 = cartelera->numPelis;
	aux = cartelera->numPelis+1;

	Pelicula *more_peliculas = realloc(cartelera->peliculas, aux*sizeof(Pelicula));
	cartelera->numPelis = cartelera->numPelis+1;

	for(int i = 0; i<cartelera->numPelis; i++)
	{
		if (i==aux2)
		{

			//cartelera->peliculas[i] = malloc(sizeof(Pelicula));
			more_peliculas[i].titulo = malloc(sizeof(char)*TAMANYO_tit);
			more_peliculas[i].descripcion = malloc(sizeof(char)*TAMANYO_descr);
			strcpy(more_peliculas[i].titulo, peli.titulo);
			strcpy(more_peliculas[i].descripcion, peli.descripcion);
			more_peliculas[i].sesiones = malloc(sizeof(Sesion)*peli.numSesiones);
			more_peliculas[i].numSesiones = peli.numSesiones;
			for(int j=0; j<peli.numSesiones; j++)
			{
				more_peliculas[i].sesiones[j].hora=peli.sesiones[j].hora;
				more_peliculas[i].sesiones[j].plazas=peli.sesiones[j].plazas;

			}
		}
	}

	cartelera->peliculas = more_peliculas;


	ficheroCartelera(*cartelera);

	printf("La pelicula se ha anyadido a la cartelera\n");
	free(more_peliculas);
	more_peliculas=NULL;

}


void ficheroCarteleraBorrado(Cartelera cart, int index)
{
	FILE *f;
	char cine[100];

	strcpy(cine, cart.cine);
	for (int i = 0; i < strlen(cine); i++)
	{
		cine[i] = toupper(cine[i]);
	}
	strcat(cine, "Cartelera.txt");

	f = fopen(cine, "w+");

	char *cine2 = cart.cine;

	int lonCharCine = strlen(cine2);

	fprintf(f, cart.cine);
	fprintf(f, "\n");

	for(int i=0; i<cart.numPelis; i++)
	{
		if(i!=index)
		{
			fprintf(f, "%s", cart.peliculas[i].titulo);
			fprintf(f, "\n");
			fprintf(f, "%s", cart.peliculas[i].descripcion);
			fprintf(f, "\n");

			fprintf(f, "%i ", cart.peliculas[i].numSesiones);

			for(int j=0; j<cart.peliculas[i].numSesiones; j++)
			{
				fprintf(f, "%i ", cart.peliculas[i].sesiones[j].plazas);
				fprintf(f, "%lf ", cart.peliculas[i].sesiones[j].hora);
			}
			fprintf(f, "\n");
		}
	}

	fclose(f);
}

int lineasFichero(char *fichero)
{
    FILE *fileptr;
    int count_lines = 0;
    char filechar[40], chr;

    fileptr = fopen(fichero, "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
    fclose(fileptr); //close file.

    return count_lines;
}

