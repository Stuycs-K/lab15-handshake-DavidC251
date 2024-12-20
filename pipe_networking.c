#include "pipe_networking.h"
//UPSTREAM = to the server / from the client
//DOWNSTREAM = to the client / from the server
/*=========================
  server_setup

  creates the WKP and opens it, waiting for a  connection.
  removes the WKP once a connection has been made

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_setup() {
  int from_client = 0;
  mkfifo("WellKnownPipe", 0666);
  from_client = open("WellKnownPipe", O_RDONLY, 0);
  //wait for connection
  //int pp = client_handshake(from_client);
  //remove WKP(create the subserver first)


  
  close(from_client);


	
  return from_client;
}

/*=========================
  server_handshake 
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe (Client's private pipe).

  returns the file descriptor for the upstream pipe (see server setup).
  =========================*/
int server_handshake(int *to_client) {
  int from_client;
  from_client = server_setup();
  //unblocked client
  int bytes;
  int* buff = malloc(sizeof(int));
  bytes = read(from_client, buff, sizeof(int));
  //step 5 reading PID(SYN)
  printf("Server Recieved PID: %d \n", *buff);
  buff = malloc(sizeof(unsigned int));
  *to_client = server_connect(from_client);

  //unblocks here
  unsigned int buff2 = malloc(sizeof(unsigned int))
  int randFile = open("/dev/random", O_RDONLY, 0);
  read(randomFile, buff2, sizeof(unsigned int));
	//SYN ACK
  write(to_client*, buff2, sizeof(unsigned int));


  //open again?
  unsigned int* buff3 = malloc(sizeof(unsigned int));
  bytes = read(from_client, buff3, sizeof(unsigned int));
  //step 9 reading ACK

  
  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int from_server;
  mkfifo("PrivatePipe", 0666);
  to_server* = open("WellKnownPipe", O_WRONLY, 0);
  int* PID = getpid();
  write(to_server*, PID, sizeof(int));
  //should unblock here
  from_server = open("PrivatePipe", O_RDONLY, 0);
  unsigned int* syn_ack = malloc(sizeof(unsigned int));
  read(from_server, syn_ack, sizeof(unsigned int));
  unsigned int ack = syn_ack + 1;
  write(to_server*, ack, sizeof(unsigned int));
  

  return from_server;
}


/*=========================
  server_connect
  args: int from_client

  handles the subserver portion of the 3 way handshake

  returns the file descriptor for the downstream pipe.
  =========================*/
int server_connect(int from_client) {
  int to_client  = 0;
  to_client = open("PrivatePipe", O_WRONLY, 0);
  return to_client;
}


