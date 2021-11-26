/*
 * eEditorial.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Leandro
 */

#include "eEditorial.h"

eEditorial* eEditorial_new() {

	eEditorial *eEditorialAux;

	eEditorialAux = (eEditorial*) calloc(1, sizeof(eEditorial));

	return eEditorialAux;
}

eEditorial* eEditorial_newParametros(char *nombre, char *idEditorial) {

	eEditorial *eEditorialAux;

	eEditorialAux = eEditorial_new();

	if (eEditorialAux != NULL) {
		eEditorial_setidEditorial(eEditorialAux, atoi(idEditorial));
		eEditorial_setNombre(eEditorialAux, nombre);
	}

	return eEditorialAux;
}

int eEditorial_setNombre(eEditorial *this, char *nombre) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int eEditorial_getNombre(eEditorial *this, char *nombre) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int eEditorial_setidEditorial(eEditorial *this, int idEditorial) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		this->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

int eEditorial_getIdEditorial(eEditorial *this, int *idEditorial) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

