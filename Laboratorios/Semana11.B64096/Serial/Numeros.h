#ifndef NUMEROS_H_INCLUDED
#define NUMEROS_H_INCLUDED

#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
class Numeros
{

public:
    Numeros();
    ~Numeros();
    int esPrimo(int);
    vector<vector<int>>calcular(int);
};

#endif // NUMEROS_H_INCLUDED
