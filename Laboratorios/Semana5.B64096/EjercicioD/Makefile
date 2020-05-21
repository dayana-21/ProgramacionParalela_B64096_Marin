# CI0117 Programación Paralela y Concurrente
# 2020-i
#

# Enlaza los archivos objeto y genera el archivo ejecutable
SumaUnoSem: SumaUnoSem.o Semaforo.o
	g++ -g SumaUnoSem.o Semaforo.o -o SumaUnoSem

# Genera el archivo objeto a partir del fuente de enviarConClases
SumaUnoSem.o: SumaUnoSem.cc Semaforo.h
	g++ -g -c SumaUnoSem.cc

# Genera el archivo objecto a partir del fuente Buzon
Semaforo.o: Semaforo.h Semaforo.cc
	g++ -g -c Semaforo.cc
