/**
 * \file Gestion.hpp
 * \brief Declaraci&oacute;n de funciones de gesti&oacute;n de men&uacute;s y pruebas.
 * \date 10/02/2026
 */

#ifndef GESTION_HPP_INCLUDED
#define GESTION_HPP_INCLUDED

#include "Matriz.hpp"

/**
 * \brief Enumeraci&oacute;n para el modo de captura de datos.
 */
enum ModoCaptura {
    MANUAL = 1,     ///< Las entradas de la matriz se ingresan manualmente.
    ALEATORIA = 2   ///< Las entradas de la matriz se generan autom&aacute;ticamente.
};

/**
 * \brief Enumeraci&oacute;n para las opciones de operaciones matriciales.
 */
enum Opciones_Operadores {
    SUMA = 1,
    RESTA,
    PRODUCTO_MATRICIAL,
    PRODUCTO_ESCALAR,
    ACCESO_ENTRADAS,
    MODIFICAR_ENTRADAS,
    TRANSPUESTA,
    INVERSA,
    REDIMENSIONAR,
    REDEFINIR,
    SALIR_OP
};

/**
 * \brief Enumeraci&oacute;n para identificar la matriz activa.
 */
enum Matriz_i{
    MatrizA = 1,
    MatrizB
};

/**
 * \brief Muestra el men&uacute; para definir e imprimir matrices.
 *
 * \return void
 *
 */
void GDefiniEImprime();

/**
 * \brief Muestra el men&uacute; de operaciones matriciales.
 *
 * \return void
 *
 */
void GOperaciones();

/**
 * \brief Ejecuta el &aacute;rea de pruebas r&aacute;pidas.
 *
 * \return void
 *
 */
void GTesteo();

/**
 * \brief Auxiliar para redefinir una matriz (dimensiones y datos).
 *
 * \param m Referencia a la matriz a definir.
 * \return void
 *
 */
void DefinirMatriz(Matriz &m);

/**
 * \brief Auxiliar para seleccionar el modo de captura.
 *
 * \param modo Referencia entera donde guardar la selecci&oacute;n.
 * \return void
 *
 */
 void ElegirModoCaptura(int &modo);

#endif // GESTION_HPP_INCLUDED
