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
		printf("1.- Editar cartelera\n2.- Crear cartelera\n3.- Pulse 'q' para volver a menu principal\n");
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
					int sesiones = 0;
					double hora = 0.0;
					char *cinema = malloc(TAMANYO_tit*sizeof(char));
					char *titulo=malloc(TAMANYO_tit*sizeof(char));
					char *descr = malloc(TAMANYO_descr*sizeof(char));
					fflush(stdin);



					printf("Inserte el nombre de la pelicula que desee anyadir\n");

					scanf(" %[^\t\n]s", titulo);
					peli1.titulo = malloc((strlen(titulo)+1)*sizeof(char));
					peli1.titulo = strcpy(peli1.titulo, titulo);
					printf("El titulo que has introducido es: %s\n", titulo);


					fflush(stdin);

					printf("Inserte la descripcion de la pelicula %s\n", peli1.titulo);
					//fgets(descr,TAMANYO_descr,stdin);
					scanf(" %[^\t\n]s", descr);

					peli1.descripcion = malloc((strlen(descr)+1)*sizeof(char));
					peli1.descripcion = strcpy(peli1.descripcion, descr);
					printf("La descripcion que has introducido es: %s\n", descr);

					printf("Cuantas sesiones diarias quiere tener de la pelicula %s?\n", peli1.titulo);
					scanf("%i", &sesiones);

					peli1.sesiones = malloc(sizeof(Sesion)*sesiones);
					peli1.numSesiones = sesiones;

					for(int i=0; i<sesiones; i++)
					{
						printf("Introduzca la hora de la sesion %i:\n", i);
						scanf("%lf", &hora);
						printf("Dentro del for la hora es %lf\n", hora);
						peli1.sesiones[i].hora = hora;
						peli1.sesiones[i].plazas = 22;
					}

					printf("La primera sesion es a las %lf\n", peli1.sesiones[0].hora);

					anyadirPelicula(&cartelerita, peli1);
	//				anyadirPelicula(carte, peli);
				}
				else if (caracter2=='2')
				{
					int indice=0;

					printf("Escoja la pelicula a borrar\n");

					printf("EL primer horario es: %lf\n", cartelerita.peliculas[2].sesiones[0].hora);

					for(int i=0; i<cartelerita.numPelis; i++)
					{
						printf("Titulo: %s\n", cartelerita.peliculas[i].titulo);
					}

					char *titulo = malloc(sizeof(char)*TAMANYO_tit);
					printf("Asd\n");
					scanf(" %[^\t\n]s", titulo);

					printf("dfs2\n");
					for (int i = 0; i < strlen(titulo); i++)
					{
						titulo[i] = toupper(titulo[i]);
					}
					printf("dfs\n");
					char *titulo2= malloc(sizeof(char)*TAMANYO_tit);

					for(int i=0; i<cartelerita.numPelis; i++)
					{
						strcpy(titulo2, cartelerita.peliculas[i].titulo);
						for (int j = 0; j < strlen(titulo2); j++)
						{
							titulo2[j] = toupper(titulo2[j]);
						}
						if(strcmp(titulo, titulo2) == 0)
						{
							indice=i;
							printf("El indice es %i", indice);
							break;
						}
					}

					ficheroCarteleraBorrado(cartelerita, indice);
					printf("mahandy\n");

//					Cartelera cart;
//
//					cart.cine = malloc(sizeof(char)*TAMANYO_tit);
//					strcpy(cart.cine, cartelerita.cine);
//					printf("mahandyyy\n");
//					cart.numPelis = cartelerita.numPelis-1;
//					printf("mahandy1\n");
//					cart.peliculas = malloc(sizeof(Pelicula)*cart.numPelis);
//					printf("mahandyyy5\n");
//					double hora = 0.0;
//					for(int i =0; i<cartelerita.numPelis;i++)
//					{
//						if(i!=indice)
//						{
//							cart.peliculas[i].titulo = malloc(sizeof(char)*TAMANYO_tit);
//							cart.peliculas[i].descripcion = malloc(sizeof(char)*TAMANYO_descr);
//							strcpy(cart.peliculas[i].titulo, cartelerita.peliculas[i].titulo);
//							strcpy(cart.peliculas[i].descripcion, cartelerita.peliculas[i].descripcion);
//							cart.peliculas[i].numSesiones = cartelerita.peliculas[i].numSesiones;
//							cart.peliculas[i].sesiones = malloc(sizeof(Sesion)*cart.peliculas[i].numSesiones);
//							printf("mahandyyy6\n");
//							for(int j=0; j<cart.peliculas[i].numSesiones; j++)
//							{
//								printf("Hola soy Lora\n");
//								//cart.peliculas[i].sesiones[j].plazas = cartelerita.peliculas[i].sesiones[j].plazas;
//
//								hora= cartelerita.peliculas[i].sesiones[j].hora;
//								printf("Hola soy Lora3\n");
//								cart.peliculas[i].sesiones[j].hora = hora;
//								printf("Hola soy Lora2\n");
//							}
//
//
//						}
//					}
//					printf("mahandy2\n");


//					ficheroCartelera(cart);

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
		int sesiones = 0;
		double hora = 0.0;

		for(int i=0; i<cart->numPelis; i++)
		{

			printf("Introduzca el titulo de la pelicula: \n");
			scanf(" %[^\t\n]s", titulo);
			longitud = strlen(titulo);
			printf("%i\n", longitud);

			printf("Introduzca una breve descripcion sobre la pelicula: \n");
			scanf(" %[^\t\n]s", desc);
			longitud2 = strlen(desc);

			printf("Cuantas sesiones diarias quiere tener de la pelicula %s?\n", titulo);
			scanf("%i", &sesiones);

			cart->peliculas[i].sesiones = malloc(sizeof(Sesion)*sesiones);
			cart->peliculas[i].numSesiones = sesiones;

			for(int j=0; j<sesiones; j++)
			{
				printf("Introduzca la hora de la sesion %i:\n", j+1);
				scanf("%lf", &hora);
				printf("Dentro del for la hora es %lf\n", hora);
				cart->peliculas[i].sesiones[j].hora = hora;
				cart->peliculas[i].sesiones[j].plazas = 22;
			}




			cart->peliculas[i].titulo= malloc (sizeof(char)*(longitud+1));
			cart->peliculas[i].descripcion = malloc (sizeof(char)*(longitud2+1));

			strcpy(cart->peliculas[i].titulo, titulo);
			strcpy(cart->peliculas[i].descripcion, desc);

		}

		printf("La primera sesion es a las %lf\n", cart->peliculas[0].sesiones[0].hora);

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

