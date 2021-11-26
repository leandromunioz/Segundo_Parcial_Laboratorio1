/*
 ============================================================================
 Name        : SegundoParcialLabo_1P.c
 Author      : Leandro Mu�oz DIV C
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

#define ARCHIVOELIBRO "eLibro.csv"
#define ARCHIVOEEDITORIAL "eEditorial.csv"
#define ARCHIVOMINOTAURO "dataMinotauro.csv"
int main(void) {

	setbuf(stdout, NULL);

	int option = 0;
	int bandera_eLibro;
	int bandera_eEditorial;
	LinkedList *eEditorialArray = ll_newLinkedList();
	LinkedList *eLibroArray = ll_newLinkedList();
	LinkedList *arrayMinotauro;

	bandera_eLibro = 0;
	bandera_eEditorial = 0;
	arrayMinotauro = NULL;

	do {

		printf(
				"\n********************************************************************************************************************************************************************************************\n1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro.\n2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial.\n3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente.\n4. Imprimir por pantalla todos los datos de los libros. \n5. Realizar un listado de los libros de la editorial MINOTAURO.\n0. Salir\n********************************************************************************************************************************************************************************************\n\n");

		if (GetNumero(&option, "Seleccione la opcion deseada:\n",
				"Opcion invalida. Reingrese:\n", 1, 5, 5) == 0) {
			printf("Verificando opcion ingresada ... Por favor, espere...\n");
		} else {
			printf(
					"Ha ocurrido un error en la operacion. Intente nuevamente.\n");
		}

		switch (option) {

		case 1:
			if (bandera_eLibro == 0) {

				if (controller_loadFromText_eLibro(ARCHIVOELIBRO, eLibroArray)
						== 0) {
					bandera_eLibro = 1;
					printf("\nOperacion de LECTURA LIBROS exitosa.\n");

				} else {

					printf(
							"Ha ocurrido un error en la operacion LECTURA LIBROS. Reintente la operacion.\n");
				}

			} else {

				printf("Ya se han cargado los datos de los libros.\n");
			}
			break;

		case 2:
			if (bandera_eEditorial == 0) {

				if (controller_loadFromText_eEditorial(ARCHIVOEEDITORIAL,
						eEditorialArray) == 0) {
					bandera_eEditorial = 1;
					printf("\nOperacion de LECTURA EDITORIAL exitosa.\n");
				} else {

					printf(
							"Ha ocurrido un error en la operacion LECTURA EDITORIAL. Reintente la operacion.\n");

				}

			} else {
				printf("Ya se han cargado los datos de las editoriales.\n");
			}

			break;

		case 3:
			if ((bandera_eLibro == 1) && (bandera_eEditorial == 1)) {
				if (ll_sort(eLibroArray, eLibro_compare_autor, 1) == 0) {

					printf(
							"\nOperacion de ORDENAMIENTO DE LA LISTA DE AUTORES exitosa.\n");
				} else {
					printf(
							"Ha ocurrido un error en la operacion ORDENAMIENTO DE LA LISTA DE AUTORES. Reintente la operacion.\n");
				}
			} else {
				printf(
						"Antes de realizar esta operacion, por favor cargue los datos de las editoriales y los libros.\n");
			}

			break;

		case 4:

			if ((bandera_eLibro == 1) && (bandera_eEditorial == 1)) {
				if (controller_List_eLibro(eLibroArray, eEditorialArray) == 0) {
					printf("\n\nOperacion IMPRIMIR DATOS DE LOS LIBROS exitosa.\n");

				} else {
					printf(
							"Ha ocurrido un error en la operacion IMPRIMIR DATOS DE LOS LIBROS. Reintente la operacion.\n");
				}
			} else {
				printf(
						"Antes de realizar esta operacion, por favor cargue los datos de las editoriales y los libros.\n");
			}

			break;

		case 5:
			if ((bandera_eLibro == 1) && (bandera_eEditorial == 1)) {
				if (controller_text_minotauro(eLibroArray, eEditorialArray,
						arrayMinotauro, ARCHIVOMINOTAURO) == 0) {
					printf(
							"\n\nOperacion LISTADO DE LOS LIBROS DE LA EDITORIAL MINOTAURO exitosa.\n");
				} else {
					printf(
							"Ha ocurrido un error en la operacion LISTADO DE LOS LIBROS DE LA EDITORIAL MINOTAURO . Reintente la operacion.\n ");
				}
			} else {
				printf(
						"Antes de realizar esta operacion, por favor cargue los datos de las editoriales y los libros.\n");
			}

		}

	} while (option != 0);

	return EXIT_SUCCESS;
}
