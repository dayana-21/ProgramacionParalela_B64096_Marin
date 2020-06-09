#include <iostream>
#include <ctime>
#include <pthread.h>
#include "Numeros.h"
#include "Mutex.h"
#include <stdio.h>
#include <stdlib.h>


using namespace std;

// Shared variables
Mutex * mutex;
vector < int > primos;
int range;
int rangoMaster;
/*
*
*/
void * hiloNumero( void * id )
{
    Numeros * num;
    mutex = new Mutex();
    num = new Numeros();
    //int identificacion = *((int*) id);
    long identificacion = (long) id;
    int rango;
    int inicio;
    int fin;


    if(identificacion == 0)
    {
        rango = rangoMaster;
    }
    else
    {
        rango = range;
    }

    inicio = (rango * identificacion) + 1;
    fin = rango * (identificacion+1);

    mutex->Lock();




    mutex->Unlock();
}


/*
*
*/
void Crear( long cantidad )
{
    long hilo;
    pthread_t * numeros;

    numeros = (pthread_t *) calloc( cantidad, sizeof( pthread_t ) );

    for ( hilo = 0; hilo < cantidad; hilo++ )
    {
        pthread_create( & numeros[ hilo ], NULL, hiloNumero, (void *) hilo );
    }


    for ( hilo = 0; hilo < cantidad; hilo++ )
    {
        pthread_join( numeros[ hilo ], NULL );
    }

    free( numeros );

}



int main(int  argc, char *argv[])
{
    Numeros * num;
    num = new Numeros();
    int numero = 0;
    int resultado = 0;

    clock_t start, finish; //Variables para medir el tiempo.
    double time = 0; //Resultado del tiempo transcurrido
    int limite = 0;
    int canthilos = 0;
    int cantidadHilos = 0;


    //start = clock();

    //Se le pide al usuario que ingrese un numero (el limite).
    cout << "Ingrese un numero entero" << endl;
    cin >> numero;
    resultado = num->verificarCuadrado(numero);
    if(resultado == 1){
    cantidadHilos = num->cantidadhilos(numero);
    }else{
    cout << " No ingreso un numero cuadrado" << endl;
    }

    finish = clock();
    time = finish - start;
    printf("Tiempo transcurrido: %f. \n", time);
}
