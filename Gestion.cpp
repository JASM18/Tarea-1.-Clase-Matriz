/**
 * \file Gestion.cpp
 * \brief Implementaci&oacute;n de la l&oacute;gica de men&uacute;s y pruebas.
 * \authors Jes&uacute;s Axel Sanchez Montoy y Marian Bethsabe Portugal Arreola
 * \date 10/02/2026
 *
 */

#include <iostream>

#include "CapturaSegura.hpp"
#include "Gestion.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::bad_alloc;
using std::cerr;

//**********************************
// MENUS PRINCIPALES
//**********************************

void GDefiniEImprime()
{
    system("CLS");

    cout << "====================" << endl;
    cout << "Define e imprime una matriz" << endl;
    cout << "====================" << endl << endl;

    cout << "\250Que hace este apartado?" << endl;
    cout << "-> Se va a definir una matriz constante 'm' para luego imprimirse con el objetivo de demostrar el funcionamiento del constructor por default" << endl;
    cout << "-> Se va a definir una matriz 'n' en donde el usuario puede definirla como lo desee" << endl;
    cout << "-> Las entradas pueden ser asignadas de forma manual o aleatoria" << endl << endl;

    system("pause");
    system("CLS");

    cout << "====================" << endl;
    cout << "Define e imprime una matriz" << endl;
    cout << "====================" << endl << endl;

    try{
        const Matriz m;

        cout << "m = " << m;

        system("pause");
        system("CLS");

        cout << "====================" << endl;
        cout << "Define e imprime una matriz" << endl;
        cout << "====================" << endl << endl;

        Matriz n;

        DefinirMatriz(n);

        cout << n;
    }catch(const char* mensaje){
        cerr << "\nERROR: " << mensaje << endl;
    }catch(bad_alloc&){
        cerr << "\nERROR: No hay suficiente memoria RAM." << endl;
    }catch(...){
        cerr << "\nERROR: Ocurrio un error inesperado." << endl;
    }

}

//**********************************

