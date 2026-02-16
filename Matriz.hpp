/**
 * \file Matriz.hpp
 * Este archivo contiene la interfaz de la clase Matriz, incluyendo sobrecarga
 * de operadores, gesti&oacute;n de memoria din&aacute;mica y algoritmos lineales
 * como la inversa y la transpuesta.
 * \authors Jes&uacute;s Axel Sanchez Montoy y Marian Bethsabe Portugal Arreola
 * \date 10/02/2026
 */

#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>
#include <iomanip>

using std::ostream;

/**
 * \brief Clase que implementa una matriz matem&aacute;tica din&aacute;mica.
 */
class Matriz{
    /**
     * \brief Sobrecarga del operador de inserci&oacute;n (salida).
     * \param salida Flujo de salida.
     * \param m Matriz a imprimir.
     * \return Referencia al flujo de salida.
     */
    friend std::ostream & operator <<(std::ostream & salida, const Matriz &m);

    /**
     * \brief Sobrecarga del operador de extracci&oacute;n (entrada).
     * \param entrada Flujo de entrada.
     * \param m Matriz donde se guardar&aacute;n los datos.
     * \return Referencia al flujo de entrada.
     */
    friend std::istream & operator>>(std::istream & entrada, Matriz &m);

    /**
     * \brief Sobrecarga del operador de multiplicaci&oacute;n conmutativa (escalar * Matriz).
     * \param escalar Valor flotante.
     * \param m Matriz a multiplicar.
     * \return Nueva Matriz escalada.
     */
    friend Matriz operator*(float escalar, const Matriz m);

public:
    // --- Constructores ---

    /**
     * \brief Constructor con par&aacute;metros por defecto.
     *
     * Inicializa la matriz reservando memoria din&aacute;mica y rellen&aacute;ndola con ceros.
     * \param filas N&uacute;mero de filas (default 3).
     * \param columnas N&uacute;mero de columnas (default 3).
     * \throw const char* Si hay error en la asignaci&oacute;n de memoria.
     */
    explicit Matriz(int filas = 3, int columnas = 3);

    /**
     * \brief Destructor de la clase.
     *
     * Libera la memoria din&aacute;mica reservada.
     */
    ~Matriz();

    /**
     * \brief Constructor de copias.
     *
     * Crea una copia profunda de la matriz recibida.
     * \param m Matriz a copiar.
     */
    Matriz(const Matriz &m);


    // --- Funciones de obtenci&oacute;n ---

    /**
     * \brief Obtiene el n&uacute;mero de filas.
     * \return Cantidad de filas.
     */
    int ObtenerNumFilas() const;

    /**
     * \brief Obtiene el n&uacute;mero de columnas.
     * \return Cantidad de columnas.
     */
    int ObtenerNumColumnas() const;

    /**
     * \brief Obtiene el valor de una entrada espec&iacute;fica.
     * \param fila &Iacute;ndice de la fila.
     * \param columna &Iacute;ndice de la columna.
     * \return Valor en la posici&oacute;n indicada.
     */
    float ObtenerEntrada(int fila, int columna) const;


    // --- Captura y salida ---

    /**
     * \brief Permite al usuario llenar la matriz manualmente.
     */
    void CapturaManual();

    /**
     * \brief Llena la matriz con valores aleatorios.
     */
    void CapturaAleatoria();

    /**
     * \brief Imprime la matriz en la consola con formato.
     */
    void Imprimir() const;


    // --- Modificaciones de la matriz ---

    /**
     * \brief Establece un valor en una posici&oacute;n espec&iacute;fica.
     * \param fila &Iacute;ndice de fila.
     * \param columna &Iacute;ndice de columna.
     * \param valor Nuevo valor a asignar.
     * \throw const char* Si los &iacute;ndices est&aacute;n fuera de rango.
     */
    void EstablecerEntrada(int fila, int columna, float valor);

