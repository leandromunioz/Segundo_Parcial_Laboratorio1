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
#define ARCHIVOMAPEADO "mapeado.csv"
int main(void) {

	setbuf(stdout, NULL);

	int option = 0;
	int bandera_eLibro;
	int bandera_eEditorial;
	LinkedList *eEditorialArray = ll_newLinkedList();
	LinkedList *eLibroArray = ll_newLinkedList();
	LinkedList *arrayMinotauro;
	LinkedList *arrayMapeado;

	bandera_eLibro = 0;
	bandera_eEditorial = 0;
	arrayMinotauro = NULL;
	arrayMapeado = NULL;
	do {

		printf(
				"\n********************************************************************************************************************************************************************************************\n1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro.\n2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial.\n3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente.\n4. Imprimir por pantalla todos los datos de los libros. \n5. Realizar un listado de los libros de la editorial MINOTAURO.\n6.Generar el archivo de salida “mapeado.csv”\n0. Salir\n********************************************************************************************************************************************************************************************\n\n");

		if (GetNumero(&option, "Seleccione la opcion deseada:\n",
				"Opcion invalida. Reingrese:\n", 0, 6, 5) == 0) {
			printf(
					"\nVerificando opcion ingresada ... Por favor, espere...\n\n");
		} else {
			printf(
					"\nHa ocurrido un error en la operacion. Intente nuevamente.\n");
		}

		switch (option) {

		case 0:

			printf(
					"\nGuardando cambios ... Aguarde un instante.\n\nVerificando que los archivos se hayan guardado correctamente... Por favor, no apague su ordenador hasta que finalice el proceso...\n\n-Cambios guardados-\n\nEl programa ha finalizado con exito.\n ");

			break;

		case 1:
			if (bandera_eLibro == 0) {

				if (controller_loadFromText_eLibro(ARCHIVOELIBRO, eLibroArray)
						== 0) {
					bandera_eLibro = 1;
					printf("\nOperacion LECTURA LIBROS exitosa.\n");

				} else {

					printf(
							"\nHa ocurrido un error en la operacion LECTURA LIBROS. Reintente la operacion.\n");
				}

			} else {

				printf("\nYa se han cargado los datos de los libros.\n");
			}
			break;

		case 2:
			if (bandera_eEditorial == 0) {

				if (controller_loadFromText_eEditorial(ARCHIVOEEDITORIAL,
						eEditorialArray) == 0) {
					bandera_eEditorial = 1;
					printf("\nOperacion LECTURA EDITORIAL exitosa.\n");
				} else {

					printf(
							"\nHa ocurrido un error en la operacion LECTURA EDITORIAL. Reintente la operacion.\n");

				}

			} else {
				printf("\nYa se han cargado los datos de las editoriales.\n");
			}

			break;

		case 3:
			if ((bandera_eLibro == 1) && (bandera_eEditorial == 1)) {
				if (ll_sort(eLibroArray, eLibro_compare_autor, 1) == 0) {

					printf(
							"\nOperacion ORDENAMIENTO DE LA LISTA DE AUTORES exitosa.\n");
				} else {
					printf(
							"\nHa ocurrido un error en la operacion ORDENAMIENTO DE LA LISTA DE AUTORES. Reintente la operacion.\n");
				}
			} else {
				printf(
						"\nAntes de realizar esta operacion, por favor cargue los datos de las editoriales y los libros.\n");
			}

			break;

		case 4:

			if ((bandera_eLibro == 1) && (bandera_eEditorial == 1)) {
				printf(
						"\n\n________________________________________\nID  | LIBRO | AUTOR | PRECIO | EDITORIAL\n----------------------------------------\n");

				if (controller_List_eLibro(eLibroArray, eEditorialArray) == 0) {
					printf(
							"\n\nOperacion IMPRIMIR DATOS DE LOS LIBROS exitosa.\n");

				} else {
					printf(
							"\nHa ocurrido un error en la operacion IMPRIMIR DATOS DE LOS LIBROS. Reintente la operacion.\n");
				}
			} else {
				printf(
						"\nAntes de realizar esta operacion, por favor cargue los datos de las editoriales y los libros.\n");
			}

			break;

		case 5:
			if ((bandera_eLibro == 1) && (bandera_eEditorial == 1)) {
				printf(
						"\n\n________________________________________\nID  | LIBRO | AUTOR | PRECIO | EDITORIAL\n----------------------------------------\n");

				if (controller_text_minotauro(eLibroArray, eEditorialArray,
						arrayMinotauro, ARCHIVOMINOTAURO) == 0) {
					printf(
							"\n\nOperacion LISTADO DE LOS LIBROS DE LA EDITORIAL MINOTAURO exitosa.\n");
				} else {
					printf(
							"\nHa ocurrido un error en la operacion LISTADO DE LOS LIBROS DE LA EDITORIAL MINOTAURO . Reintente la operacion.\n ");
				}
			} else {
				printf(
						"\nAntes de realizar esta operacion, por favor cargue los datos de las editoriales y los libros.\n");
			}
			break;

		case 6:
			if ((bandera_eLibro == 1) && (bandera_eEditorial == 1)) {
				if (controller_lista_mapeada(eLibroArray, eEditorialArray,
						arrayMapeado, ARCHIVOMAPEADO) == 0) {
					printf("\n\nOperacion LISTADO MAPEADO exitosa. Encontrará su nuevo archivo 'mapeado.csv' en la carpeta destino correspondiente.\n");
				} else {
					printf(
							"\nAntes de realizar esta operacion, por favor cargue los datos de las editoriales y los libros.\n");
				}

				break;
			}
		}

	} while (option != 0);

	return EXIT_SUCCESS;
}
