#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;
  //to client is the private pipe
  from_client = server_handshake( &to_client );




int randFile = open("/dev/random", O_RDONLY, 0);
   while(1){
	int* buff = malloc(sizeof(int));
  	
  	read(randFile, buff, sizeof(int));
	if(*buff < 0){
		*buff *= -1;
		
		
	}
	*buff %= 101;
	write(to_client, buff, sizeof(int));
        sleep(1);

  }
}



