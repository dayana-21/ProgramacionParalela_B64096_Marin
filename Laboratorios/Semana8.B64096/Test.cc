#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include "FileReader.h"

struct sharedData {
	FileReader fr;
} * sharedFR;
void processFile( sharedData * sd, int worker ) {
   char * line;
   FileReader * fr = &sd->fr;
   line = (char *) calloc (512, sizeof ( char ));
   while (fr->hasNext ( worker )) {
	fr->getNext(&line, worker);
	printf( "Hilera %s  \n", line);
	usleep ( 10 );
   }
   free(line);
}
int main( int argc, char ** argv ) {
  FileReader * fr;
  int workers = 3;
  int strategy = 1;
  int shmid, status;
  int i, pid [3];

  shmid = shmget (0x00ECC4,sizeof ( sharedData), IPC_CREAT | 0600);
  if(-1 == shmid ){
	perror("Memoria compartida");
	exit(1);
  }

  sharedFR = (sharedData *) shmat (shmid, NULL, 0);
  fr = new FileReader (argv[1], workers, strategy);
  memcpy ( sharedFR, fr, sizeof (FileReader));

  for (i = 0; i < 3; i++){
		pid[ i ] = 0;
  }
  for (i = 1; i < 3; i++){
	pid[ i ] = fork();
	if(! pid [ i ]){
		processFile( sharedFR, i);
		break;
	}else{
		pid[ 0 ] = getpid();
	}
  }
  for (i = 1; i < 3; i++) {
	if ( pid[ i ] > 0){
 		waitpid ( pid[ i ], &status, 0);
	}
	
  }
   printf( "El numero de trabajadores es %d  \n", workers);
}
