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
#include "cartelera.h"
#include "gestor.h"

#define TAMANYO_tit 100
#define TAMANYO_descr 200

void menuGestor(Cartelera *cart)
//el menuGestor creo que no deberia recibir una cartelera (opinion)
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
			printf("Introduce el titulo de la pelicula que quieres borrar:\n");

			char *tituloABorrar=malloc(TAMANYO_tit*sizeof(char));
			fflush(stdin);
			fgets(tituloABorrar,TAMANYO_tit,stdin);

			PeliABorrar->descripcion = malloc((strlen(tituloABorrar)+1)*sizeof(char));
			PeliABorrar->descripcion = strcpy(peli.descripcion, tituloABorrar);

			printf("Estas seguro? Pulsa 's'= SI // 'n'=NO: %s");
			char opcion;
			scanf("%c", opcion);
			if (opcion == 's')
			{
				quitarPelicula(cart, *PeliABorrar);
			}
			else if (opcion == 'n')
			{
				menuGestor(cart);
			}
		}

	}while(caracter!='q');

}

void NuevaCartelera()
{
	Cartelera cart;

	char *cine;
	printf("Introduzca el nombre del cine: \n");
	scanf("%s", cine);

	int numPelis = 0;
	printf("Introduzca el numero de peliculas que desea anyadir a la cartelera: \n");
	scanf("%i", numPelis);

	cart.cine = cine;
	cart.numPelis = numPelis;

	for(int i=0; i<cart.numPelis; i++)
	{
		char *titulo;
		printf("Introduzca el titulo de la pelicula: \n");
		scanf("%s", titulo);

		char *desc;
		printf("Introduzca una breve descripcion sobre la pelicula: \n");
		scanf("%s", desc);

		cart.peliculas[i].titulo = titulo;
		cart.peliculas[i].descripcion = desc;

	}

	ficheroCartelera(cart);

}

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

