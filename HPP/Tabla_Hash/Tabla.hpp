#pragma once

///////////LIBRERIAS DE LA TABLA///////////
#include "Celdas.hpp"

///////////LIBRERIAS DE FUNCIONES DE DISPERSIÓN///////////
#include "fdispersionsuma.h"
#include "fdispersionmodulo.h"
#include "fdispersionaleatoria.h"

///////////LIBRERIAS DE FUNCIONES DE EXPLORACIÓN///////////
#include "fexploracionlineal.h"
#include "fexploracioncuadratica.h"

using namespace std;

class TablaHash{

  private:

    vector<CELDAS<DNI>> Tabla;      //vector de celdas
    vector<int> visitadas;          //vector de posiciones visitadas
    int RowSize;                    //tamaño de las filas
    int CellSize;                   //número de las celdas
    fdispersionbase* fdispersion;   //función de dispersión a usar
    fexploracionbase* fexploracion; //función de exploración a usar
    float factordecarga;            //factor de carga

  public:


    ///////////CONSTRUCTOR/////////////////////////////////

    ///Constructor de la clase
    TablaHash(int RowS, int CellS,char* dispersion,char* exploracion,float fc);

    ///////////FUNCIONES DE MODIFICACIÓN Y BUSQUEDA///////////

    ///Carga en la tabla los DNI iniciales
    void LoadTable(int tam,vector<DNI>& nums);
    ///Busca en la tabla
    bool Buscar(DNI& key);
    ///Inserta en la tabla
    bool Insertar(DNI& key);
    ///Lleva la cuenta de las filas de celdas que se han visitado
    bool visitada(int i);

    ///////////////////////////////////////////////////////////

};
