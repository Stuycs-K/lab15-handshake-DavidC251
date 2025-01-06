#include "pipe_networking.h"

int main() {
  int randFile = open("/dev/random", O_RDONLY, 0);

  signal(SIGPIPE, ignore_SIGPIPE);
  signal(SIGINT, sigint_handler);
  while(1){
    int to_client;
    int from_client;
  
    from_client = server_setup();
    to_client = server_connect(from_client);
    
    if(fork() == 0){
     	server_handshake_half(&to_client, from_client);
	while(1){
		char* linebuff = malloc(256);
		if(read(from_client, linebuff, 255) <= 0){

			break;
		}
		printf("SERVER RECIEVED MESSAGE: %s \n", linebuff);
		


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


