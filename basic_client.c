#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

   //from_server is private
   while(1){
	char* linebuff = malloc(256);
	fgets(linebuff, 255, stdin);
	int bytes;
	bytes = write(to_server, linebuff, 255);
	if(bytes <= 0){
		break;
	}
   }
}