void GOperaciones()
{
    // Esta gestion es para poner a prueba los operadores como la suma o la multiplicacion de matrices
    int opcion = -1, escalar, opcion_matriz, i, j;
    system("CLS");

    cout << "====================" << endl;
    cout << "Operaciones con matrices" << endl;
    cout << "====================" << endl << endl;

    cout << "\250Que hace este apartado?" << endl; // \250 = ¿
    cout << "-> Realiza diferentes tipos de operaciones con dos matrices A y B\n" << endl;

    try{
        Matriz A, B, C;

        cout << "Define la matriz A:" << endl;
        DefinirMatriz(A);
        cout << "A = " << A << endl;

        cout << "Define la matriz B:" << endl;
        DefinirMatriz(B);
        cout << "B = " << B << endl;

        system("pause");
        system("CLS");

        do{

            cout << "====================" << endl;
            cout << "Operaciones con matrices" << endl;
            cout << "====================" << endl << endl;

            cout << "A = " << A << endl;
            cout << "B = " << B << endl;

            cout << "Operaciones:" << endl;
            cout << "\t" << SUMA << ") Suma de dos matrices A+B" << endl;
            cout << "\t" << RESTA << ") Resta de dos matrices A-B" << endl;
            cout << "\t" << PRODUCTO_MATRICIAL << ") Producto de dos matrices A*B" << endl;
            cout << "\t" << PRODUCTO_ESCALAR << ") Producto de una matriz por un escalar a*A" << endl;
            cout << "\t" << ACCESO_ENTRADAS << ") Acceso indizado a las entradas de una matriz A[i][j]" << endl;
            cout << "\t" << MODIFICAR_ENTRADAS << ") Modificaci\242n indizada a las entradas de una matriz A[i][j]" << endl;
            cout << "\t" << TRANSPUESTA << ") La transpuesta de una matriz" << endl;
            cout << "\t" << INVERSA << ") La inversa de una matriz cuadrada" << endl;
            cout << "\t" << REDIMENSIONAR << ") Redimensionamiento de una matriz" << endl;
            cout << "\t" << REDEFINIR << ") Redefinir la matriz (por si el cliente desea redefinir A o B)" << endl;
            cout << "\t" << SALIR_OP << ") Salir al menu" << endl;

            do{
                CapturarNumero(opcion, "Elige una opci\242n: ");
            }while(opcion > SALIR_OP || opcion < SUMA);

            if(opcion == SALIR_OP) continue;

            switch(opcion){

                case SUMA:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "SUMA" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\nCalculando A + B..." << endl;
                    try {
                        C = A + B;
                        cout << A << "+" << B << "=" << C;
                    } catch(const char* mensaje) {
                        cerr << "Error en SUMA: " << mensaje << endl;
                    }
                break;
                case RESTA:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "RESTA" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\nCalculando A - B..." << endl;
                    try {
                        C = A - B;
                        cout << A << "-" << B << "=" << C;
                    } catch(const char* mensaje) {
                        cerr << "Error en RESTA: " << mensaje << endl;
                    }
                break;
                case PRODUCTO_MATRICIAL:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "PRODUCTO MATRICIAL" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\nCalculando A * B..." << endl;
                    try {
                        C = A * B;
                        cout << A << "*" << B << "=" << C;
                    } catch(const char* mensaje) {
                        cerr << "Error en PRODUCTO: " << mensaje << endl;
                    }
                break;
                case PRODUCTO_ESCALAR:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "PRODUCTO POR ESCALAR" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\nCalculando el producto por escalar..." << endl;

                    cout << "Se va a probar Matriz*escalar y escalar*Matriz para demostrar la conmutatividad" << endl;

                    try {
                        cout << "\n-----> Trabajando con A <-----" << endl;

                        CapturarNumero(escalar, "Introduce el escalar para A: ");

                        C = A*escalar;
                        cout << "A * " << escalar << " = " << C;

                        C = escalar*A;
                        cout << escalar << " * A = " << C;


                        cout << "\n-----> Trabajando con B <-----" << endl;

                        CapturarNumero(escalar, "Introduce el escalar para B: ");

                        C = B*escalar;
                        cout << "B * " << escalar << " = " << C;

                        C = escalar*B;
                        cout << escalar << " * B = " << C;


                    } catch(const char* mensaje) {
                        cerr << "Error en REESCALADO: " << mensaje << endl;
                    }
                break;
                case ACCESO_ENTRADAS:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "Acceso a las entradas" << endl;
                    cout << "====================" << endl << endl;

                    cout << "-> Nota: el indice de filas esta protegido desde la sobrecarga del operator[], pero las columnas no estaran protegidas" << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\250Con cual matriz se desea operar?" <<endl;
                    cout << "\t"<< MatrizA << ") Matriz A" << endl;
                    cout << "\t" << MatrizB << ") Matriz B" << endl;

                    do{
                        CapturarNumero(opcion_matriz, "Elige una opci\242n: ");
                    }while(opcion_matriz > MatrizB || opcion_matriz < MatrizA);

                    try{

                        if(opcion_matriz == MatrizA){

                            cout << "Introduce la entrada A[fila][columna]" << endl;
                            CapturarNumero(i, "Fila: ");
                            CapturarNumero(j, "Columna: ");

                            cout << "A[" << i << "][" << j << "] = " << A[i-1][j-1] << endl;


                        }else{

                            cout << "Introduce la entrada B[fila][columna]" << endl;
                            CapturarNumero(i, "Fila: ");
                            CapturarNumero(j, "Columna: ");

                            cout << "B[" << i << "][" << j << "] = " << B[i-1][j-1] << endl;

                        }

                    } catch(const char* mensaje) {
                        cerr << "Error de indice: " << mensaje << endl;
                    }

                break;
                case MODIFICAR_ENTRADAS:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "Modificar una entrada A[i][j] = valor" << endl;
                    cout << "====================" << endl << endl;

                    cout << "-> Nota: el indice de filas esta protegido desde la sobrecarga del operator[], pero las columnas no estaran protegidas" << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\250Con cual matriz se desea operar?" <<endl;
                    cout << "\t"<< MatrizA << ") Matriz A" << endl;
                    cout << "\t" << MatrizB << ") Matriz B" << endl;

                    do{
                        CapturarNumero(opcion_matriz, "Elige una opci\242n: ");
                    }while(opcion_matriz > MatrizB || opcion_matriz < MatrizA);

                    try{

                        float nuevoValor;

                        if(opcion_matriz == MatrizA){

                            cout << "Introduce la entrada A[fila][columna]" << endl;
                            CapturarNumero(i, "Fila: ");
                            CapturarNumero(j, "Columna: ");

                            cout << "Valor actual en A[" << i << "][" << j << "] es: " << A[i-1][j-1] << endl;

                            cout << "Ingresa el NUEVO valor: ";
                            cin >> nuevoValor;

                            A[i-1][j-1] = nuevoValor;

                            cout << "\nCambio realizado exitosamente." << endl;
                            cout << "A[" << i << "][" << j << "] ahora vale: " << A[i-1][j-1] << endl;


                        }else{

                            cout << "Introduce la entrada B[fila][columna]" << endl;
                            CapturarNumero(i, "Fila: ");
                            CapturarNumero(j, "Columna: ");

                            cout << "Valor actual en B[" << i << "][" << j << "] es: " << B[i-1][j-1] << endl;

                            cout << "Ingresa el NUEVO valor: ";
                            cin >> nuevoValor;

                            B[i-1][j-1] = nuevoValor;

                            cout << "\nCambio realizado exitosamente." << endl;
                            cout << "B[" << i << "][" << j << "] ahora vale: " << B[i-1][j-1] << endl;

                        }

                    }catch(const char* mensaje){
                        cerr << "Error de indice: " << mensaje << endl;
                    }

                break;
                case TRANSPUESTA:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "Matriz transpuesta" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\250Cual matriz se desea sacar la transpuesta?" <<endl;
                    cout << "\t"<< MatrizA << ") Matriz A" << endl;
                    cout << "\t" << MatrizB << ") Matriz B" << endl;

                    do{
                        CapturarNumero(opcion_matriz, "Elige una opci\242n: ");
                    }while(opcion_matriz > MatrizB || opcion_matriz < MatrizA);

                    try{

                        Matriz C;

                        if(opcion_matriz == MatrizA){

                            C = A.MatrizTrans();
                            cout << "A^T = " << C;

                        }else{

                            C = B.MatrizTrans();
                            cout << "B^T = " << C;
                        }

                    } catch(const char* mensaje) {
                        cerr << "Error: " << mensaje << endl;
                    }

                break;
                case INVERSA:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "Matriz inversa" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\250Cual matriz se desea invertir?" <<endl;
                    cout << "\t"<< MatrizA << ") Matriz A" << endl;
                    cout << "\t" << MatrizB << ") Matriz B" << endl;

                    do{
                        CapturarNumero(opcion_matriz, "Elige una opci\242n: ");
                    }while(opcion_matriz > MatrizB || opcion_matriz < MatrizA);

                    try{

                        Matriz C;

                        if(opcion_matriz == MatrizA){

                            C = A.MatrizInversa();
                            cout << "A^(-1) = " << C;

                        }else{

                            C = B.MatrizInversa();
                            cout << "B^(-1) = " << C;
                        }

                    } catch(const char* mensaje) {
                        cerr << "Error: " << mensaje << endl;
                    }

                break;
                case REDIMENSIONAR:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "Redimencionar matrices" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\250Cual matriz se desea redimencionar?" <<endl;
                    cout << "\t"<< MatrizA << ") Matriz A" << endl;
                    cout << "\t" << MatrizB << ") Matriz B" << endl;

                    do{
                        CapturarNumero(opcion_matriz, "Elige una opci\242n: ");
                    }while(opcion_matriz > MatrizB || opcion_matriz < MatrizA);

                    int nuevaFilas, nuevaColumnas;

                    cout << "Ingresa las nuevas dimensiones de la matriz:" << endl;

                    CapturarNumero(nuevaFilas, "Filas: ");

                    CapturarNumero(nuevaColumnas, "Columnas: ");

                    try{

                        if(opcion_matriz == MatrizA){

                            cout << "Matriz A: " << A.ObtenerNumFilas() << "x" << A.ObtenerNumColumnas() << " -> A: " << nuevaFilas << "x" << nuevaColumnas << endl;
                            A.Redimensionar(nuevaFilas, nuevaColumnas);
                            cout << A;

                        }else{
                            cout << "Matriz B: " << B.ObtenerNumFilas() << "x" << B.ObtenerNumColumnas() << " -> B: " << nuevaFilas << "x" << nuevaColumnas << endl;
                            B.Redimensionar(nuevaFilas, nuevaColumnas);
                            cout << B;
                        }

                    } catch(const char* mensaje) {
                        cerr << "Error de indice: " << mensaje << endl;
                    }

                break;
                case REDEFINIR:

                    system("CLS");

                    cout << "====================" << endl;
                    cout << "Redefinir matriz" << endl;
                    cout << "====================" << endl << endl;

                    cout << "A = " << A << endl;
                    cout << "B = " << B << endl;

                    cout << "\250Cual matriz se desea redefinir?" <<endl;
                    cout << "\t"<< MatrizA << ") Matriz A" << endl;
                    cout << "\t" << MatrizB << ") Matriz B" << endl;

                    do{
                        CapturarNumero(opcion_matriz, "Elige una opci\242n: ");
                    }while(opcion_matriz > MatrizB || opcion_matriz < MatrizA);

                    if(opcion_matriz == 1){
                        cout << "\nRedefiniendo la matriz A:" << endl;
                        DefinirMatriz(A);
                        cout << "Matriz A redifinida con exito:" << A;
                    }else{
                        cout << "\nRedefiniendo la matriz B:" << endl;
                        DefinirMatriz(B);
                        cout << "Matriz B redifinida con exito:" << B;
                    }

                break;
            }

            system("pause");
            system("CLS");

        }while(opcion != SALIR_OP);

    }catch(const char* mensaje){
        cerr << "\nERRORRRR: " << mensaje << endl;
    }catch(bad_alloc&){
        cerr << "\nERROR: No hay suficiente memoria RAM." << endl;
    }catch(...){
        cerr << "\nERROR: Ocurrio un error inesperado." << endl;
    }
}

