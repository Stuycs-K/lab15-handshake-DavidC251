#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
}



int server_handshake(int* client){
	int WKP = mkfifo("WKP", 0666);
	wr


}
