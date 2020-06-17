#include "parserHTML.h"
#include "mapa.h"

parserHTML::parserHTML(){}
parserHTML::~parserHTML(){}
void parserHTML::processLine( const char * line, mapa * tags) {
   	char * token;
   	char * respaldo;
   	token = strtok_r( (char * ) line, "< >\t\n",  &respaldo );
   	while ( NULL != token ) {
      		tags->setMapa(tags->agregarEtiqueta(token, tags->getMapa()));
      		token = strtok_r( NULL, "< >\t\n" ,&respaldo);
	}
	
}
void parserHTML::mostrarEtiquetas(mapa * tags){
	tags->imprimir(tags->getMapa());
}



