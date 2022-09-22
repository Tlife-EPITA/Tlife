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

#define MAX_CLIENTS 		10
#define BUFFER_SIZE			2048

typedef struct{
	struct sockaddr_in address;
	int socket;
	int uid;
} client_t;

int usersOnline = 0;

char* str_ip_addr(char *str, struct sockaddr_in addr){
	sprintf(str, "%d.%d.%d.%d", addr.sin_addr.s_addr & 0xff,
	(addr.sin_addr.s_addr & 0xff00) >> 8,
	(addr.sin_addr.s_addr & 0xff0000) >> 16,
	(addr.sin_addr.s_addr & 0xff000000) >> 24);
	return str;
}

int main(){
	// Socket
	int socketServer;
	socketServer = socket(AF_INET, SOCK_STREAM, 0);

	// Address
	struct sockaddr_in addrServer;
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.7");
	addrServer.sin_port = htons(19840);

	// Bind
	if(bind(socketServer, (const struct sockaddr *) &addrServer, sizeof(addrServer)) < 0){
		errx(EXIT_FAILURE, "ERROR: bind\n");
	}
	printf("bind : %d\n", socketServer);

	// Listen
	if(listen(socketServer, MAX_CLIENTS) < 0){
		errx(EXIT_FAILURE, "ERROR: listen\n");
	}
	printf("listenning...\n");


	pthread_t thread;
	printf("=== INITIATED ===\n");
	int uid = 0;

	while(1){
		struct sockaddr_in addrClient;
		socklen_t csize = sizeof(addrClient);
		int socketClient = accept(socketServer, (struct sockaddr *) &addrClient, &csize);

		if(usersOnline + 1 == MAX_CLIENTS){
			printf("Connection rejected: Maximum clients connected\n");
			close(socketClient);
			continue;
		}

		client_t *client = malloc(sizeof(client_t));
		client->address = addrClient;
		client->socket = socketClient;
		client->uid = uid++;

		char buffer[BUFFER_SIZE];
		printf("new connection accepted(%s)(%d)(%d).\n", str_ip_addr(buffer, client->address), client->socket, client->uid);

		// Reduce CPU usage
		sleep(0.5);
	}
	
	return 0;
}
