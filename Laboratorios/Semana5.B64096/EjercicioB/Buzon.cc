#include "Buzon.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 0xB64096 

bool recibio=false;
Buzon::Buzon(){ 
this->id=msgget( KEY, IPC_CREAT | 0600 );
if (id == -1){ 
printf("Buzon::Buzon()");
exit (-1);
}
}
Buzon::~Buzon(){
if(recibio){ 
msgctl( id, IPC_RMID, NULL );
}
}
int Buzon::Enviar(const char * mensaje, int veces, long tipo){ 
int size = sizeof( mensaje );
msj.mtype = tipo;
msj.veces = veces;
strncpy( msj.etiqueta, mensaje,size );
int st = msgsnd( id, (const void *) & msj, sizeof( msj ) , IPC_NOWAIT ); 
if(-1==st){
perror("Buzon::Enviar"); 
exit(1);
} 
}
int Buzon::EnviarDouble(double mensaje){ 
msj.mtype = 2020;
msj.valor=mensaje;
int sit = msgsnd( id, (const void *) & msj, sizeof( msj ) , IPC_NOWAIT ); 
if(-1==sit){
perror("Buzon::EnviarDouble"); 
exit(1);
}
}
int Buzon::Recibir(char * mensaje, int * veces, long tipo ){
recibio=true;
st = msgrcv( id, (void *) & msj, sizeof( msj), tipo, IPC_NOWAIT );
strncpy( mensaje,msj.etiqueta, sizeof( mensaje ) );
recibio=true;
if(-1==st){
perror("Buzon::Recibir");
exit(1);
}
return st;
}
int Buzon::RecibirDouble(double * mensaje){
msj.mtype = 2020;
st = msgrcv( id, (void *) & msj, sizeof( msj ), 2020, IPC_NOWAIT );
*mensaje=msj.valor;
recibio=true;
if(-1==st){
perror("Buzon::RecibirDouble"); 
exit(1);
}	
return st;
}
