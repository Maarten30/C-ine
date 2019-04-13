/*
 * main.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */
#include <stdio.h>
#include <stdlib.h>
#include "gestor.h"
#include "cartelera.h"

#define TAMANYO_descr 200
#define TAMANYO_titulo 100



int main(void)
{

//	char c = '5';
//
//	int x = c - '0';
//
//	printf("El numero es %i\n", x);

	Cartelera cart;

	cart.cine = "urbil";
	cart.numPelis = 2;

	cart.peliculas = malloc (sizeof(Pelicula)*2);

	cart.peliculas[0].titulo = "Interstellar";
	cart.peliculas[0].descripcion = "Va de estrellas";
	cart.peliculas[1].titulo = "Bambi";
	cart.peliculas[1].descripcion = "Va de un ciervo";

	printf("Llega aqui\n");
	printf("%s\n", cart.peliculas[0].titulo);

//	ficheroCartelera(cart);

	char caracter;

	do
	{
		printf("\nMenu Principal: \n");
		printf("1.- Cartelera\n2.- Compra de entradas\n");
		scanf(" %c", &caracter);
		printf("%c\n", caracter);

		if(caracter == 'g' || caracter == 'G')
		{
			menuGestor();
		}
		else if(caracter == '1')
		{

			Cartelera cartel;
			cartel = leerCartelera("GML");

			Pelicula *Lora=(Pelicula*)malloc(sizeof(Pelicula));
			Lora->descripcion=malloc(TAMANYO_descr*sizeof(char));
			Lora -> titulo = malloc(TAMANYO_titulo*sizeof(char));
			Lora->descripcion = "porseaca";
			Lora->titulo = "Lora";
			anyadirPelicula(&cartel, *Lora);
			imprimirCartelera(cartel);

		}else if(caracter == '2')
		{
			int lineas = lineasFichero("MadridCartelera.txt");
			printf("El numero de lineas del fichero es: %i", lineas);

		}


	}while(caracter!='q');

}





