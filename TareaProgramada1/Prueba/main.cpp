    #include <iostream>
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <time.h>
	#include <pthread.h>
	#include "Ascensor.h"
	#include "Persona.h"
	#include "Mutex.h"
    #include <vector>

	using namespace std;



// Shared variables
//En este vector de vectores se guardan las solicitudes de las perosnas que quieren estrar al ascensor.

  Mutex * mutex;
  vector< vector < int > > solicitudes;
//Se guarda aquellas solicitudes que pueden ser aceptadas mientras el ascensor no este lleno

//vector< vector< int > > solicitudesAceptadas;
//En este vector de vectores se guardan las personas que estan dentro de ascensor;
//vector< vector< int> > personasDentro;

/*
 *  Rutina que ejecutan los hilos ascensor
 *
 */
void * hiloAscensor( void * param ) {
   Ascensor * ascensor;
   long identificacion;
   char  * rotulo;
   identificacion = (long) param;
   rotulo = (char *) calloc( 64, 1 );
   ascensor = new Ascensor( identificacion );

   ascensor->Display( rotulo );
   printf( "%s", rotulo );

   free( rotulo );

   return NULL;

}


/*
 *  Rutina que crea los ascensores del edificio, en el caso de esta tarea solo 1
 *  Cada ascensor es representado por un hilo
 */
void Ascensores( long cantidad ) {
   long hilo;
   pthread_t * ascensor;

   ascensor = (pthread_t *) calloc( cantidad, sizeof( pthread_t ) );

   for ( hilo = 0; hilo < cantidad; hilo++ ) {
      pthread_create( & ascensor[ hilo ], NULL, hiloAscensor, (void *) hilo );
   }

   for ( hilo = 0; hilo < cantidad; hilo++ ) {
      pthread_join( ascensor[ hilo ], NULL );
   }

   free( ascensor );

}


void * hiloPersona( void * param ) {
   Persona * persona;
   char  * rotulo;
   long identificacion;

   mutex = new Mutex();

   identificacion = (long) param;
   persona = new Persona( identificacion );
   rotulo = (char *) calloc( 64, 1 );

   mutex->Lock();
   persona->Display( rotulo );
   printf( "%s", rotulo );
   solicitudes.push_back(persona->solicitud(rotulo));
   printf( "%s", rotulo );
   free( rotulo );
   mutex->Unlock();

   return NULL;

}


/*
 *  Rutina que simula las oleadas de personas para uso del ascensor
 *  Las personas son generadas como hilos
 *
 */
void Personas( long cantidad ) {
   long hilo;
   pthread_t * personas;

   personas = (pthread_t *) calloc( cantidad, sizeof( pthread_t ) );

   for ( hilo = 0; hilo < cantidad; hilo++ ) {
      pthread_create( & personas[ hilo ], NULL, hiloPersona, (void *) hilo );
   }

   for ( hilo = 0; hilo < cantidad; hilo++ ) {
      pthread_join( personas[ hilo ], NULL );
   }

   free( personas );

}


/*
 *  Rutina principal para la creacion de los ascensores y las personas
 *  Restricciones de este proyecto programado
 *     - Solo un ascensor
 *
 */

int main( int argc, char ** argv )
	{
	long hilos;
	clock_t start, finish;
	double used;
	pthread_t ascensor;
	long cantidad = 1;

	srand( time( NULL ) );
	Ascensores( 1 );
	//usleep(50);

	Personas( 15 ); // Primera oleada

	sleep( 2 );


	//Personas( 10 ); // Segunda oleada

	}
