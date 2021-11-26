/*
 * input.h
 *
 *  Created on: 9 sep. 2021
 *      Author: Leandro
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

///@brief Funcion que muestra un numero flotante que se la pasa como parametro
/// @param puntero a variable de tipo flotante
/// @return devuelve 1 si la funcion se ejecuto correctamente.
int MostrarPunteroFlotante(float *numeroFlotante);

///@brief Pide el ingreso de un numero
///@param Un mensaje impreso en pantalla donde pide el numero
/// @param Recibe un numero entero
/// @return devuelve un numero flotante
float IngresarNumero(char mensaje[], int *numeroIngresado);

void IngresarArrayDeNumeros(int numeros[], int T);

///@brief Realiza operaciones matematicas y el calculo del factorial
/// @param primer numero a calcular
/// @param segundo numero a calcular
/// @param tipo de operacion a realizar
/// @return devuelve el resultado de la operacion
double Operaciones(float numeroUno, float numeroDos, char operador);

///@brief Realiza el calculo del factorial
/// @param primer numero a calcular el factorial
/// @return devuelve el resultado de la operacion
long double CalculoFactorial(int valor);


char IngresarCaracter(char mensaje[]);

/// @fn int FormatearCadena(char[])
/// @brief Ordena un array de caracteres primero en mayus y luego en minus.
///
/// @param cadena
/// @return devuelve 0 si hubo un error , 1 si fue realizada con exito.
int FormatearCadena(char cadena[]);

/// @fn int GetCuit(char*)
/// @brief Pide el ingreso de un cuit y le inserta sus respectivos guiones.
///
/// @param cuit
/// @return devuelve 0 si hubo error y 1 si fue ejecutada con exito.
int GetCuit(char* cuit);

/// @fn int IngresarCadena(char[], char[], char*, int)
/// @brief Pide el ingreso de una cadena de caracteres validada en rango
///
/// @param mensaje
/// @param mensajeError
/// @param cadena
/// @param tam
/// @return devuelve 1 si fue exitosa y 0 si hubo error
int IngresarCadena(char mensaje[], char mensajeError[], char* cadena, int tam);

/// @fn int RetornarNombreCompleto(char[], char[], char[])
/// @brief devuelve el nombre completo ordenado Nombre Apellido
///
/// @param nombre
/// @param apellido
/// @param nombreCompleto
/// @return 1 si fue exitosa y 0 si hubo errores
int RetornarNombreCompleto(char nombre[], char apellido[], char nombreCompleto[]);

int PedirEnteroValidadoEnRango(char[], int, int);

///@brief Valida el numero recibido
/// @param numero ingresado
/// @return devuelve 0 si hubo error o 1 si hubo exito
int ValidarNumero(char *cadena);

int ValidarCuit(char* string);

void MostrarNumerosIngresados(char[], int numeros[], int T); //Muestra el array de los numeros ingresados.
void MostrarNumerosPares(char[], int numeros[], int T);
void MostrarNumerosImpares(char[], int numeros[], int T);

///@brief verifica si el numero ingresado es par o impar
/// @param numero ingresado a verificar
/// @return devuelve 0 si es par , 1 si es impar y -1 si hubo un error
int VerificarParidad(int numeroIngresado);

int PedirNumero(char mensaje[],int *num);

///@brief funcion que pide el ingreso de un numero validado en un rango y da una cantidad de reintentos
/// @param puntero al espacio en memoria en donde se dejara el resultado de la funcion
/// @param mensaje de ingreso de datos
/// @param mensaje de error por si los datos no son validos
/// @param numero minimo a ingresar
/// @param numero maximo a ingresar
/// @param reintentos posibles
/// @return Devuelve 0 si la funcion fue ejecutada con exito. -1 si hubo un error
int GetNumero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos);

/// @fn int GetDouble(double*, char*, char*, double, double, int)
/// @brief Funcion que recibe un numero de tipo double
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param min
/// @param max
/// @param reintentos
/// @return devuelve 0 si fue ejecutada con exito y -1 si hubo un error.
int GetDouble(double *pResultado, char *mensaje, char *mensajeError, double min, double max, int reintentos);

///@brief funcion que pide el ingreso de un flotante validado en un rango y da una cantidad de reintentos
/// @param puntero al espacio en memoria en donde se dejara el resultado de la funcion
/// @param mensaje de ingreso de datos
/// @param mensaje de error por si los datos no son validos
/// @param numero minimo a ingresar
/// @param numero maximo a ingresar
/// @param reintentos posibles
/// @return Devuelve 0 si la funcion fue ejecutada con exito. -1 si hubo un error
int GetFlotante(float *pResultado, char *mensaje, char *mensajeError, float min, float max, int reintentos);

///@brief funcion que pide el ingreso de un caracter validado en un rango y da una cantidad de reintentos
/// @param puntero que apunta al caracter
/// @param mensaje de ingreso de datos
/// @param mensaje de error por si los datos no son validos
/// @param caracter minimo a ingresar
/// @param caracter maximo a ingresar
/// @param reintentos posibles
/// @return Devuelve 0 si la funcion fue ejecutada con exito. -1 si hubo un error
int GetCaracter(char *pResultado, char *mensaje, char *mensajeError, char min, char max, int reintentos);

 int GetInt(int *resultado);
 int GetFloat(float *pResultado);

 ///@brief verifica si la cadena ingresada es numerica
  /// @param cadena a ser verificada
  /// @return devuelve -1 si hay error de parametros, 1 si la cadena es numerica y 0 si es falso
 int EsNumerica(char *cadena, int limite);

 ///@brief verifica si la cadena es flotante
 /// @param cadena a ser verificada
 /// @return devuelve 1 si la cadena es flotante y 0 si no es flotante
 int EsFlotante(char *cadena);

 /// @fn int MyGets(char*, int)
 /// @brief Pide el ingreso de una cadena de texto de manera segura, evitando desbordamiento de buffer.
 ///
 /// @param cadena
 /// @param longitud
 /// @return devuelve 0 si fue ejecutada con exito, -1 si hubo error.
 int MyGets(char *cadena, int longitud);

 ///@brief Pide el ingreso de una cadena de texto
  /// @param mensaje a mostrar
  /// @param cadena de texto ingresada
  /// @return devuelve 1 si la funcion fue ejecutada, 0 si hubo un error
 int GetString(char mensaje[],char cadena[]);

 /// @fn int MyIsAlpha(char[])
 /// @brief Funcion que verifica si la cadena ingresada es unicamente de caracteres
 ///
 /// @param cadena
 /// @return devuelve 1 si fue ejecutada con exito, -1 si hubo error.
 int MyIsAlpha(char cadena[]);

 /// @fn int GetName(char[], char[], char[])
 /// @brief Pide el ingreso de una cadena, verificando que sea solo letras. Funcion utilizada para pedir nombres
 ///
 /// @param mensaje
 /// @param mensajeError
 /// @param cadena
 /// @return devuelve 0 si hubo error, 1 si fue ejecutada con exito.
 int GetName(char mensaje[],char mensajeError[] , char cadena[]);

 ///@brief Funcion que confirma una accion
 ///@param mensaje
 ///@param confirmacion
 ///@return devuelve la confirmacion s o n
 int ConfirmarAccion(char *mensaje, char *compara);
#endif /* FUNCIONES_H_ */

