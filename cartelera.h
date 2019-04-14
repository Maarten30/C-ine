/*
 * cartelera.h
 *
 *  Created on: Apr 6, 2019
 *      Author: maarten
 */
#include "pelicula.h"

#ifndef CARTELERA_H_
#define CARTELERA_H_

typedef struct
{
	char *cine;
	Pelicula *peliculas;
	int numPelis;


} Cartelera;

void ficheroCartelera(Cartelera cart);
void imprimirCartelera(Cartelera cart);
Cartelera leerCartelera(char *cine);
void anyadirPelicula(Cartelera *cartelera, Pelicula peli);
void quitarPelicula(Cartelera *cartelera, Pelicula PeliABorrar);
int lineasFichero(char *fichero);
#endif /* CARTELERA_H_ */
