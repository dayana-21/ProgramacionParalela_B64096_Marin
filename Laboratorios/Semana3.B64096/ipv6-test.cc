#include <stdio.h>
#include <string.h>
#include "Socket.h"

int main( int argc, char * argv[] ) {

   Socket s( 's', true );
   char a[512];

   memset( a, 0, 512 );
   s.Connect( (char *) "fe80::a84c:9cd8:269e:db76%enp0s3", (char *) "7002" );
   s.Write(  (char *) "GET / HTTP/1.1\r\nhost: redes.ecci\r\n\r\n", 36 );
   s.Read( a, 512 );
   printf( "%s\n", a);
}
