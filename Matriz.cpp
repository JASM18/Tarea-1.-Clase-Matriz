/**
 * \file Matriz.cpp
 * \brief Implementaci&oacute;n de los m&eacute;todos de la clase Matriz.
 * \authors Jes&uacute;s Axel Sanchez Montoy y Marian Bethsabe Portugal Arreola
 * \date 10/02/2026
 *
 */

#include "Matriz.hpp"
#include "Aleatorio.hpp"
#include "CapturaSegura.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setprecision;
using std::fixed;

// C&oacute;digos ASCII para bordes
enum {BV = 179, ESD = 191, EII = 217, EID = 192, ESI = 218};

//**********************************
// CONSTRUCTORES
//**********************************

Matriz::Matriz(int filas, int columnas)
{
    EstablecerDimensiones(filas, columnas);

    try{
        entrada = new float *[filas]; // Se crea un arreglo dinamico tal que tama&ntilde;o del arreglo es la cantidad de filas que hay

        // 2. RECORREMOS CADA FILA (usamos i < filas)
        for(int i = 0 ; i < filas ; ++i){ // Se recorre CADA FILA (el i va a recorrer cada fila)

            entrada[i] = new float [columnas]; // A cada fila le asignamos sus columas. La fila 'i' tendr&aacute; 'columnas' espacios para n&uacute;meros

            for(int j = 0 ; j < columnas ; ++j){ // Para la fila 'i', vamos a recorrer cada una de sus columnas para asignarle '0'
                entrada[i][j] = 0;
            }
        }

    }catch(std::bad_alloc &){
        throw "Error en la asignaci\242n de memoria\n";
    }
}

//**********************************

Matriz::~Matriz()
{
    // Como en el constructor se define la matriz como un arreglo de arreglos, para destruirlo primero...
    // primero hay que elimiar los arreglos que ESTAN ADENTRO del arreglo principal...
    // Entonces como el arreglo principal representa la cantidad de filas que hay, lo que hay que hacer...
    // es recorrer cada indice de las filas para eliminar los arreglos de las columnas

    for(int i = 0 ; i < filas ; ++i){ // Liberamos la memoria de cada fila individualmente
        delete[] entrada[i]; // Borramos el arreglo de la fila 'i'ecima.
    }
    delete[] entrada; // Liberamos el arreglo que conten&iacute;a los arreglos (el arreglo de filas)
}

Matriz::Matriz(const Matriz &m) : filas(0), columnas(0), entrada(nullptr)
{
    *this = m;

}

//**********************************
// FUNCIONES DE OBTENCION
//**********************************

int Matriz::ObtenerNumFilas() const
{
    return filas;
}

//**********************************

int Matriz::ObtenerNumColumnas() const
{
    return columnas;
}

//**********************************

float Matriz::ObtenerEntrada(int fila, int columna) const
{
    return entrada[fila][columna];
}

//**********************************
// Captura y salida
//**********************************

void Matriz::CapturaManual()
{
    cout << "\n";
    for(int i = 0 ; i < filas ; ++i){

        for(int j = 0 ; j < columnas ; ++j){
            cout << "Entrada [" << i+1 << "][" << j+1 << "]: ";
            CapturarNumero(entrada[i][j], "");
        }

    }
}

//**********************************

void Matriz::CapturaAleatoria()
{
    for(int i = 0 ; i < filas ; ++i){

        for(int j = 0 ; j < columnas ; ++j){
            entrada[i][j] = aleatorio(-10,10);
        }

    }
}

//**********************************

void Matriz::Imprimir() const
{
    cout << endl;
    cout << (char)ESI;
    for(int i = 0 ; i <= columnas ; ++i){
        cout << "\t";
    }
    cout << (char)ESD << endl;

    for(int i = 0 ; i < filas ; ++i){
        cout << (char)BV;

        for(int j = 0 ; j < columnas ; ++j){

            float valor = entrada[i][j];

            if(valor == (int)valor) {
                cout << setw(8) << (int)valor; // Imprime sin decimales
            }else{
                cout << setw(8) << fixed << setprecision(2) << valor; // Imprime con 2 decimales
            }
        }

        cout << "\t" << (char)BV;
        cout << endl;
    }

    cout << (char)EID;
    for(int i = 0 ; i <= columnas ; ++i){
        cout << "\t";
    }
    cout << (char)EII << endl;
}


