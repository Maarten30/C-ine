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
	int plazas;
	double hora;

} Sesion;

typedef struct
{
	char *titulo;
	char *descripcion;
	int numSesiones;
	Sesion *sesiones;

} Pelicula;



void imprimirPelicula(Pelicula peli);
#endif /* PELICULA_H_ */
