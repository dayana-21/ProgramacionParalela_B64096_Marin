# CI0117 Programación Paralela y Concurrente
# 2020-i
#

# Enlaza los archivos objeto y genera el archivo ejecutable
PiPorSeriesConMensajes: PiPorSeriesConMensajes.o Buzon.o
	g++ -g PiPorSeriesConMensajes.o Buzon.o -o PiPorSeriesConMensajes

# Genera el archivo objeto a partir del fuente de enviarConClases
PiPorSeriesConMensajes.o: PiPorSeriesConMensajes.c Buzon.h
	g++ -g -c PiPorSeriesConMensajes.c

# Genera el archivo objecto a partir del fuente Buzon
Buzon.o: Buzon.h Buzon.cc
	g++ -g -c Buzon.cc
