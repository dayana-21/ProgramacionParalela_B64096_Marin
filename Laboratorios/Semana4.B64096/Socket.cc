/*
 *  Esqueleto para la clase Socket
 */
#include "Socket.h"
#include <sys/types.h>        
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>


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

Socket::Socket(int ID){
this->idSocket = socket(AF_INET,SOCK_STREAM,0);
if(-1 == idSocket){
perror("Socket::Socket");
}
SetIDSocket(ID);
}


Socket::Socket(){
this->idSocket= socket(AF_INET, SOCK_STREAM,0);
if(-1 == idSocket){
perror("Socket()::Socket()");
}
}
// Destructor 
Socket::~Socket(){
    Close();
}


void Socket::Close(){
int retorno;
retorno = close(this->idSocket);
if(-1 == retorno){
perror("Socket::Close()");
exit(1);
}
}

/*
   char * hostip: direccion del servidor, por ejemplo "www.ecci.ucr.ac.cr"
   int port: ubicacion del proceso, por ejemplo 80
 */
int Socket::Connect( char * hostip, int port )
{
    //Para definir los elementos del socket
    struct sockaddr_in dir;
    dir.sin_family = AF_INET;
    dir.sin_port = htons(port); //Se convierte a variable de red

    inet_aton(hostip, &dir.sin_addr);

    int conex = connect(this->idSocket, (struct sockaddr *) &dir, sizeof(dir));

     if(conex == -1)
        {
            perror("Socket::Connect");
            exit(1);
        }
    return conex;

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
        retorno = connect(this->idSocket, rp->ai_addr, rp->ai_addrlen );
        if ( -1 == retorno )
            break;
    }

    freeaddrinfo( resultado );

    return retorno;

}
/*
 *  Lee caracteres por medio del socket y los guarda en "text" cuya capacidad máxima es "len"
 */
int Socket::Read( char *text, int len ) {
int lect;
lect = read(this->idSocket,(void*)text,len);
if (-1 == lect){
perror("Socket::Read()");
}
   return lect;
}


/*
 *  Escribe la tira de caracteres a traves de socket
 */
int Socket::Write( char *text ) {
int escr;
escr = write(this->idSocket,(void*)text,strlen(text));
if (-1 == escr){
perror("Socket::Write");
}
return escr;

}

int Socket::Write( char *text, int len) {
int escr;
escr = write(this->idSocket,(void*)text,len);
if (-1 == escr){
perror("Socket::Write");
}
return escr;
}


/*
 *  Indica al sistema operativo que el socket va a actuar de manera pasiva
 *  Utilizara conexiones establecidas por medio de Accept
 */
int Socket::Listen( int queue ) {
int pas = listen(this->idSocket, queue);
if ( -1 == pas) {
perror( "Socket::Listen" ); 
exit( 1 );}
 return pas;    
}

/*
 *  Asocia al socket con el puerto indicado como parametro
 */
int Socket::Bind ( int port ) {
struct sockaddr_in dir;
	
dir.sin_family = AF_INET;
dir.sin_addr.s_addr = htonl( INADDR_ANY );
dir.sin_port = htons( port );

int ID = bind( this->idSocket, (const sockaddr *) & dir, sizeof(dir)); 

if ( -1 == ID) {
perror( "Socket::Bind" ); 
exit( 1 );
}
	return ID;

}

/*
 *  Acepta conexiones desde los clientes
 *  Devuelve una nueva instancia de la clase Socket para manejar la conexion de un cliente
 */
Socket * Socket::Accept()
{
    struct sockaddr_in dir;
    socklen_t dir_len = sizeof(dir);

    int nuevoId = accept(this->idSocket, (struct sockaddr*) &dir, &dir_len);

    if(nuevoId == -1)
    {
        perror("Socket::Accept");
        exit(1);
    }

    Socket * nuevoSocket = new Socket(nuevoId);

    return nuevoSocket;

}
/*
 *  Cierra parcialmente la conectividad de un socket, puede ser por escrituras o lecturas
 *  El parametro "mode" indica el tipo de cierre que se quiere efectuar
 */
int Socket::Shutdown( int mode ) {
int apagado = shutdown(this->idSocket,mode);
if( apagado = -1){
perror( "Socket::Shutdown" ); 
exit( 1 ); 
}
 return apagado;
}

/*
 *  Cambia la variable de instancia
 */
void Socket::SetIDSocket(int id){

    idSocket = id;

}
