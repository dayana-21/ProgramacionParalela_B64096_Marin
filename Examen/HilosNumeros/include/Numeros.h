#ifndef NUMEROS_H
#define NUMEROS_H
#include <vector>

using namespace std;

class Numeros
{
    public:
        Numeros();
        virtual ~Numeros();
        int verificarCuadrado(int);
        vector < int > Primos(int, int);
        void imprimir( vector < int >);
        int cantidadhilos(int numeros);
    protected:

    private:
};

#endif // NUMEROS_H
