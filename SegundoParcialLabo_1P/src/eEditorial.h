/*
 * eEditorial.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Leandro
 */

#ifndef EEDITORIAL_H_
#define EEDITORIAL_H_
#include "funciones.h"

typedef struct {

	int idEditorial;
	char nombre[128];

} eEditorial;

/// @brief crea un espacio en memoria para eEditorial
/// @return devuelve el puntero al espacio en memoria
eEditorial* eEditorial_new();

/// @brief constructor con datos parametrizados
/// @param nombre
/// @param idEditorial
/// @return puntero al espacio en memoria
eEditorial* eEditorial_newParametros(char *nombre, char *idEditorial);
/// @brief carga los datos de nombre
/// @param this
/// @param nombre
/// @return devuelve -1 en caso de error y 0 en caso de exito
int eEditorial_setNombre(eEditorial *this, char *nombre);
/// @brief obtiene el dato requerido
/// @param this
/// @param nombre
/// @return devuelve -1 en caso de error y 0 en caso de exito
int eEditorial_getNombre(eEditorial *this, char *nombre);
/// @brief carga los datos de editorial
/// @param this
/// @param idEditorial
/// @return devuelve -1 en caso de error y 0 en caso de exito
int eEditorial_setidEditorial(eEditorial *this, int idEditorial);
/// @brief obtiene los datos requeridos
/// @param this
/// @param idEditorial
/// @return devuelve -1 en caso de error y 0 en caso de exito
int eEditorial_getIdEditorial(eEditorial *this, int *idEditorial);

#endif /* EEDITORIAL_H_ */