    /**
     * \brief Cambia las dimensiones de la matriz.
     *
     * Si las dimensiones cambian, se preservan los datos que caben en la nueva matriz.
     * \param nuevasFilas Nueva cantidad de filas.
     * \param nuevasColumnas Nueva cantidad de columnas.
     * \throw const char* Si falla la memoria.
     */
    void Redimensionar(int nuevasFilas, int nuevasColumnas);

    // --- Operadores (M&eacute;todos expl&iacute;citos) ---

    /**
     * \brief Realiza la suma de dos matrices.
     * \param m2 Matriz a sumar.
     * \return Matriz resultante de la suma.
     * \throw const char* Si las dimensiones son incompatibles.
     */
    Matriz SumarMatrices(const Matriz &m2) const;

    /**
     * \brief Realiza la resta de dos matrices.
     * \param m2 Matriz a restar.
     * \return Matriz resultante de la resta.
     * \throw const char* Si las dimensiones son incompatibles.
     */
    Matriz RestarMatrices(const Matriz &m2) const;

    /**
     * \brief Realiza el producto matricial.
     * \param m2 Matriz por la cual multiplicar.
     * \return Matriz resultante.
     * \throw const char* Si las columnas de A no coinciden con las filas de B.
     */
    Matriz ProductoMatrices(const Matriz &m2) const;

    /**
     * \brief Multiplica la matriz por un escalar.
     * \param escalar N&uacute;mero por el cual multiplicar.
     * \return Matriz resultante.
     */
    Matriz MultiplicarEscalar(float escalar) const;


    // --- M&eacute;todos para calcular... ---

    /**
     * \brief Calcula la transpuesta de la matriz.
     * \return Nueva Matriz transpuesta.
     */
    Matriz MatrizTrans() const;

    /**
     * \brief Calcula la inversa de la matriz usando Gauss-Jordan.
     * \return Nueva Matriz inversa.
     * \throw const char* Si la matriz no es cuadrada o su determinante es 0.
     */
    Matriz MatrizInversa() const;


    // --- Sobrecarga de operadores ---

    /**
     * \brief Operador de asignaci&oacute;n.
     * \param m Matriz a asignar.
     * \return Referencia a la matriz actual (*this).
     */
    Matriz& operator=(const Matriz &m);

    /**
     * \brief Operador de suma (+).
     */
    Matriz operator+(const Matriz &m2) const;

    /**
     * \brief Operador de resta (-).
     */
    Matriz operator-(const Matriz &m2) const;

    /**
     * \brief Operador de multiplicaci&oacute;n matricial (*).
     */
    Matriz operator*(const Matriz &m2) const;

    /**
     * \brief Operador de multiplicaci&oacute;n por escalar (*).
     */
    Matriz operator*(float escalar) const;

    /**
     * \brief Operador de acceso indizado (lectura/escritura).
     * \param i &Iacute;ndice de fila.
     * \return Puntero al arreglo de la fila.
     * \throw const char* Si el &iacute;ndice est&aacute; fuera de rango.
     */
    float* operator[](int i);

    /**
     * \brief Operador de acceso indizado (solo lectura).
     * \param i &Iacute;ndice de fila.
     * \return Puntero constante al arreglo de la fila.
     * \throw const char* Si el &iacute;ndice est&aacute; fuera de rango.
     */
    const float* operator[](int i) const;


private:
    /**
     * \brief Valida y asigna las dimensiones de la matriz.
     * \param filas Cantidad de filas.
     * \param columnas Cantidad de columnas.
     * \throw const char* Si las dimensiones son menores a 1.
     */
    void EstablecerDimensiones(int filas, int columnas);

    int filas;     ///< Cantidad de filas.
    int columnas;  ///< Cantidad de columnas.
    float** entrada;        ///< Puntero doble para el manejo de memoria din&aacute;mica.

};

#endif // MATRIZ_HPP_INCLUDED
