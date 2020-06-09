#include "Numeros.h"
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

Numeros::Numeros()
{
    //ctor
}

Numeros::~Numeros()
{
    //dtor
}

int Numeros::verificarCuadrado(int m){
int resultado = 0; // 1 para cuadrado 0 para verificar que no es cuadrado.
int n = 0;
n = sqrt(m);
if(n*n == m){
resultado = 1;
}else{
resultado = 2;
}
return resultado;
}

vector<int> Numeros::Primos(int inicio, int num){

vector < int > primos;

for (int i = inicio; i <= num; +i++){

if (i%2 != 0){
primos.push_back (i);
}
}
return primos;
}

void Numeros::imprimir(vector< int > numeros)
{

    for(size_t num = 0; num < numeros.size(); num++)
    {
        printf( " %d  ",numeros[num], "  ");
    }
}






