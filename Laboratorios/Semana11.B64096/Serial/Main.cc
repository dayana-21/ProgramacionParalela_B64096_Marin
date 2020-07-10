#include <iostream>
#include <chrono>
#include "Numeros.h"
#include <vector>
using namespace std;

int main()
{
    Numeros *n;
    int limiteSuperior;
    double tiempo;
    auto start = chrono::high_resolution_clock::now();
    cout << "Por favor ingrese el limite: " << "\n";
    cin>> limiteSuperior;
    vector<vector<int>> Tsumas;
    vector<int> suma;
    Tsumas = n->calcular(limiteSuperior);
    for(size_t num = 0; num < Tsumas.size(); num++)
    {
        suma = Tsumas[num];
        printf( "%d = %d + %d \n",suma[0], suma[1], suma[2]);
    }

    auto finish = chrono::high_resolution_clock::now();
    tiempo = chrono::duration<double, milli>(finish-start).count();
    printf("Tiempo transcurrido es: %f. \n", tiempo);
   
    return 0;
}

