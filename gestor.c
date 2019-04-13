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

void menuGestor()
//el menuGestor creo que no deberia recibir una cartelera (opinion)
{
	char caracter;
	char caracter2;
	Pelicula peli;

	do
	{
		printf("Menu Gestor: \n");
		printf("1.- Editar cartelera\n2.- Crear cartelera\n");
		scanf(" %c", &caracter);
		printf("%c\n", caracter);
		if(caracter == '1')
		{
			printf("Elige el cine que quiera editar:\n");
			char *nombrecart;
			char *nombrecart2 = malloc(TAMANYO_tit*sizeof(char));
			nombrecart = malloc(TAMANYO_tit*sizeof(char));
			scanf("%s", nombrecart);
			strcpy(nombrecart2, nombrecart);
			for (int i = 0; i < strlen(nombrecart); i++)
			{
			    nombrecart[i] = toupper(nombrecart[i]);
			    nombrecart2[i] = toupper(nombrecart2[i]);
			}
			//toupper((unsigned char) *nombrecart);
			printf("%s", nombrecart);
			//strupr(nombrecart);
			//strupr(nombrecart2);
			strcat(nombrecart, "Cartelera.txt");
			int existe = exists(nombrecart);

			if (existe ==0)
			{
				printf("El cine introducido no existe, vuelva a introducirlo:\n");
				menuGestor();
			}
			else
			{
				Cartelera cartelerita = leerCartelera(nombrecart2);
				printf("1.- Anyadir pelicula \n2.- Retirar pelicula\n");
				scanf(" %c", &caracter2);
				printf("%c\n", caracter2);

				if(caracter2 == '1')
				{
					Pelicula peli1;
					char *cinema = malloc(TAMANYO_tit*sizeof(char));
					char *titulo=malloc(TAMANYO_tit*sizeof(char));
					char *descr = malloc(TAMANYO_descr*sizeof(char));
					fflush(stdin);



					printf("Inserte el nombre de la pelicula que desee anyadir\n");

					scanf(" %s", titulo);
					peli1.titulo = malloc((strlen(titulo)+1)*sizeof(char));
					peli1.titulo = strcpy(peli1.titulo, titulo);
					printf("El titulo que has introducido es: %s\n", titulo);


					fflush(stdin);

					printf("Inserte la descripcion de la pelicula %s\n", peli1.titulo);
					//fgets(descr,TAMANYO_descr,stdin);
					scanf(" %s", descr);

					peli1.descripcion = malloc((strlen(descr)+1)*sizeof(char));
					peli1.descripcion = strcpy(peli1.descripcion, descr);
					printf("La descripcion que has introducido es: %s\n", descr);

					anyadirPelicula(&cartelerita, peli1);
	//				anyadirPelicula(carte, peli);
				}
				else if (caracter2=='2')
				{
					Pelicula *PeliABorrar = malloc(1*sizeof(Pelicula));
//					imprimirCartelera(cart);
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
						//quitarPelicula(cart, *PeliABorrar);
					}
					else if (opcion == 'n')
					{
						menuGestor();
					}
			}

			}
		}
		else if(caracter == '2')
		{

			NuevaCartelera();

		}
	}
	while(caracter!='q');

}

void NuevaCartelera()
{

	Cartelera *cart = malloc(sizeof(Cartelera));

	char cine[TAMANYO_tit];
	char aux[TAMANYO_tit];
	printf("Introduzca el nombre del cine: \n");
	scanf("%s", aux);
	strcpy(cine,aux);
	int existe = exists(strcat(aux, "Cartelera.txt"));
	if (existe ==1)
	{
		printf("Esta cartelera ya existe.\n");
		menuGestor();
	}
	else
	{
		int numPelis = 0;
		printf("Introduzca el numero de peliculas que desea anyadir a la cartelera: \n");
		scanf("%i", &numPelis);

		cart->cine = malloc (sizeof(char)*TAMANYO_tit);
		strcpy(cart->cine, cine);



		cart->numPelis = numPelis;

		cart->peliculas = malloc(sizeof(Pelicula)*numPelis);



		char titulo[TAMANYO_tit];
		char desc[TAMANYO_descr];
		int longitud = 0;
		int longitud2 = 0;

		for(int i=0; i<cart->numPelis; i++)
		{

			printf("Introduzca el titulo de la pelicula: \n");
			scanf("%s", titulo);
			longitud = strlen(titulo);
			printf("%i\n", longitud);

			printf("Introduzca una breve descripcion sobre la pelicula: \n");
			scanf(" %[^\t\n]s", desc);
			longitud2 = strlen(desc);

			cart->peliculas[i].titulo= malloc (sizeof(char)*(longitud+1));
			cart->peliculas[i].descripcion = malloc (sizeof(char)*(longitud2+1));

			strcpy(cart->peliculas[i].titulo, titulo);
			strcpy(cart->peliculas[i].descripcion, desc);

		}

		ficheroCartelera(*cart);

	}

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

