#include "pipe_networking.h"

int main() {
  while(1){
  	int to_client;
  	int from_client;
  
  	from_client = server_setup();
    to_client = server_connect(from_client);
    
    
	//ctrl c the client
    while(){
		
		
	}
    close(to_client);
	close(from_client);


  }



  
}



