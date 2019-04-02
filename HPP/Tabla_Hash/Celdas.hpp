#pragma once

///////////LIBRERIAS///////////
#include <vector>
#include "DNI.hpp"

template <class T>
class CELDAS{

  private:

    int NumCells;  //Número de celdas
    int FullCells; //Celdas que ya están completas
    std::vector<T> Cells; //vector de DNI's que almacena las celdas

  public:

    /// Constructor de la clase
    CELDAS(int NCeldas): FullCells(0),NumCells(NCeldas),Cells(NCeldas){}

    CELDAS(const CELDAS& old_obj);

    //////////////FUNCIONES DE CONTROL//////////////

    ///Número de Celdas
    int size(){return NumCells;}
    ///Muestra por pantalla la celda pasada por parámetro
    void ver(int i);
    ///Comprueba si todas las celdas están rellenas
    bool Full();
    
    //////////////FUNCIONES DE INTERACCIÓN//////////////

    ///Buscar una clave en las celdas
    bool buscar(T key);
    ///Insertar una clave en las celdas
    bool insertar(T key);

    //////////////OPERATORS OVERLOADED//////////////
    friend std::ostream& operator<<(std::ostream& os, const CELDAS& obj){
        for(int i=0;i<obj.NumCells;i++){
          os << obj.Cells[i] << "\n";
        }
        return os;
    }

};



template <class T>
CELDAS<T>::CELDAS(const CELDAS<T>& old_obj){

  NumCells = old_obj.NumCells;
  FullCells = 0;
  Cells = old_obj.Cells;

}


template <class T>
/*!
* Comprueba si el número actual de celdas es igual al número total de celdas que existen, devolviendo verdadero o falso.
*/
bool CELDAS<T>::Full(){
  return(FullCells == NumCells)? true : false;
}


template <class T>
/*!
* En caso de que no estén todas las celdas completas, se le añade al vector de claves la clave introducida y se aumentan el tamaño de celdas ocupadas (FullCells), en caso
* de que no se pueda introducir esta función devuelve falso, verdadero si la introduce.
*/
bool CELDAS<T>::insertar(T key){

    if(!Full()){

    Cells[FullCells] = key;
    FullCells++;

    return true;
  }

  return false;
}

template <class T>
/*!
* Recorre todas las celdas que están ocupadas, comprobando si la celda es igual a la clave dada, en tal caso devuelve verdadero (Ha encontrado la clave), si no la encuentra devuelve falso.
*/
bool CELDAS<T>::buscar(T key){
  for(int i=0;i<FullCells;i++){
    if(Cells[i] == key)
    return true;
  }
  return false;
}

template <class T>
/*!
* Dado una celda (i), muestra la clave que hay en ella haciendo uso de la función ver de la clase DNI.
*/
void CELDAS<T>::ver(int i){
  Cells[i].ver();
}