//**********************************
// Modificaciones de la matriz
//**********************************

void Matriz::EstablecerDimensiones(int filas, int columnas)
{
    if(filas < 1 || columnas < 1){
        throw "Dimensi\242nes inv\240lidas";
    }

    this->filas = filas;
    this->columnas = columnas;
}


//**********************************

void Matriz::EstablecerEntrada(int fila, int columna, float valor)
{
    if(fila < 0 || columna < 0){
        throw "\326ndice fuera de rango";
    }
    entrada[fila][columna] = valor;
}

//**********************************

void Matriz::Redimensionar(int nuevasFilas, int nuevasColumnas)
{
    if(filas == nuevasFilas && columnas == nuevasColumnas) return;

    float** temp = nullptr;
    try{
        temp = new float*[nuevasFilas]; // Arreglo de PUNTEROS (float**)

        for(int i = 0; i < nuevasFilas; ++i) {
            temp[i] = new float[nuevasColumnas];

            // Inicializamos todo en 0 para evitar basura en las celdas nuevas
            for(int j = 0; j < nuevasColumnas; ++j) {
                temp[i][j] = 0;
            }
        }
    } catch(std::bad_alloc&) {
        throw "Error de memoria al redimensionar";
    }

    // COPIAR los datos que quepan (Intersecci&oacute;n)
    // El l&iacute;mite de copia es el MENOR entre la dimensi&oacute;n vieja y la nueva
    int limiteFilas = (filas < nuevasFilas) ? filas : nuevasFilas;
    int limiteCols = (columnas < nuevasColumnas) ? columnas : nuevasColumnas;

    for(int i = 0; i < limiteFilas; ++i) {
        for(int j = 0; j < limiteCols; ++j) {
            temp[i][j] = entrada[i][j]; // Copiamos dato viejo a la nueva casa
        }
    }

    for(int i = 0; i < filas; ++i) {
        delete[] entrada[i];
    }
    delete[] entrada;

    entrada = temp;
    filas = nuevasFilas;
    columnas = nuevasColumnas;
}

//**********************************
// Operadores (No sobrecargados)
//**********************************

Matriz Matriz::SumarMatrices(const Matriz &m2) const
{
    if (filas != m2.filas || columnas != m2.columnas){
        throw "Dimensiones incompatibles para suma";
    }
    Matriz resultado(filas, columnas);

    for(int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            resultado.entrada[i][j] = entrada[i][j] + m2.entrada[i][j];
        }
    }

    return resultado;
}

//**********************************

Matriz Matriz::RestarMatrices(const Matriz &m2) const
{
    if (filas != m2.filas || columnas != m2.columnas){
        throw "Dimensiones incompatibles para resta";
    }

    Matriz resultado(filas, columnas);

    for(int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            resultado.entrada[i][j] = entrada[i][j] - m2.entrada[i][j];
        }
    }

    return resultado;
}

//*********************************

Matriz Matriz::ProductoMatrices(const Matriz &m2) const
{
    if(this->columnas != m2.filas){
        throw "Dimensiones incompatibles para la multiplicaci\242n";
    }

    Matriz resultado(this->filas, m2.columnas);

    for(int i = 0; i < (*this).filas; i++){
        for(int j = 0; j < m2.columnas; j++){
            for(int k = 0; k < (*this).columnas; k++){
                resultado[i][j] += (*this)[i][k]*m2[k][j];
            }
        }
    }

    return resultado;
}

Matriz Matriz::MultiplicarEscalar(float escalar) const // Multiplica una matriz por escalar
{
    Matriz resultado(filas, columnas);

    for(int i = 0 ; i < filas ; ++i){
        for(int j = 0 ; j < columnas ; ++j){
            resultado.entrada[i][j] = escalar * entrada[i][j];
        }
    }

    return resultado;
}

//**********************************
// Metodos para calcular...
//**********************************

Matriz Matriz::MatrizTrans() const
{
    Matriz resultado(this->columnas, this->filas);

    for(int i = 0; i < this->filas; i++){
        for (int j = 0; j < this->columnas; j++){
            resultado.entrada[j][i] = this->entrada[i][j];
        }
    }

    return resultado;
}

