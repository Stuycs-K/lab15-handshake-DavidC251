#include "pipe_networking.h"

int main() {
  int randFile = open("/dev/random", O_RDONLY, 0);

  signal(SIGPIPE, ignore_SIGPIPE);
  signal(SIGINT, sigint_handler);
  while(1){
    int to_client;
    int from_client;
  
    from_client = server_setup();
    
    
    if(fork() == 0){
     	to_client = server_handshake_half(&to_client, from_client);
	

	while(1){
		char* linebuff = malloc(256);
		int bytes;
		bytes = read(from_client, linebuff, 255);
		if(bytes <= 0){

			break;
		}
		printf("SERVER RECIEVED MESSAGE: %s", linebuff);
		


	}
	exit(1);
    }
    close(to_client);
    close(from_client);


  }



  
}


static void ignore_SIGPIPE(int signum){

	

}

static void sigint_handler(int signum){
	remove("WellKnownPipe");
	exit(1);
	

}


