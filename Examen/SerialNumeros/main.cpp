#include <iostream>
#include "Numeros.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    Numeros * num;
    num = new Numeros();
    int numero;
    int resultado = 0;
    vector <int > rango;
    vector < int > primos;
   int cantPrimos = 0;

    clock_t start, finish; //Variables para medir el tiempo.
    double time = 0; //Resultado del tiempo transcurrido
    start = clock();
     int primer_num = 0;
     int segundo_num = 0;
     int esCuadrado;
     int verificar = 0;

    cout << "Ingrese un numero entero" << endl;
    cin >> numero;
    resultado = num->verificarCuadrado(numero);

    if(resultado == 1){
    for (int i = 1; i <= numero; i++){
    primer_num = i;
    segundo_num = (i+1);
    primer_num = primer_num*primer_num;
    segundo_num = segundo_num*segundo_num;
    printf( " Pareja de numeros cuadrados:  %d %d ",primer_num , segundo_num,"/n");
    primos =  num->Primos(primer_num,segundo_num);
    for(int i = 1; i<=primos.size();i++) {
    cantPrimos++;
     printf( "Numeros primos: ","/n");
     num->imprimir(primos);
   }
   }

   }else{
   printf( "No es un raiz cuadrda ","/n");
   }
    finish = clock();
    time = finish - start;
    printf("Tiempo transcurrido: %f. \n", time);


    return 0;
}
