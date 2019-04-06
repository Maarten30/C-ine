/*
 * pelicula.h
 *
 *  Created on: Apr 6, 2019
 *      Author: maarten
 */

#ifndef PELICULA_H_
#define PELICULA_H_
typedef struct
{
	char *titulo;
	char *descripcion;

} Pelicula;

void imprimirPelicula(Pelicula peli);
#endif /* PELICULA_H_ */
