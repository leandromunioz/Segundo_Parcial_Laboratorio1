/*
 * Parcer.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Leandro
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "eLibro.h"
#include "eEditorial.h"

/// @brief parsea los datos de eLibro desde el archivo csv
/// @param pFile
/// @param pArrayList_eLibro
/// @return 0 en caso de exito, -1 en caso de error
int parser_eLibroFromText(FILE *pFile, LinkedList *pArrayList_eLibro);
/// @brief parsea los datos de eEditorial desde el archivo csv
/// @param pFile
/// @param pArrayList_eEditorial
/// @return 0 en caso de exito, -1 en caso de error
int parser_eEditorialFromText(FILE *pFile, LinkedList *pArrayList_eEditorial);
/// @brief parsea los datos de MINOTAURO desde el archivo csv
/// @param pFile
/// @param pArrayMinotauro
/// @return 0 en caso de exito, -1 en caso de error
int parser_textFromMinotauro(FILE *pFile, LinkedList *pArrayMinotauro);

#endif /* PARSER_H_ */
