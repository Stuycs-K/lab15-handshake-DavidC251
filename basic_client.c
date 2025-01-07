#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  signal(SIGPIPE, handle_SIGPIPE);
   //from_server is private
   while(1){
	//check if server exitted
	


	char* linebuff = malloc(256);
	printf("Please enter a line: \n");
	fgets(linebuff, 255, stdin);
	int bytes;
	
	bytes = write(to_server, linebuff, 255);
	
	if(bytes <= 0){
		fflush(stdout);
		printf("ERROR: SERVER CLOSED \n");
		fflush(stdout);
		exit(0);
	}
	char* servermsg = malloc(256);
	read(from_server, servermsg, 255);
	printf("Waiting for server to confirm sent message... \n");
	if(strcmp(servermsg, "EXIT") == 0){
		fflush(stdout);
		printf("ERROR: SERVER CLOSED \n");
		fflush(stdout);
		exit(0);
	}
	
   }
}

static void handle_SIGPIPE(int signum){
	printf("ERROR: SERVER CLOSED \n");
	exit(0);
	

}



