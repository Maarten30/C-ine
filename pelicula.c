/*
 * pelicula.c
 *
 *  Created on: Apr 6, 2019
 *      Author: maarten
 */
#include "pelicula.h"

void imprimirPelicula(Pelicula peli)
{
	printf("%s\nDescripcion: %s\n", peli.titulo, peli.descripcion);
}

