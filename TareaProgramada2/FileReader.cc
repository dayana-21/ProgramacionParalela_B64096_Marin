#include "FileReader.h"

FileReader :: FileReader(const char * fileName, int workers, int the_strategy){
   strategy = the_strategy;
   size = 512;
   line = (char *) calloc( 512, 1 );
   int temp;
   fileId = fopen( fileName, "r" );
   if ( NULL == fileId ) {
      perror( "El archivo no se pudo abrir");
      exit( 2 );
   }
   do{
   chars = getline(&line, & size, fileId);
    totalLines= totalLines+1;
   }while(chars>0);
   rewind(fileId);
   chars = getline(&line, & size, fileId);
   rewind(fileId);
   int division = totalLines/3;
       switch(strategy){
	case 1:
		lineT1= 0;
		lineT2= division;
		lineT3= division*2;
	break;
	case 2:
		lineT1= 0;
		lineT2= 1;
		lineT3= 2;
	break;
	case 3:
		lineT1=0;
	break;
	case 4:
		lineT1= 0;
		lineT2= 20;
		lineT3= 40;
		contadorT1=0;
		contadorT2=20;
		contadorT3=40;

	break;
	}
}
bool FileReader:: hasNext(int worker){
	bool result = false;
	if(chars > 0){
		result = true;
	}
	
	return result;
}

int FileReader:: getNext( char ** lineS, int worker){
        switch(strategy){
	case 1:
		if(worker==1){
		rewind(fileId);
		for(int i = 0; i<=lineT1; i++){
			chars = getline(lineS, & size, fileId);
		}
		lineT1++;
		}
		if(worker==2){
		rewind(fileId);
		for(int i = 0; i<=lineT2; i++){
			chars = getline(lineS, & size, fileId);
		}
		lineT2++;
		}
		if(worker==3){
		rewind(fileId);
		for(int i = 0; i<=lineT3; i++){
			chars = getline(lineS, & size, fileId);
		}
		lineT3++;
		}
	break;
	case 2:
		if(worker==1){
		rewind(fileId);
		for(int i = 0; i<=lineT1; i++){
			chars = getline(lineS, & size, fileId);
		}
		lineT1=lineT1+3;
		}
		if(worker==2){
		rewind(fileId);
		for(int i = 0; i<=lineT2; i++){
			chars = getline(lineS, & size, fileId);
		}
		lineT2=lineT2+3;
		}
		if(worker==3){
		rewind(fileId);
		for(int i = 0; i<=lineT3; i++){
			chars = getline(lineS, & size, fileId);
		}
		lineT3=lineT3+3;
		}
	break;
	case 3:
		rewind(fileId);
		for(int i = 0; i<lineT1; i++){
			chars = getline(lineS, & size, fileId);
		}
		lineT1++;
		chars = getline(lineS, & size, fileId);
	break;
	case 4:
		if(worker==1){
		rewind(fileId);
		if(contadorT1==lineT1){
		contadorT1= contadorT1+60;
		}
		for(int i = 0; i<=lineT1; i++){
			chars = getline(lineS, & size, fileId);
		}
		if(contadorT1==lineT1){
			lineT1=lineT1+40;
		}else {
			lineT1++;
		}
		
		}
		if(worker==2){
		rewind(fileId);
		if(contadorT2==lineT2){
		contadorT2= contadorT2+60;
		}
		for(int i = 0; i<=lineT2; i++){
			chars = getline(lineS, & size, fileId);
		}
		if(contadorT2==lineT2){
			lineT2=lineT2+40;
		}else {
			lineT2++;
		}
		
		}
		if(worker==3){
		rewind(fileId);
		if(contadorT3==lineT3){
		contadorT3= contadorT3+60;
		}
		for(int i = 0; i<=lineT3; i++){
			chars = getline(lineS, & size, fileId);
		}
		if(contadorT3==lineT3){
			lineT3=lineT3+40;
		}else {
			lineT3++;
		}
		
		}
		
	break;
	default:
	chars = getline(lineS, & size, fileId);
	break;
	}
	
	return chars;
}

FileReader::~FileReader(){
   free(line);
   fclose(fileId);
}
