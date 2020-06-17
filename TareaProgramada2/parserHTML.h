#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <regex>
#include <iostream>
#include "mapa.h"

class parserHTML{
	parserHTML();
	~parserHTML();
	public:
	void processLine( const char * line, mapa*);
 	void mostrarEtiquetas(mapa*);
};


