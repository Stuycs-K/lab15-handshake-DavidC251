#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

   //from_server is private
   while(1){
	
	int* buff = malloc(sizeof(int));
	if(read(from_server, buff, sizeof(int)) == 0){
		
		exit(1);
		
	}
	else{
        printf("RECIEVED RANDOM INT: %d \n", *buff);
 	 }
}
}



