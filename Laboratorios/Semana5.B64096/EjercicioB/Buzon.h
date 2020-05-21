/*
 *  Esta clase encapsula los llamados al sistema en UNIX, para intercambio de mensajes por medio de buzones
 *  Se provee facilidades para el envio y recepcion de mensajes de cualquier tipo definido por el usuario
 *
 *  Autor: CI0117 Programacion Paralela y Concurrente
 *  Fecha: 2020-i
 *
 *  Ejemplo de un mensaje que contiene etiquetas HTML y su cantidad de apariciones:
 *
 *  struct msgbuf {
 *     long mtype;	// Tipo del mensaje a enviar, tiene que estar de primero en la estructura
 *			// Esta variable, para enviar, debe ser > 0
 *     int veces;	// Cantidad de veces que aparece la etiqueta HTML
 *     char etiqueta[ 32];	// Etiqueta HTML
 *  };
 */
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <sys/msg.h>
#include <errno.h>
#define KEY 0xB64096

class Buzon {
   public:
     struct msgbuf { 
      long mtype;
      int veces;
      char etiqueta[ 24 ]={0}; 
      double valor; 
   } msj;
      Buzon();
      ~Buzon();
      int Enviar( const char * mensaje, int veces, long tipo );	
      int EnviarDouble(double mensaje); 
      int Recibir( char * mensaje, int * veces, long tipo );   
      int RecibirDouble(double * mensaje); 
   private:
      int id; 
	  int st=0;
};
