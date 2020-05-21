#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include "Semaforo.h"

union semun {
   int              val;    /* Value for SETVAL */
   struct semid_ds buf;    / Buffer for IPC_STAT, IPC_SET */
   unsigned short  array;  / Array for GETALL, SETALL */
   struct seminfo  __buf;  / Buffer for IPC_INFO
                               (Linux-specific) */
};


double SumarUno( long * suma ) {
   int i;

   for ( i = 0; i < 1000; i++ ) {
      (* suma)++;			// Suma uno
   }
   exit( 0 );
}


double SumarUnoControlado( Semaforo s, long * suma ) {
   int i;
   s.Wait();
   for ( i = 0; i < 1000; i++ ) {
      (* suma)++;			
      
   }
   s.Signal();

   exit( 0 );

}

int SerialTest( int procesos, long * total ) {
   int i, proceso;

   for ( proceso = 0; proceso < procesos; proceso++ ) {

      for ( i = 0; i < 1000; i++ ) {
         (* total)++;			
      }

   }
   return 0;
}


int ForkTestRaceCondition( int procesos, long * total ) {
   int proceso, pid;

   for ( proceso = 0; proceso < procesos; proceso++ ) {
      pid = fork();
      if ( ! pid ) {
         SumarUno( total );
      }
   }

   for ( proceso = 0; proceso < procesos; proceso++ ) {
      int status;
      pid_t pid = wait( &status );
   }
   return 0;
}


int ForkTestNORaceCondition( int procesos, Semaforo s, long * total ) {
   int proceso, pid;

   for ( proceso = 0; proceso < procesos; proceso++ ) {
      pid = fork();
      if ( ! pid ) {
         SumarUnoControlado( s, total );
      }
   }

   for ( proceso = 0; proceso < procesos; proceso++ ) {
      int status;
      pid_t pid = wait( &status );
   }
   return 0;
}

int main( int argc, char ** argv ) {
   long procesos;
   long * total;
   int proceso, pid, shmid, semid;
   clock_t start, finish;
   double used;
   Semaforo s(1);

   shmid = shmget( 0xB64096, sizeof( long ), IPC_CREAT | 0600 );
   total = (long *) shmat( shmid, NULL, 0 );

   procesos = 100;
   if ( argc > 1 ) {
      procesos = atol( argv[ 1 ] );
   }

   start = clock();
   * total = 0;
   SerialTest( procesos, total );
   finish = clock();
   used = ((double) (finish - start)) / CLOCKS_PER_SEC;
   printf( "Prueba serial: Valor acumulado es \033[91m %ld \033[0m con %ld procesos in %f seconds\n", * total, procesos, used );

   start = clock();
   * total = 0;
   ForkTestRaceCondition( procesos, total );
   finish = clock();
   used = ((double) (finish - start)) / CLOCKS_PER_SEC;
   printf( "Prueba con hilos: Valor acumulado es \033[91m %ld \033[0m con %ld procesos in %f seconds\n", * total, procesos, used );

   start = clock();
   * total = 0;
   ForkTestNORaceCondition( procesos, s, total );
   finish = clock();
   used = ((double) (finish - start)) / CLOCKS_PER_SEC;
   printf( "Prueba con hilos y semáforos: Valor acumulado es \033[91m %ld \033[0m con %ld procesos in %f seconds\n", * total, procesos, used );
   shmdt( total );
   shmctl( shmid, IPC_RMID, 0 );

}
