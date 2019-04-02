
#include "DNI.hpp"

unsigned long int DNI::comparaciones = 0;
/*!
* se incializa el tamaño y se alamcena en dni el número que se genera de manera aleatoria
*/
DNI::DNI(): size(8){

    dni = rand()%MAX;

}

/*!
* Develve el tamaño del DNI
*/
int DNI::getsize()const{
  return size;
}


/*!
* Compara un dni con otro
*/
bool DNI::operator==(const DNI& rhs){

  comparaciones++;
  return(this -> dni == rhs.getdni())? true : false;

}

/*!
* Le pasamos un flujo de salida (ostream) y un DNI, y muestra el dni.
* Si el número almacenado (dni) es menor de 8 dígitos, setfill completa los dígitos restantes con '0'
* y setw (set width) le dice cual es el máximo de dígitos.
*/
std::ostream& operator<< (std::ostream& os, const DNI& obj){

 os << std::setfill('0') << std::setw(8) << obj.dni;
 return os;

}

/*!
* Devuelve las comparaciones
*/
 unsigned long int DNI::getcomp(){
  return comparaciones;
}

/*!
* Resetea las comparaciones
*/
void DNI::clearcomp(){
  comparaciones = 0;
}

/*!
* devuelve el dni, que ya es un unsigned int
*/
DNI::operator unsigned int(){return dni;}

/*!
* devuelve el dni para los DNI constantes
*/
DNI::operator unsigned int()const{return dni;}
