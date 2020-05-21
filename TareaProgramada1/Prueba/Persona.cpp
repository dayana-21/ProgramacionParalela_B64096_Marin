
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

#include "Persona.h"


/*
 *  Contruye una persona usuaria del ascensor
 *  Debe definir de manera aleatoria los pisos de subida y bajada
 *  Los pisos deben respetar las limitaciones fisicas del edificio
 *     - Se indica 10 pisos en el enunciado numerados del 1 al 10
 *
 */
Persona::Persona( long identificacion ) {
   int r1, r2;

   this->idPersona = identificacion;

   r1 = (rand() % 10) + 1;
   this->pisoDondeMeSubo = r1;

   do {
      r2 = (rand() % 10) + 1;
   } while ( r1 == r2 );
   this->pisoDondeMeBajo = r2;

}


/*
 *  Destructor
 */
Persona::~Persona() {
}

  vector< int > Persona::solicitud(char * rotulo){

  vector< int > personas;
  personas.push_back(this->idPersona);
  personas.push_back(this->pisoDondeMeSubo);
  personas.push_back(this->pisoDondeMeBajo);

  return personas;
 }

/*
 *  Metodo para desplegar los datos de los elementos de esta clase (toString)
 */
void Persona::Display( char * rotulo ) {

   sprintf( rotulo, "Persona[ %d ]:, subo en %d, bajo en %d\n", this->idPersona, this->pisoDondeMeSubo, this->pisoDondeMeBajo );

}
