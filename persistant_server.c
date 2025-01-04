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
    
    
     while(1){
	int* buff = malloc(sizeof(int));
  	
  	read(randFile, buff, sizeof(int));
	if(*buff < 0){
		*buff *= -1;
		
		
	}
	*buff %= 101;

	int bytes = write(to_client, buff, sizeof(int));
	if(bytes <= 0){
		break;
	}
	
	printf("SERVER SENT RANDOM INT: %d \n", *buff);
        sleep(1);

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


