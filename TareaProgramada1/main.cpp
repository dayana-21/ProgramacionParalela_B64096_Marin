
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <malloc.h>
#include <sys/unistd.h>
#include <sys/errno.h>
#include <error.h>
#include <time.h>


using namespace std;



int collatz(int num);
void shm_create( int *& shm, int key );
void shm_get( int *& shm, int key );
void process_work( int pid, int shmid, int l_limit, int u_limit );
int get_max_num( int ** shm );

int main()
{
  int padreID, hijoID, my_shmid, my_pid;
  int * shm[5]; // un puntero a memoria compartida por cada hijo

  int lower_limit = 2;
  int upper_limit;
  bool esMultiplo = true;
  time_t t;

  while(esMultiplo) {
	  cout << " Digíte el limite superior del conjunto de valores a calcular: "; cin >> upper_limit;
	  if (upper_limit % 10 == 0){
		 esMultiplo = false;
	  } else {
		  cout << "El numero digitado no corresponde a un multiplo de 10 \n";
		}
  }





   t = clock();

  //Se crean los procesos hijos
  //5 procesos hijos
  padreID = getpid();
  for (int i = 1; i <= 5; i++){
    if (getpid() == padreID ){
      my_pid = i; // identificador de proceso interno
      my_shmid = my_pid+5000;
      shm_create( shm[i-1], my_shmid );
      hijoID = fork();
    } else {
      break;
    }
  }

  if( hijoID == 0 ){

    process_work( my_pid, my_shmid, lower_limit, upper_limit );
  } else {
    while( wait( NULL ) > 0 ); // espera que terminen todos los hijos

    int max = get_max_num( shm );
    printf( "El numero %d genero la mayor cantidad de pasos: %d\n", shm[max][0], shm[max][1] );
    t = clock() - t;
    printf ("Tiempo: (%f segundos).\n",t,((float)t)/CLOCKS_PER_SEC);
  }

  return 0;
}

//Metodo que verifica si el numero es par o impar y hace respectiva  operacion

int collatz(int num){
  int steps = 0;

  while (num != 1){
    if ((num % 2) == 0){
      num = num/2;
      steps++;
    } else {
      num = num * 3 + 1;
      steps++;
    }
  }

  return steps;
}

void shm_create( int *& shm, int key ){
  int shmid;

  if ((shmid = shmget(key, 2*sizeof(int), IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  shm = (int *)shmat(shmid, NULL, 0);
  if((intptr_t) shm == -1){
    perror("Error en shmat");
    exit(1);
  }
}

void shm_get( int *& shm, int key ){
  int shmid;

  if ((shmid = shmget(key, 2*sizeof(int), 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  shm = (int *)shmat(shmid, NULL, 0);
  if((intptr_t) shm == -1){
    perror("Error en shmat");
    exit(1);
  }
}

void process_work( int pid, int shmid, int l_limit, int u_limit ){
  int * my_shm;
  int steps;
  shm_get( my_shm, shmid );
  my_shm[0] = 0; // numero que genero la mayor cantidad de pasos
  my_shm[1] = 0; // cantidad de pasos maxima

  for(int i = l_limit+(pid-1); i <= u_limit; i += 5){
    steps = collatz(i);

    // aqui lo que se me ocurre es comparar si la cantidad de pasos es mayor a la que ya se encuentra y tambien agrego el numero que genero esa cantidad de paos
    if (steps > my_shm[1]){
      my_shm[0] = i;
      my_shm[1] = steps;
    }
  }
}

int get_max_num( int ** shm ){
  int max_index = 0;
  int max = shm[0][1]; // suponiendo que el primero es el maximo

  for( int i = 1; i <= 5; ++i ){
    if( shm[i-1][1] > max ){
      max_index = i-1;
      max = shm[i-1][1];
    }
  }

  return max_index;
}

