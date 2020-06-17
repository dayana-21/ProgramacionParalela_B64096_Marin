#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <thread>
#include <mutex>
#include "FileReader.h"
#include "parserHTML.h"
#include "mapa.h"
//std::mutex mtx;


struct sharedData {
	FileReader fr;
	mapa tags;
} * sharedFR;

void processFile( sharedData * sd, int worker) {
   parserHTML * pa;
   char * line;
   FileReader * fr = &sd->fr;
   mapa * mp = &sd->tags;
   line = (char *) calloc (512, sizeof ( char ));
   while (fr->hasNext ( worker )) {
	fr->getNext(&line, worker);
        pa->processLine(line, mp);
	printf ("%s", line);
	usleep ( 10 );
   }
   free(line);
   pa->mostrarEtiquetas(mp);
}
int main( int argc, char ** argv ) {
  FileReader * fr;
  mapa * tags;
  int workers;
  int strategy;
  int shmid;
  int i;
  std::cout<<"Cantidad de trabajadores que desea asignar"<<std::endl;
  std::cin>>workers;
  std::thread worker[workers];
  std::cout<<"Que estrategia desea usar"<<std::endl;
  std::cin>>strategy;
  sharedFR = (sharedData *) shmat (shmid, NULL, 0);
  fr = new FileReader (argv[1], workers, strategy);
  tags = new mapa();
  for(i = 0; i< workers; i++){
    worker[i] = std::thread(processFile, sharedFR, i);
  }
  for(i = 0; i< workers; i++){
    worker[i].join();
  }


  


}
