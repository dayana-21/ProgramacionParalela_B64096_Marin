#include <iostream>
#include <math.h>
#include <vector>
#include <mpi.h>
#include <time.h>
#include <chrono>
#include "Numeros.h"

using namespace std;

int main(int  argc, char *argv[])
{
    Numeros * numeros;
    numeros = new Numeros();
    int lim = 0; 
    int rango = 0;
    int range = 0;  
    int inicio = 0;  
    int fin = 0; 
    int procesos = 0; 
    int cant_procs = 0;  
    int id = 0;
    int my_rank;  
    double tiempo;
   vector<vector<int>> Tsumas; 
    if (argc != 2)
    {
        printf("Ingrese: %s cantida limite  y la cantidad de procesos por favor. \n", argv[0]);
        exit(1);
    }
    auto empezar = chrono::high_resolution_clock::now();

    lim = atoi(argv[1]);
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &procesos);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    cant_procs = procesos-1; 
    rango = floor(lim/cant_procs);
    range = (lim - rango*(cant_procs-1));


    if(my_rank != 0)
    {
        vector<vector<int>> sumas;
        vector<int> suma;
        id = my_rank-1;
        int cantidadVeces;
        inicio = (range * id) + 1;
        fin = range * (id+1);


        if (fin > lim)
        {
            fin = lim;
        }
        sumas = numeros->calcular(inicio, fin);
        cantidadVeces = sumas.size();
        MPI_Send(&cantidadVeces, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
        for(size_t i = 0; i < sumas.size(); i++)
        {
            suma = sumas[i];
            MPI_Send(&suma[0], 3, MPI_INT, 0, 0, MPI_COMM_WORLD); 
        }
    }
    else
    {vector<int> suma; 
     int cantidadVeces = 0;

        for(int j = 1; j < procesos; j++)
        {
            MPI_Recv(&cantidadVeces, 1, MPI_INT, j, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for(int i = 0; i < cantidadVeces; i++)
            {   suma.resize(3); 
                MPI_Recv(&suma[0], 3, MPI_INT, j, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
                Tsumas.push_back(suma); 

            }
        }

    }
    if(my_rank == 0)
    {
        vector<int> suma;
        int tamano = Tsumas.size();
        printf("Medida %d\n", tamano);
        for(size_t i = 0; i < Tsumas.size(); i++)
        {
            suma = Tsumas[i];
            printf( "%d = %d + %d \n",suma[0], suma[1], suma[2]);
        }
        auto finals = chrono::high_resolution_clock::now();

        tiempo = chrono::duration<double, milli>(finals-empezar).count();
        printf("El tiempo transcurrido es: %f. \n", tiempo);
    }

    MPI_Finalize();
}
