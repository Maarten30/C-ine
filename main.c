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


int main(void)
{
	printf("Hola mundo\n");

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

		if(caracter == 'g')
		{
			menuGestor(cart);
		}
		else if(caracter == '1')
		{

			leerCartelera();
			//imprimirCartelera(cart);
		}else if(caracter == '2')
		{
			int lineas = lineasFichero();
			printf("El numero de lineas del fichero es: %i", lineas);

		}


	}while(caracter!='q');

}





