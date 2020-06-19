//sockets.h
//181 lines

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h> 

int PORT = 8080; //port, defualt 8080

struct connection{
    int PORT;
    char * ip;
    char * ip_address;
    char * buffer;
    char * message;
    char Data[1024];
    int sock;
    struct sockaddr_in address;
    pthread_t thread;
    

};
struct connection FIRST;

void defualts_for_first(){
    FIRST.PORT = 8080;
    FIRST.ip = "127.0.0.1";
    FIRST.sock = 0;
}

void clear(struct connection);

//fda0:3e59:2ef8::6892:4d75:e33c:8d3d
//14.2.157.137
//10.1.1.209

//char buffer;

 
int setup_as_server(int port, struct connection C)
{ 
	int server_fd, valread;
	int opt = 1; 
	int addrlen = sizeof(C.address);
	
	
	
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
	C.address.sin_family = AF_INET;
	C.address.sin_addr.s_addr = INADDR_ANY;
	C.address.sin_port = htons( C.PORT);
	
	// Forcefully attaching socket to the port 8080 
	if (bind(server_fd, (struct sockaddr *)&C.address,
								sizeof(C.address))<0)
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((C.sock = accept(server_fd, (struct sockaddr *)&C.address,
					(socklen_t*)&addrlen))<0) 
	{ 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	}
    C.ip_address = inet_ntoa(C.address.sin_addr);
    puts(C.ip_address);
return 0;
	
} 



int setup_as_client(int port, char * ip)
{
	int valread;
    int sock = 0;
	struct sockaddr_in serv_addr; 
	 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{ 
		printf("\n Socket creation error \n");
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(port);
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0)
	{ 
		printf("\nInvalid address/ Address not supported \n");
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{ 
		//printf("\n Setting up as server \n");
		return -1; 
	}
 
return sock;

} 

void SEND(struct connection C){
        send(C.sock , C.message , strlen(C.message) , 0 );

}

int check(struct connection);

void READ(struct connection C){
        clear(C);
        int valread;
    while(check(C) == 0){
        clear(C);
        valread = read(C.sock , C.Data, 1024);
    }
    //printf("Data: ");
    //printf("%s", Data);

    C.buffer = C.Data;
        
        
}

int check(struct connection C){
    int returner = 0;
    for(int i = 0; i < 1024; i++){
        if(C.Data[i] != '\000') {
            returner = 1;
            break;
        }
    }
    return returner;
}

int boot(struct connection C){
 //printf("Data: ");
C.buffer = (char*) malloc(1024 * sizeof(char));
 int b = 0;
 C.sock = setup_as_client(C.PORT, C.ip);
 if(C.sock == -1){
 setup_as_server(C.PORT, C);
 b = 1;
}
return b;
}

void clear(struct connection C){
   for(int i = 0; i < 1024; i++){
   C.Data[i]  = '\000' ;
   C.buffer[i] = '\000' ;
}


}

void Close(struct connection C){ close(C.sock); }
void wipe_sockets(struct connection C){ clear(C); SEND(C); }
  
