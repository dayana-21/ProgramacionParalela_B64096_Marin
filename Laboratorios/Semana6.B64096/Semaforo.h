/*
   C++ class to encapsulate Unix semaphore intrinsic structures and
   system calls
*/

#ifndef SEMAFORO
#define SEMAFORO
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 0xB64096	// Valor de la llave del recurso

//g++ Semaforo.cc pruebaSem.cc

class Semaforo {
   public:
      Semaforo( int ValorInicial = 0 );
      ~Semaforo();
      int Signal();	// Puede llamarse V
      int Wait();	// Puede llamarse P
   private:
      int id;		// Identificador del semaforo
};

#endif
