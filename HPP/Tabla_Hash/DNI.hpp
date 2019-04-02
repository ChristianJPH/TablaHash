#pragma once

///////////LIBRERIAS///////////
#include <sstream>
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
/////////////////////////////////

///////////CONSTANTES///////////
const unsigned int MAX = 99999999;


class DNI{

  private:

    int comp; // Almacena las comparaciones
    unsigned int dni; //Almacena el dni, sólo los núneros
    int size; //tamaño del dni
    static unsigned long int comparaciones; // Veces que se comparan un

  public:

    ///////////CONSTRUCTORES///////////

    ///constructor de la clase
    DNI();

    ///////////FUNCIONES DE CONTROL///////////

    ///devuelve el tamaño del dni
    int getsize()const;
    ///devuelve las comparaciones
    static unsigned long int getcomp();
    ///devuelve el dni
    unsigned int getdni()const{return dni;}

    ///////////SOBRECARGA DE OPERADORES///////////

    ///permite comprobar si un dni es igual a otro
    bool operator==(const DNI& rhs);
    ///transforma el dni en un unsigned int
    operator unsigned int();
    ///transforma un dni constante en un unsigned int
    operator unsigned int()const;
    ///permite utilizar std::cout con los dni
    friend std::ostream& operator<<(std::ostream& os, const DNI& obj);

};
