#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <regex>
#include <iostream>

class FileReader {

private:
   int workers,lineaW1,lineaW2,lineaW3;				
   int strategy;			
   int totalLines;			
   FILE * fileId;	
   int chars;
   size_t size;
   char * line;
   int lineT1,lineT2,lineT3;		

public:
   FileReader( const char * fileName, int workers = 1, int strategy = 1 );
   ~FileReader();
   bool hasNext( int worker = 0 );
   int getNext( char ** line, int worker = 0 );

};