//**********************************

Matriz Matriz::MatrizInversa() const
{
    if(this->columnas != this->filas)
        throw "La matriz no es cuadrada, entonces no tiene inversa.";

    int n = this->filas;

    Matriz Aumentada(n, n * 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Aumentada.entrada[i][j] = entrada[i][j];
        }

        for (int j = n; j < 2 * n; j++) {
            if (i == (j - n)) {
                Aumentada.entrada[i][j] = 1;
            } else {
                Aumentada.entrada[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {

        if (Aumentada.entrada[i][i] == 0) {

            int filaCambio = i + 1;

            while (filaCambio < n && Aumentada.entrada[filaCambio][i] == 0) {
                filaCambio++;
            }

            if (filaCambio == n) {
                throw "El determinante de la matriz es cero, por lo que no tiene inversa.";
            }

            float* temporal = Aumentada.entrada[i];
            Aumentada.entrada[i] = Aumentada.entrada[filaCambio];
            Aumentada.entrada[filaCambio] = temporal;
        }

        float pivote = Aumentada.entrada[i][i];

        for (int j = 0; j < 2 * n; j++) {
            Aumentada.entrada[i][j] /= pivote;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = Aumentada.entrada[k][i];

                for (int j = 0; j < 2 * n; j++) {
                    Aumentada.entrada[k][j] -= factor * Aumentada.entrada[i][j];
                }
            }
        }
    }

    Matriz resultado(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado.entrada[i][j] = Aumentada.entrada[i][j + n];
        }
    }

    return resultado;
}

//**********************************
// Operadores (Sobrecargados)
//**********************************

Matriz& Matriz::operator=(const Matriz &m)
{
    if(this == &m){
        return *this;
    }

    if(entrada != nullptr) { /// Si hay memoria asignada, entonces procedemos a borrarla
        for(int i = 0 ; i < filas ; ++i){
            delete[] entrada[i];
        }
        delete[] entrada;
    }

    this->EstablecerDimensiones(m.filas, m.columnas);

    try{
        entrada = new float *[filas]; /// Se crea un arreglo dinamico tal que tama&ntilde;o del arreglo es la cantidad de filas que hay

        // 2. RECORREMOS CADA FILA (usamos i < filas)
        for(int i = 0 ; i < filas ; ++i){ /// Se recorre CADA FILA (el i va a recorrer cada fila)

            entrada[i] = new float [columnas]; /// A cada fila le asignamos sus columas. La fila 'i' tendr&aacute; 'columnas' espacios para n&uacute;meros

            for(int j = 0 ; j < columnas ; ++j){ /// Para la fila 'i', vamos a recorrer cada una de sus columnas para asignarle '0'
                entrada[i][j] = m.entrada[i][j];
            }
        }

    }catch(std::bad_alloc &){
        throw "Error en la asignaci\242n de memoria\n";
    }

    return *this;
}

//**********************************

Matriz Matriz::operator+(const Matriz &m2) const
{
    Matriz resultante = this->SumarMatrices(m2);

    return resultante;
}

Matriz Matriz::operator-(const Matriz &m2) const
{
    Matriz resultado = (*this).RestarMatrices(m2);

    return resultado;
}

Matriz Matriz::operator*(const Matriz &m2) const
{
    Matriz resultado = (*this).ProductoMatrices(m2);

    return resultado;
}

Matriz Matriz::operator*(float escalar) const
{
    return (*this).MultiplicarEscalar(escalar);
}

Matriz operator*(float escalar, const Matriz m)
{
    return m.MultiplicarEscalar(escalar);
}



float* Matriz::operator[](int i)
{
    if(i < 0 || i >= filas) throw "\326ndice fuera de rango";
    return entrada[i];
}

//**********************************

const float* Matriz::operator[](int i) const
{
    if(i < 0 || i >= filas) throw "\326ndice fuera de rango";
    return entrada[i];
}


//**********************************
// Flujos sobrecargados de entrada y salida
//**********************************

std::ostream & operator<<(std::ostream & salida, const Matriz &m)
{
    m.Imprimir();
    return salida;
}

//**********************************

std::istream & operator>>(std::istream & entrada, Matriz &m)
{
    m.CapturaManual();
    return entrada;
}
