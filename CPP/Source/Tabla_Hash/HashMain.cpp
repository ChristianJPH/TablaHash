
///////////LIBRERIAS///////////
#include<iostream>
#include<cstdlib>
#include<string>
#include <stdlib.h>
#include <vector>
#include <time.h>
/////////////////////////////////

///////////////////////////////
//      DEMO DE MAIN         //
///////////////////////////////


///////////TABLA_HASH///////////
#include "Tabla.hpp"


int main(int argc, char* argv[]){
  //Comprueba que se introducen 7 argumentos
  if(argc != 7){

    std::cout << "Usage: Celdas  nClaves     dispersión exploración      Carga       Pruebas\n";
    return -1;

  }else{
    //variable para contar el tiempo
  clock_t time;

  //calcula N
  int N = atof(argv[5]) * stoi(argv[1]) * stoi(argv[2]);
  std::vector<DNI> TestDNI(2*N);

  //obtiene el tiempo que se ha estado ejecutando el programa hasta ahora
  time = clock();
  std::cout << "tiempo consumido para la creación de los dni: " << ((float)time)/CLOCKS_PER_SEC << " segundos.\n";

  //constructor de la tabla
  TablaHash table(stoi(argv[1]),stoi(argv[2]),argv[3],argv[4],atof(argv[5]));
  //carga la tabla con los N dni
  table.LoadTable(N,TestDNI);

//Busca los valores en la tabla comprobando que realmente se han introducido
  bool n;
  for(int i=0;i<N;i++){

    n = table.Buscar(TestDNI[i]);
    if(n)
      std::cout << "Encontrado\n";
    else
      std::cout << "Perdido\n";

}

//obtiene el tiempo que se ha estado ejecutando y le resta el tiempo que ha tardado en crear los dni
time = clock() - time;
std::cout << "tiempo consumido para la carga de la tabla: " << ((float)time)/CLOCKS_PER_SEC << " segundos.\n";

}

}
