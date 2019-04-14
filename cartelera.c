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
	for (int i =0; i<cart.numPelis;i++)
	{
		printf("Cine: %s, Pelicula: %s, Descripcion: %s\n", cart.cine, (cart.peliculas[i]).titulo, (cart.peliculas[i]).descripcion);

		printf("Numero de sesiones en metodo es: %i\n", cart.peliculas[i].numSesiones);
		printf("Sesiones:\n");
		for(int j=0; j<cart.peliculas[i].numSesiones; j++)
		{
			printf("Hora: %lf\n", cart.peliculas[i].sesiones[j].hora);
		}
	}
}

void ficheroCartelera(Cartelera cart)
{
	FILE *f;
	char cine[100];

	printf("Llega aqui2\n");



	strcpy(cine, cart.cine);
	for (int i = 0; i < strlen(cine); i++)
	{
		cine[i] = toupper(cine[i]);
	}
	//strupr(cine);
	strcat(cine, "Cartelera.txt");

	printf("Llega aqui3\n");

	f = fopen(cine, "w+");

	char *cine2 = cart.cine;

	int lonCharCine = strlen(cine2);

	printf("Llega aqui4\n");

//	fprintf(f, lonCharCine);
	fprintf(f, cart.cine);
	fprintf(f, "\n");
//	fprintf(f, cart.numPelis);
//	int lonPeli = 0;


	for(int i=0; i<cart.numPelis; i++)
	{

		fprintf(f, "%s", cart.peliculas[i].titulo);
		fprintf(f, "\n");
		fprintf(f, "%s", cart.peliculas[i].descripcion);
		fprintf(f, "\n");

		fprintf(f, "%i ", cart.peliculas[i].numSesiones);

		for(int j=0; j<cart.peliculas[i].numSesiones; j++)
		{

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
	char ch;
	char fichero[100];
	//int lonCharCine;
	int numPelis = 0;
	int contador = 0;

//	for (int i = 0; i < strlen(cine); i++)
//	{
//		cine[i] = toupper(cine[i]);
//	}


	strcpy(fichero, cine);
	strcat(fichero, "Cartelera.txt");

	int boolean = exists(fichero);

	printf("El resultado es: %i\n", boolean);

	printf("el  nombre de la cartelera es: %s\n", fichero);

	f = fopen(fichero, "r");

	//lonCharCine = ch - '0';

	cart.cine = malloc(sizeof(char)*TAMANYO_tit);

	numPelis = (lineasFichero(fichero)-1)/3;
	printf("el numero de pelis es %i\n", numPelis);
	cart.numPelis = numPelis;

	cart.peliculas = malloc(sizeof(Pelicula)*numPelis);

	char buff[255];
	double hora=0.0;
	int numSesiones = 0;
	char c;

	fscanf(f, "%s", buff);
	strcpy(cart.cine, buff);

	for(int i=0; i<numPelis; i++)
	{
		printf("aquiiii\n");
		cart.peliculas[i].titulo = malloc (sizeof(char)*TAMANYO_tit);
		fscanf(f, " %[^\t\n]s", buff);
		strcpy(cart.peliculas[i].titulo,buff);

		printf("aquiiii2\n");
		cart.peliculas[i].descripcion = malloc (sizeof(char)*TAMANYO_descr);
		fscanf(f, " %[^\t\n]s", buff);
		printf("%s\n", buff);
		strcpy(cart.peliculas[i].descripcion,buff);



//		c = fgetc(f);
//		printf("EL char es: %c", c);
//		int x = c - '0';

		fscanf(f, "%d", &numSesiones);


		cart.peliculas[i].numSesiones = numSesiones;

		printf("El numero de sesioncitas es: %i\n", numSesiones);
		cart.peliculas[i].sesiones = (Sesion*)malloc (sizeof(Sesion)*numSesiones);

		for(int j=0; j<numSesiones;j++)
		{
			fscanf(f, "%lf", &hora);
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
		}
	}


	cartelera->peliculas = more_peliculas;


	ficheroCartelera(*cartelera);



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
    printf("There are %d lines in in a file\n", count_lines);

    return count_lines;
}

