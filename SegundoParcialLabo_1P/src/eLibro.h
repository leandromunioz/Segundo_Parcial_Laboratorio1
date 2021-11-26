/*
 * eLibro.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Leandro
 */

#ifndef ELIBRO_H_
#define ELIBRO_H_
#include "funciones.h"
#include "eEditorial.h"
typedef struct {

	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;

} eLibro;

/// @brief crea un espacio en memoria para eLibro
/// @return devuelve el puntero al espacio en memoria
eLibro* eLibro_new();

/// @brief constructor con datos parametrizados
/// @param id
/// @param titulo
/// @param autor
/// @param precio
/// @param idEditorial
/// @return devuelve el puntero al espacio en memoria
eLibro* eLibro_newParametros(char *id, char *titulo, char *autor, char *precio,
		char *idEditorial);

/// @brief carga datos de id
/// @param this
/// @param id
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_setId(eLibro *this, int id);

/// @brief obtiene el dato requerido
/// @param this
/// @param id
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_getId(eLibro *this, int *id);
/// @brief carga datos del titulo
/// @param this
/// @param titulo
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_setTitulo(eLibro *this, char *titulo);

/// @brief obtiene el dato requerido
/// @param this
/// @param titulo
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_getTitulo(eLibro *this, char *titulo);

/// @brief carga datos del autor
/// @param this
/// @param autor
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_setAutor(eLibro *this, char *autor);
/// @brief obtiene el dato requerido
/// @param this
/// @param autor
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_getAutor(eLibro *this, char *autor);
/// @brief carga datos de id editorial
/// @param this
/// @param idEditorial
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_setidEditorial(eLibro *this, int idEditorial);
/// @brief obtiene el dato requerido
/// @param this
/// @param idEditorial
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_getIdEditorial(eLibro *this, int *idEditorial);
/// @brief carga datos del precio
/// @param this
/// @param precio
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_setPrecio(eLibro *this, float precio);
/// @brief obtiene el dato requerido
/// @param this
/// @param precio
/// @return -1 en caso de error y 0 en caso de que sea exitosa
int eLibro_getPrecio(eLibro *this, float *precio);
/// @brief funcion que compara dos datos
/// @param one
/// @param two
/// @return devuelve el resultado de la comparacion
int eLibro_compare_autor(void *one, void *two);
/// @brief funcion utilizada para obtener el id 4 de la editorial
/// @param pElement
/// @return devuelve 1 si encontro el id 4, -1 si hubo error
int eLibro_compare_editorial(void *pElement);

#endif /* ELIBRO_H_ */
