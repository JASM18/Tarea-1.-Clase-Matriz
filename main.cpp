/**
 * \file main.cpp
 * \brief Punto de entrada de la aplicaci&oacute;n.
 * \authors Jes&uacute;s Axel Sanchez Montoy y Marian Bethsabe Portugal Arreola
 * \date 10/02/2026
 * Contiene el men&uacute; principal para navegar entre las distintas funcionalidades
 * del proyecto Matriz.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "CapturaSegura.hpp"
#include "Gestion.hpp"

using namespace std;

/**
 * \brief Opciones del men&uacute; principal.
 */
enum Opciones_principales {
    DEFINIR_E_IMPRIMIR_MATRICES = 1,    /// Opci&oacute;n para ir a la gesti&oacute;n de definir e imprimir matrices.
    OPERACIONES,                        /// Opci&oacute;n para ir a la gesti&oacute;n de operaciones.
    TESTEO,                             /// Opci&oacute;n  para ir a la gesti&oacute;n de testeo.
    SALIR                               /// Opci&oacute;n para salir del programa
};

/**
 * \brief Funci&oacute;n principal del programa.
 * \return 0 si la ejecuci&oacute;n fue exitosa.
 */
int main()
{

    int opcion = -1;

    srand(time(NULL));

    do{
        cout << "====================" << endl;
        cout << "Tarea 1. Clase Matriz" << endl;
        cout << "====================" << endl << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << DEFINIR_E_IMPRIMIR_MATRICES << ") Solo define una matriz y la imprime" << endl;
        cout << "\t" << OPERACIONES << ") Operaciones con matrices" << endl;
        cout << "\t" << TESTEO << ") \265rea de testeo" << endl;
        cout << "\t" << SALIR << ") Salir del programa" << endl;

        do{
            CapturarNumero(opcion, "Elige una opci\242n: ");
        }while(opcion > SALIR || opcion < DEFINIR_E_IMPRIMIR_MATRICES);

        if(opcion == SALIR) continue;

        try{
            switch(opcion){

                case DEFINIR_E_IMPRIMIR_MATRICES:
                    GDefiniEImprime();
                break;
                case OPERACIONES:
                    GOperaciones();
                break;
                case TESTEO:
                    GTesteo();
                break;
            }
        }catch(const char *mensaje){
            cerr << "\nERROR: " << mensaje << endl;
        }catch(...) {
            cerr << "\nERROR: Ocurri\242 un error inesperado." << endl;
        }

        system ("pause");
        system("CLS");
    }while(opcion != SALIR);

    cout << "\nEl programa ha terminado." << endl;

    system("pause");
    return 0;
}
