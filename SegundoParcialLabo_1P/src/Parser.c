/*
 * Parser.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Leandro
 */

#include "Parser.h"

int parser_eLibroFromText(FILE *pFile, LinkedList *pArrayList_eLibro) {
	eLibro *eLibroAux;
	char id[128];
	char titulo[128];
	char autor[128];
	char precio[128];
	char idEditorial[128];
	int retorno = -1;

	if (pFile != NULL && pArrayList_eLibro != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, titulo, autor,
				precio, idEditorial);
		retorno = 0;

		while (!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, titulo,
					autor, precio, idEditorial);
			eLibroAux = eLibro_newParametros(id, titulo, autor, precio,
					idEditorial);

			ll_add(pArrayList_eLibro, eLibroAux);
		}

	}

	return retorno;
}

int parser_eEditorialFromText(FILE *pFile, LinkedList *pArrayList_eEditorial) {
	eEditorial *eEditorialAux;
	char nombre[128];
	char idEditorial[128];
	int retorno = -1;

	if (pFile != NULL && pArrayList_eEditorial != NULL) {

		fscanf(pFile, "%[^,],%[^\n]\n ", nombre, idEditorial);
		retorno = 0;

		while (!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^\n]\n ", idEditorial, nombre);
			eEditorialAux = eEditorial_newParametros(nombre, idEditorial);
			ll_add(pArrayList_eEditorial, eEditorialAux);
		}

	}

	return retorno;
}

int parser_textFromMinotauro(FILE *pFile, LinkedList *pArrayMinotauro) {

	int tam;
	int retorno;
	int idAux;
	char tituloAux[128];
	char autorAux[128];
	float precioAux;
	int idEditorialAux;
	eLibro *eLibroAux;

	retorno = -1;

	if (pFile != NULL) {
		tam = ll_len(pArrayMinotauro);
		fprintf(pFile, "ID,TITULO,AUTOR,PRECIO,IDEDITORIAL\n");

		for (int i = 0; i < tam; i++) {

			eLibroAux = (eLibro*) ll_get(pArrayMinotauro, i);
			eLibro_getId(eLibroAux, &idAux);
			eLibro_getIdEditorial(eLibroAux, &idEditorialAux);
			eLibro_getPrecio(eLibroAux, &precioAux);
			eLibro_getTitulo(eLibroAux, tituloAux);
			eLibro_getAutor(eLibroAux, autorAux);
			fprintf(pFile, "%d,%s,%s,%.2f,%d\n", idAux, tituloAux, autorAux,
					precioAux, idEditorialAux);

		}

		retorno = 0;
	}

	return retorno;
}

