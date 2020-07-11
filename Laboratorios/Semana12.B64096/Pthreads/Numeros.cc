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

vector<vector<int>> Numeros::calcular(int inicio,int limiteSuperior){
vector<vector<int>> sumas;
vector<int> suma;
for (int i = inicio; i <= limiteSuperior; i++){
	if(i%2 == 0){
            for(int j = 2; j <= limiteSuperior; j++){
              for(int k = 2; k<= limiteSuperior; k++){
                   if(esPrimo(k) == 1 && esPrimo(j)){
                       if(j+k == i){
                          //printf( "Valor: %d = %d + %d \n",i,j,k);
                          suma.push_back(i);
                          suma.push_back(j);
                          suma.push_back(k);
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

