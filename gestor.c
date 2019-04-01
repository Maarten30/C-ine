/*
 * gestor.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */

#include <stdio.h>
#include "gestor.h"

void menuGestor()
{
	char caracter;

	do
	{
		printf("Menu Gestor: \n");
		printf("1.- Añadir Pelicula\n2.- Retirar Pelicula\n");
		scanf(" %c", &caracter);
		printf("%c\n", caracter);
		if(caracter == '1')
		{
			añadirPelicula();
		}

	}while(caracter!='q');

}

void añadirPelicula()
{
	printf("La pelicula se ha añadido\n");
}

void quitarPelicula()
{

}
