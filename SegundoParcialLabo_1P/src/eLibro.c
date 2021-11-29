/*
 * eLibro.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Leandro
 */
#include "eLibro.h"

eLibro* eLibro_new() {
	eLibro *eLibroAux;

	eLibroAux = (eLibro*) calloc(1, sizeof(eLibro));

	return eLibroAux;
}

eLibro* eLibro_newParametros(char *id, char *titulo, char *autor, char *precio,
		char *idEditorial) {

	eLibro *eLibroAux;

	eLibroAux = eLibro_new();

	if (eLibroAux != NULL) {
		eLibro_setidEditorial(eLibroAux, atoi(idEditorial));
		eLibro_setId(eLibroAux, atoi(id));
		eLibro_setTitulo(eLibroAux, titulo);
		eLibro_setAutor(eLibroAux, autor);
		eLibro_setPrecio(eLibroAux, atoi(precio));
	}

	return eLibroAux;
}

int eLibro_setId(eLibro *this, int id) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int eLibro_getId(eLibro *this, int *id) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int eLibro_setTitulo(eLibro *this, char *titulo) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(this->titulo, titulo);
		retorno = 0;
	}

	return retorno;
}

int eLibro_getTitulo(eLibro *this, char *titulo) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(titulo, this->titulo);
		retorno = 0;
	}

	return retorno;
}

int eLibro_setAutor(eLibro *this, char *autor) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(this->autor, autor);
		retorno = 0;
	}

	return retorno;
}

int eLibro_getAutor(eLibro *this, char *autor) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(autor, this->autor);
		retorno = 0;
	}

	return retorno;
}

int eLibro_setidEditorial(eLibro *this, int idEditorial) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		this->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

int eLibro_getIdEditorial(eLibro *this, int *idEditorial) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

int eLibro_setPrecio(eLibro *this, float precio) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int eLibro_getPrecio(eLibro *this, float *precio) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int eLibro_compare_autor(void *one, void *two) {
	int retorno;
	char nameOne[128];
	char nameTwo[128];
	eLibro *first;
	eLibro *second;

	retorno = -1;
	first = (eLibro*) one;
	second = (eLibro*) two;
	eLibro_getAutor(first, nameOne);
	eLibro_getAutor(second, nameTwo);
	retorno = stricmp(nameOne, nameTwo);

	return retorno;
}

int eLibro_compare_editorial(void *pElement) {

	eLibro *eLibroAux;
	int retorno;
	int idAux;
	retorno = -1;

	eLibroAux = (eLibro*) pElement;

	eLibro_getIdEditorial(eLibroAux, &idAux);

	if (idAux == 4) {
		retorno = 1;
	}

	return retorno;
}

int eLibro_descuento(void *aux) {
	int retorno;
	int idAux;
	float precio;
	float descuento;

	retorno = -1;

	if ((eLibro_getIdEditorial(aux, &idAux) == 0)
			&& (eLibro_getPrecio(aux, &precio) == 0)) {

		if ((idAux == 1) && (precio >= 300)) {
			descuento = precio - (precio * 20 / 100);
			((eLibro*) aux)->precio = descuento;
		} else {
			if ((idAux == 2) && (precio >= 200)) {
				descuento = precio - (precio * 10 / 100);
				((eLibro*) aux)->precio = descuento;
			}
		}
		retorno = 0;
	}

	return retorno;

}
