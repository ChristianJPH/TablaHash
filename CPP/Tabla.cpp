#include "Tabla.hpp"

/*!
* Inicializa EL tamaño de la tabla, inicializa el vector de celdas y detecta la función de exploración y dispersión que se quiere utilizar
*/

TablaHash::TablaHash(int RowS, int CellS,char* dispersion, char* exploracion,float fc): RowSize(RowS), CellSize(CellS), Tabla(RowS,CELDAS<DNI>(CellS)), factordecarga(fc){

  //////////////Funciones de dispersion//////////////
  if(std::string(dispersion) == "suma"){
    fdispersion = new fdispersionsuma(RowS);
  }else if(std::string(dispersion) == "modulo")
    fdispersion = new fdispersionmodulo(RowS);
  else if(std::string(dispersion) == "aleatoria")
    fdispersion = new fdispersionaleatoria(RowS);

  else
std::cout << "Función de dispersión no válida\n";

//////////////Funciones de exploración//////////////
  if(std::string(exploracion) == "lineal")
    fexploracion = new fexploracionlineal(RowS);
  else if(std::string(exploracion) == "cuadratica")
    fexploracion = new fexploracioncuadratica(RowS);

  else
  std::cout << "Función de exploración no válida\n";

}

/*!
* Busca con el índice que devuelve la función de dispersión, si lo encuentra devuelve true (encontrado),
* si no lo encuentra recorre el vector de celdas, en caso de que se haya visitado ya una posición devuelve false, por el contrario si no se ha visitado, busca con el índice que devuelve
*la función de exploración, si lo encuentra devuelve true, sino almacena en visitadas la posición que se ha visitado.
*/

bool  TablaHash::Buscar(DNI& key){

visitadas.clear();

int indx;

  if(!Tabla[(*fdispersion)(key)].buscar(key)){

    indx=(*fdispersion)(key);

      for(int i=0;i<RowSize;i++){
          
        if(visitada((*fexploracion)(key,indx))){
          return false;
        }
        if(Tabla[(*fexploracion)(key,indx)].buscar(key)){
          return true;
        }else{
          visitadas.push_back((*fexploracion)(key,indx));
        }

        indx = (*fexploracion)(key,indx);
      }
return false;

}else{

return true;
  }
}

/*!
* Si en el índice no están llenas las celdas, inserta el dni y devuelve true, si están llenas itera mientras que las celdas estén llenas va llamando a la función de exploración y almacenando el nuevo indice, si itera más veces que el tamaño del vector devuelve false, si sale del bucle
* inserta el valor en la tabla y devuelve true.
*/
bool TablaHash::Insertar(DNI& key){

  if(!Tabla[(*fdispersion)(key)].Full()){

    return Tabla[(*fdispersion)(key)].insertar(key);

  }else{

    int indx = (*fdispersion)(key);
    int cont=0;

    while(Tabla[indx].Full()){
      cont++;

      indx = (*fexploracion)(key,indx);

      if(cont >= RowSize){
        return false;
      }
    }

    return  Tabla[indx].insertar(key);
  }
}

/*!
* Se le pasa una posición del vector de celdas y se recorre el vector de visitadas
* si la posición se encuentra en el vector de visitadas se devuelve true (pues esta posición ya se ha visitado)
* en caso contrario se devuelve false (Esta función es cara muy cara!!)
*/

bool TablaHash::visitada(int cellpos){

  for(int i=0;i<visitadas.size();i++){
    if(visitadas[i] == cellpos)
    return true;
  }
  return false;
}

/*!
* se le pasa un tamaño y un vector de DNI's e inserta ese número de dni's
*/

void TablaHash::LoadTable(int tam,vector<DNI>& nums){
  bool n;
 for(int i=0;i<tam;i++){

  n =   Insertar(nums[i]);
  if(!n)
  std::cout << " No insertado\n";
  }
}
