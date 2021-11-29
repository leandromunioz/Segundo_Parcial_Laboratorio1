/*
 * Controller.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Leandro
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Parser.h"

int controller_loadFromText_eLibro(char *path, LinkedList *pArrayList_eLibro);

int controller_loadFromText_eEditorial(char *path,
		LinkedList *pArrayList_eEditorial);

int controller_List_eLibro(LinkedList *pArrayList_eLibro,
		LinkedList *pArrayList_eEditorial);

int controller_eLibro_print(eLibro *this, LinkedList *pArrayList_eEditorial);

int controller_buscarIndicePorId(LinkedList *pArrayList_eEditorial, int id);

int controller_text_minotauro(LinkedList *pArrayList_eLibro,
		LinkedList *pArrayList_eEditorial, LinkedList *pArrayListMinotauro,
		char *path);

int controller_lista_mapeada(LinkedList *pArrayList_eLibro,
		LinkedList *pArrayList_eEditorial, LinkedList *pArrayList_mapeada,
		char *path);
#endif /* CONTROLLER_H_ */