//**********************************

void GTesteo()
{
    // Esta gestion es solo para pruebas

    system("CLS");

    cout << "====================" << endl;
    cout << "Utileria" << endl;
    cout << "====================" << endl << endl;

    cout << "Este apartado es para poder jugar con las matrices desde Gestion.cpp, aqu\241 no hay menu, solo es para poner a prueba algunos metodos." << endl;

    try{
        Matriz A, B;

        DefinirMatriz(A);
        DefinirMatriz(B);

        system("CLS");

        cout << "====================" << endl;
        cout << "Area de testeo" << endl;
        cout << "====================" << endl << endl;

        cout << "Este apartado es para poder jugar con las matrices desde Gestion.cpp, aqu\241 no hay menu, solo es para poner a prueba algunos metodos." << endl;

        cout << "A = " << A;
        cout << "B = " << B;


    }catch(const char* mensaje){
        cerr << "\nERROR: " << mensaje << endl;
    }catch(bad_alloc&){
        cerr << "\nERROR: No hay suficiente memoria RAM." << endl;
    }catch(...){
        cerr << "\nERROR: Ocurrio un error inesperado." << endl;
    }
}

//**********************************
// FUNCIONES AUXILIARES DEL MENU
//**********************************

void DefinirMatriz(Matriz &m)
{
    int fil, col, modo;
    cout << "Ingresa las dimensiones de la matriz:" << endl;

    CapturarNumero(fil, "Filas: ");

    CapturarNumero(col, "Columnas: ");

    m.Redimensionar(fil, col);

    ElegirModoCaptura(modo);

    if(modo == MANUAL){
        cout << "Modo Manual seleccionado." << endl;
        cin >> m;
    }else{
        cout << "Modo Aleatorio seleccionado." << endl;
        m.CapturaAleatoria();
    }
}

//**********************************

void ElegirModoCaptura(int &modo)
{
    cout << "\n> \250Elementos aleatorios o puestos de forma manual?" << endl;
    cout << "\t1) Manual" << endl;
    cout << "\t2) Aleatoria" << endl;
    cout << "Introduce: ";

    CapturarNumero(modo, "");
    while(modo < 1 || modo > 2){
        CapturarNumero(modo, "Error: Introduce una opci\242n val\241da: ");
    }
}
