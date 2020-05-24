#define KEY 0xB64096
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include "Semaforo.h"

//g++ Semaforo.cc pruebaSem.cc

union semun {
               int val = 0;    ///* Value for SETVAL */
               struct semid_ds *buf;    ///* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  ///* Array for GETALL, SETALL */
               struct seminfo  *__buf;  ///* Buffer for IPC_INFO
                                           /* (Linux-specific) */ 
 };
struct sembuf l;
union semun u;

Semaforo::Semaforo(int inicial){
	int estado;
	this->id = semget(KEY,1,IPC_CREAT |0600);
		if(-1==id){
			perror("Semaforo::Semaforo");
			exit(1);
		}
		estado=semctl(id,0,SETVAL,u);
		if(-1==estado){
			perror("Semaforo::Semaforo");
			exit(1);
		} }
Semaforo::~Semaforo(){
	semctl(id, 0, IPC_RMID);
}

int Semaforo::Wait(){
	l.sem_num=0;
	l.sem_op=-1;
	l.sem_flg=0;
	int estado=semop(id,&l,1);
}
int Semaforo::Signal(){
	l.sem_num=0;
	l.sem_op=1;
	l.sem_flg=0;
	int estado =semop(id,&l,1);
}
