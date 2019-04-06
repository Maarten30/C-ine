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

typedef struct
{
	char *peli;
	Pelicula *peliculas;
	int sitios;


} Sesion;

void imprimirCartelera(Cartelera cart);
#endif /* CARTELERA_H_ */
