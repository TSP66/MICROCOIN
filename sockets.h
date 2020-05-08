//sockets.h

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h> 

#define PORT 8091

void clear(void);

char * message;

char * buffer;
char Data[1024] = {0}; //local
int sock = 0;
 
int setup_as_server(int port) 
{ 
	int server_fd, valread; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	
	
	
	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	// Forcefully attaching socket to the port 8080 
	/*if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
												&opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	}
*/ 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( port ); 
	
	// Forcefully attaching socket to the port 8080 
	if (bind(server_fd, (struct sockaddr *)&address, 
								sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((sock = accept(server_fd, (struct sockaddr *)&address, 
					(socklen_t*)&addrlen))<0) 
	{ 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 
return 0;
	
} 



int setup_as_client(int port) 
{ 
	int valread; 
	struct sockaddr_in serv_addr; 
	 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(port); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\n Setting up as server \n"); 
		return -1; 
	} 
return 0;

} 

void SEND(){
        send(sock , message , strlen(message) , 0 );

}
void READ(){
        clear();
        int valread;
        valread = read(sock , Data, 1024);
        buffer = Data;
        
        
}

int boot(){
 buffer = (char*) malloc(1024 * sizeof(char)); 
 int b = 0; 
 if(setup_as_client(PORT) == -1){
 setup_as_server(PORT);
 b = 1;
}
return b;
}

void clear(){
   for(int i = 0; i < 1024; i++){
   Data[i]  = '\040' ;
   buffer[i] = '\040' ;
}


}

void Close(){ close(sock); }
void wipe_sockets(){ clear(); SEND(); }
  