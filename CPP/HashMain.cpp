
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

   unsigned int min,max=0,acc=0;
   table.Buscar(TestDNI[0]);
   min = DNI::getcomp();

  bool n;

  for(int i=0; i<N;i++){
    n = table.Buscar(TestDNI[rand()%N]);
    if(!n)
      std::cout << "Perdido\n";

      if((DNI::getcomp()- acc) > max)
        max = DNI::getcomp() - acc;

      acc = DNI::getcomp();
  }
std::cout << "min: " << min << "\n";
std::cout << "max: " << max << "\n";
std::cout << "acc: " << acc << "\n";

DNI::clearcomp();
table.Buscar(TestDNI[N]);
min = DNI::getcomp();
min=0;max=0;acc=0;

for(int i=0;i<N;i++){

    table.Buscar(TestDNI[N+rand()%N]);

    if(DNI::getcomp() - acc < min)
      min = DNI::getcomp() - acc;
    if(DNI::getcomp() - acc > max)
      max = DNI::getcomp() - acc;

    acc = DNI::getcomp();
}

std::cout << "min: " << min << "\n";
std::cout << "max: " << max << "\n";
std::cout << "acc: " << acc << "\n";

//Busca los valores en la tabla comprobando que realmente se han introducido
/*
  bool n;

  for(int i=0;i<N;i++){
    std::cout << "i: " << i << "\n";
    n = table.Buscar(TestDNI[i]);
}
std::cout << "Comparaciones: " << DNI::getcomp();
*/
//obtiene el tiempo que se ha estado ejecutando y le resta el tiempo que ha tardado en crear los dni
time = clock() - time;
std::cout << "tiempo consumido para la carga de la tabla: " << ((float)time)/CLOCKS_PER_SEC << " segundos.\n";

}

}
