/*
 * main.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */
#include <stdio.h>
#include "gestor.h"


int main(void)
{
	printf("Hola mundo\n");

	char c = '5';

	int x = c - '0';

	printf("El numero es %i\n", x);


	char caracter;

	do
	{
		printf("Menu Principal: \n");
		printf("1.- Cartelera\n2.- Compra de entradas\n");
		scanf(" %c", &caracter);
		printf("%c\n", caracter);


		if(caracter == 'g')
		{
			menuGestor();
		}


	}while(caracter!='q');

}



