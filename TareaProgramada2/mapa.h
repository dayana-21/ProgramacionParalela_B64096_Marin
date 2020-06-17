/* 
Ricardo Alfaro - B70257
Tarea Programada 2
Parser HTML
 */


#ifndef MAPA_H
#define MAPA_H
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

class mapa{

public:
	mapa();
	~mapa();
	void sumar(string);
	void imprimir(map <string,int>);
        void asignarMapa();
	std::map <string,int> agregarEtiqueta(string, map <string,int>);
	std::map <string,int> getMapa();
	void setMapa(std::map <string,int>);
private:
	std::map <string,int> tags;
	
};
#endif //MAPA.H
