/*
 * Controller.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"

/** \brief Carga los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList_eLibro LinkedList*
 * \return int
 *
 */

int controller_loadFromText_eLibro(char *path, LinkedList *pArrayList_eLibro) {
	int retorno;
	retorno = -1;

	FILE *pFile;

	pFile = fopen(path, "r");

	if (pFile != NULL) {
		parser_eLibroFromText(pFile, pArrayList_eLibro);
		retorno = 0;
	}

	fclose(pFile);
	return retorno;
}

int controller_saveFromLinkedList(char *path, LinkedList *pArrayList) {

	FILE *pFile = NULL;
	int retorno;
	retorno = -1;

	pFile = fopen(path, "w");

	if (pFile != NULL) {

		parser_textFromMinotauro(pFile, pArrayList);
		retorno = 0;

	}
	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de las editoriales desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList_eEditorial LinkedList*
 * \return int
 *
 */

int controller_loadFromText_eEditorial(char *path,
		LinkedList *pArrayList_eEditorial) {
	int retorno;
	retorno = -1;

	FILE *pFile;

	pFile = fopen(path, "r");

	if (pFile != NULL) {
		parser_eEditorialFromText(pFile, pArrayList_eEditorial);
		retorno = 0;
	}

	fclose(pFile);
	return retorno;
}

/// @brief verifica que el id y el ideditorial sean iguales y devuelve su indice
/// @param pArrayList_eEditorial
/// @param id
/// @return devueleve el indice del id
int controller_buscarIndicePorId(LinkedList *pArrayList_eEditorial, int id) {
	eEditorial *eEditorialAux;
	int tam;
	int retorno;
	int idEditorialAux;
	retorno = -1;

	if (pArrayList_eEditorial != NULL) {
		tam = ll_len(pArrayList_eEditorial);

		for (int i = 0; i < tam; i++) {
			eEditorialAux = (eEditorial*) ll_get(pArrayList_eEditorial, i);
			eEditorial_getIdEditorial(eEditorialAux, &idEditorialAux);
			if (idEditorialAux == id) {

				retorno = i;

				break;

			} else {
				continue;
			}
		}
	}

	return retorno;
}

/// @brief printea los datos de elibro
/// @param this
/// @param pArrayList_eEditorial
/// @return -1 si hubo error, 0 si fue exitoso
int controller_eLibro_print(eLibro *this, LinkedList *pArrayList_eEditorial) {

	eEditorial *eEditorialAux;
	int indexAux;
	int idAux;
	char titulo[128];
	char autor[128];
	char nombre[128];
	float precio;
	int idEditorial;
	int retorno;
	retorno = -1;

	if (this != NULL) {
		eLibro_getAutor(this, autor);
		eLibro_getId(this, &idAux);
		eLibro_getPrecio(this, &precio);
		eLibro_getIdEditorial(this, &idEditorial);
		eLibro_getTitulo(this, titulo);

		indexAux = controller_buscarIndicePorId(pArrayList_eEditorial,
				idEditorial);
		eEditorialAux = (eEditorial*) ll_get(pArrayList_eEditorial, indexAux);
		eEditorial_getNombre(eEditorialAux, nombre);
		printf("%d, %s,%s, %.2f, %s\n", idAux, titulo, autor, precio, nombre);
		retorno = 0;
	}

	return retorno;
}

/** \brief Listar libros
 *
 * \param path char*
 * \param pArrayListeLibro LinkedList*
 * \return int -1 error y 0 si fue exitosa
 *
 */
int controller_List_eLibro(LinkedList *pArrayList_eLibro,
		LinkedList *pArrayList_eEditorial) {
	eLibro *eLibroaux;
	int tam;
	int retorno;
	retorno = -1;

	if (pArrayList_eLibro != NULL) {
		tam = ll_len(pArrayList_eLibro);
		for (int i = 0; i < tam; i++) {
			eLibroaux = (eLibro*) ll_get(pArrayList_eLibro, i);
			controller_eLibro_print(eLibroaux, pArrayList_eEditorial);

		}
		retorno = 0;
	}

	return retorno;
}

/// @brief guarda todos los libros de la editorial MINOTAURO (id 4 )
/// @param pArrayList_eLibro
/// @param pArrayList_eEditorial
/// @param pArrayListMinotauro
/// @param path
/// @return -1 si hubo error , 0 si fue exitosa
int controller_text_minotauro(LinkedList *pArrayList_eLibro,
		LinkedList *pArrayList_eEditorial, LinkedList *pArrayListMinotauro,
		char *path) {

	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "w");

	if (pFile != NULL) {

		pArrayListMinotauro = ll_filter(pArrayList_eLibro,
				eLibro_compare_editorial);

		if (parser_textFromMinotauro(pFile, pArrayListMinotauro) == 0) {
			retorno = 0;
			controller_List_eLibro(pArrayListMinotauro, pArrayList_eEditorial);
		}
	}
	fclose(pFile);
	return retorno;
}

/// @brief setea la lista y la carga en el archivo csv
/// @param pArrayList_eLibro
/// @param pArrayList_eEditorial
/// @param pArrayList_mapeada
/// @param path
/// @return 0 si fue exitosa y -1 en caso de error
int controller_lista_mapeada(LinkedList *pArrayList_eLibro,
		LinkedList *pArrayList_eEditorial, LinkedList *pArrayList_mapeada,
		char *path) {

	int retorno;
	retorno = -1;

	if (pArrayList_eLibro != NULL) {
		if (ll_map(pArrayList_eLibro, eLibro_descuento) == 0) {
			if (controller_saveFromLinkedList(path, pArrayList_eLibro) == 0) {

				retorno = 0;
			}
		}
	}
	return retorno;
}

