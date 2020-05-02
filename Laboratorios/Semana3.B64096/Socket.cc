#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include "Socket.h"

/* 
   char tipo: el tipo de socket que quiere definir
      's' para "stream
      'd' para "datagram"
   bool ipv6: si queremos un socket para IPv6
 */
Socket::Socket( char tipo, bool ipv6 ){
if (ipv6){
this->idSocket = socket(AF_INET,SOCK_STREAM,0);
}else{ 
   switch(tipo){
case 'd':
case 'D':
this->idSocket = socket(AF_INET,SOCK_DGRAM,0);
break;
default:
this->idSocket = socket(AF_INET,SOCK_STREAM,0);
break;
}
}
if(-1 == this->idSocket){
perror("Socket::Socket");
exit(1);
}
} 




//Destructor
Socket::~Socket(){
    Close();
}

void Socket::Close(){
int retorno;
retorno = close(this->idSocket);
if(-1 == retorno){
perror("Socket::Close()Close()");
exit(1);
}
}

/*
   char * hostip: direccion del servidor, por ejemplo "www.ecci.ucr.ac.cr"
   int port: ubicacion del proceso, por ejemplo 80
 */
int Socket::Connect( char * hostip, int port ) {
struct sockaddr_in direction;
direction.sin_family = AF_INET;
direction.sin_port = htons(port);
inet_pton(AF_INET, hostip, & direction.sin_addr);
int retorno = connect(this->idSocket,(struct sockaddr*)& direction,sizeof(direction));
return retorno;
}

/*
   char * hostip: direccion del servidor, por ejemplo "www.ecci.ucr.ac.cr"
   char * service: nombre del servicio que queremos acceder, por ejemplo "http"
 */
int Socket::Connect( char *host, char *service ) {
    int retorno;
    struct addrinfo hints, *resultado, *rp;

    hints.ai_family = AF_UNSPEC;    
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = 0;
    hints.ai_protocol = 0;         

    retorno = getaddrinfo( host, service, &hints, &resultado);

    for ( rp = resultado; rp; rp = rp->ai_next ) {
        retorno = connect( idSocket, rp->ai_addr, rp->ai_addrlen );
        if ( -1 == retorno )
            break;
    }

    freeaddrinfo( resultado );

    return retorno;

}


int Socket::Read( char *text, int len ) {
int retorno;
retorno = read(this->idSocket,(void*)text,len);
if (-1 == retorno){
perror("Socket::Read()");
}
   return retorno;

}


int Socket::Write( char *text, int len) {
int retorno;
retorno = write(this->idSocket,(void*)text,len);
if (-1 == retorno){
perror("Socket::Write");
}
return retorno;
}

void Socket::SetIDSocket(int id){
       idSocket = id;

}

