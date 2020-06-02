//sockets_local.h

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#define LOCAL_PORT 8079 //port, defualt 8079 for local connections

char * local_ip = "127.0.0.1"; // ip address "112.213.34.190"
char * ip_address;
void lclear(void);
char * local_buffer;
char * local_message;

//fda0:3e59:2ef8::6892:4d75:e33c:8d3d
//14.2.157.137
//10.1.1.209

//char buffer;
char Local_Data[1024] = {0}; //local
int lsock = 0;
 
int local_setup_as_server(int port)
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
	if ((lsock = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0) 
	{ 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	}
    ip_address = inet_ntoa(address.sin_addr);
    puts(ip_address);
return 0;
	
} 



int local_setup_as_client(int port)
{ 
	int valread; 
	struct sockaddr_in serv_addr; 
	 
	if ((lsock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{ 
		//printf("\n Socket creation error \n");
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(port); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, local_ip, &serv_addr.sin_addr)<=0)
	{ 
		//printf("\nInvalid address/ Address not supported \n");
		return -1; 
	} 

	if (connect(lsock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{ 
		//printf("\n Setting up as server \n"); 
		return -1; 
	} 
return 0;

} 

void LSEND(){
        send(lsock , local_message , strlen(message) , 0 );

}

int lcheck(void);

void LREAD(){
        lclear();
        int valread;
    while(check() == 0){
        clear();
        valread = read(lsock , Local_Data, 1024);
    }
    //printf("Data: ");
    //printf("%s", Data);

    local_buffer = Local_Data;
        
        
}

int lcheck(){
    int returner = 0;
    for(int i = 0; i < 1024; i++){
        if(Data[i] != '\000') {
            returner = 1;
            break;
        }
    }
    return returner;
}


void lclear(){
   for(int i = 0; i < 1024; i++){
   Data[i]  = '\000' ;
   buffer[i] = '\000' ;
}


}

void LClose(){ close(sock); }
void Lwipe_sockets(){ clear(); SEND(); }
  
