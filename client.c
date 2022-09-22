#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <err.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int socketServer;

int main(){
	// Socket
	socketServer = socket(AF_INET, SOCK_STREAM, 0);

	// Address
	struct sockaddr_in addrServer;
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.7");
	addrServer.sin_port = htons(19840);

	// Connect
	int connection_status = connect(socketServer, (struct sockaddr *) &addrServer, sizeof(addrServer));

	// Check for error with the connection
	if(connection_status != 0){
		printf("failed to connect\n");
		return 1;
	}
	printf("connected\n");

	while(1){
		
	}


	close(socketServer);

	return 0;
}
