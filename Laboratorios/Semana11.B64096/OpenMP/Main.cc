#include <iostream>
#include <math.h>
#include <vector>
#include <omp.h>
#include <time.h>
#include <chrono>
#include "Numeros.h"

using namespace std;

int main(int  argc, char *argv[])
{
    Numeros * num;
    num = new Numeros();
    vector<vector<int>> Tsumas;//Guarda todas las sumas 
    vector<vector<int>> sumas;//Guarda las sumas pero por rangos
    vector<int> suma; //Guarda los valores de cada suma
    int limite = 0; 
    int cant_hilos = 0;
    int rango = 0;
    int range = 0;  
    int inicio = 0; 
    int fin = 0;  
    int id = 0;  
    double tiempo;

    auto start = chrono::high_resolution_clock::now();
    if (argc != 3)
    {
        printf("Ingrese: %s la cantidad limite y  la cantidad de hilos \n", argv[0]);
        exit(1);
    }

    limite = atoi(argv[1]);
    cant_hilos = atoi(argv[2]);
    rango = floor(limite/cant_hilos);
    range = (limite - rango*(cant_hilos-1));

    #pragma omp parallel num_threads(cant_hilos) shared (Tsumas) private (sumas, suma, inicio, fin)
    {
        id = omp_get_thread_num();

        inicio = (range * id) + 1;
        fin = range * (id+1);

        if (fin > limite)
        {
            fin = limite;
        }

        sumas = num->calcular(inicio, fin);

        for(size_t i = 0; i < sumas.size(); i++)
        {
            suma = sumas[i];
            #pragma omp critical
            Tsumas.push_back(suma);
        }
    }
    #pragma omp single
    for(size_t i = 0; i < Tsumas.size(); i++)
    {
        suma = Tsumas[i];
        printf( "%d = %d + %d \n",suma[0], suma[1], suma[2]);
    }
    auto finish = chrono::high_resolution_clock::now();
    tiempo = chrono::duration<double, milli>(finish-start).count();
    printf("Tiempo transcurrido: %f. \n", tiempo);
}
