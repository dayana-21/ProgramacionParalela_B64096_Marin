#include <iostream>
#include <chrono>
#include <pthread.h>
#include <math.h>
#include "Numeros.h"
#include "Mutex.h"

using namespace std;


// Shared variables
Mutex * mutex;
vector<vector<int>> Tsumas; 
int range = 0;  
int lim = 0;  




void * hiloNumero( void * id )
{
    Numeros * num;
    mutex = new Mutex();
    num = new Numeros();
    long identificacion = (long) id;
    int inicio;
    int fin;

    vector<vector<int>> sumas; 
    vector<int> actual; 

    inicio = (range * identificacion) + 1;
    fin = range * (identificacion+1);

    if (fin > lim)
    {
        fin = lim;
    }

    mutex->Lock();
    sumas = num->calcular(inicio, fin);

    for(size_t i = 0; i < sumas.size(); i++)
    {
        actual = sumas[i];
        Tsumas.push_back(actual);
    }

    mutex->Unlock();
}


void Crear( long cantidad )
{
    long hilo;
    pthread_t * numeros;

    numeros = (pthread_t *) calloc( cantidad, sizeof( pthread_t ) );

    for ( hilo = 0; hilo < cantidad; hilo++ )
    {
        pthread_create( & numeros[ hilo ], NULL, hiloNumero, (void *) hilo );
    }

    //Se espera por la finalizacion de todos los hilos creados.
    for ( hilo = 0; hilo < cantidad; hilo++ )
    {
        pthread_join( numeros[ hilo ], NULL );
    }

    free( numeros );

}



int main(int  argc, char *argv[])
{
    int limite = 0;
    int cant_hilos = 0;
    int rango = 0;
    std::vector<int> numeros;
    double tiempo;

    auto start = chrono::high_resolution_clock::now();

    if (argc != 3)
    {
        printf("Ingrese: %s el limite superior y el numero de hilos \n", argv[0]);
        exit(1);
    }

    limite = atoi(argv[1]);
    cant_hilos = atoi(argv[2]);
    lim = limite;
    rango = floor(limite/cant_hilos);
    range = (limite - rango*(cant_hilos-1));
    Crear((long)cant_hilos);
    for(size_t num = 0; num < Tsumas.size(); num++)
    {
        numeros = Tsumas[num];
        printf( "%d = %d + %d \n",numeros[0], numeros[1], numeros[2]);
    }

    auto finish = chrono::high_resolution_clock::now();

    tiempo = chrono::duration<double, milli>(finish-start).count();
    printf("Tiempo transcurrido : %f. \n", tiempo);
}

