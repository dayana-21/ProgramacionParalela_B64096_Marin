#include "Numeros.h"
#include <vector>
#include <string.h>
#include <iostream>


using namespace std;


Numeros::Numeros()
{
}

Numeros::~Numeros()
{
}

int Numeros::esPrimo(int numero){
int primo; 
int contador = 0;
for(int i = 1; i <= numero; i++){
      if(numero % i == 0){
      contador++;
}
}
if (contador > 2){
primo = 0;
}else{
primo = 1;
} 
return primo;
}

vector<vector<int>> Numeros::calcular(int limiteSuperior){
vector<vector<int>> sumas;
vector<int> suma;
//for para los pares 
for (int i = 6; i <= limiteSuperior; i++){
	if(i%2 == 0){// se verifica que es par 
           // for para ver los primos y la suma;
            for(int j = 2; j <= limiteSuperior; j++){
              for(int k = 2; k<= limiteSuperior; k++){
                   if(esPrimo(k) == 1 && esPrimo(j)){// Se accede al metodo esprimo para ver si es primo.
                       if(j+k == i){//Se verifica si la suma es igual al numero par que estamos verificando
                          //printf( "Valor: %d = %d + %d \n",i,j,k);
                          suma.push_back(i);
                          suma.push_back(j);
                          suma.push_back(k);
                          //suma es un vector que guarda el numero par y los dos numeros primos que forman la suma
                          sumas.push_back(suma);
                          suma.clear();
}
}
}
}
}
}
return sumas;
}

