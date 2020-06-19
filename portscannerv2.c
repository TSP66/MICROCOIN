#include "stdio.h"
#include "sys/socket.h"
#include "errno.h"
#include "netdb.h"
#include "string.h"
#include "stdlib.h"
#include <unistd.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include "client_side.h"

#define PORT 8000

void scan(struct sockaddr_in SA, int port, char*  ip, int time_out){
  //Initialise the sockaddr_in structure
    
    
   int err;
    strncpy((char*)&SA , "" , sizeof SA);
    SA.sin_family = AF_INET;
    int sock = 0;
   
    SA.sin_addr.s_addr = inet_addr(ip);
       
    
        //Fill in the port number
        SA.sin_port = htons(port);
        //Create a socket of type internet
        sock = socket(AF_INET , SOCK_STREAM , 0);
         
        //Check whether socket created fine or not
        if(sock < 0) 
        {
            perror("\nSocket");
            exit(1);
        }
        //Connect using that socket and sockaddr structure
    err = connect(sock , (struct sockaddr*)&SA , sizeof SA);
         
        //not connected
        //printf("hello \n");
        if( err < 0 )
        {
           printf("%s %-5d %s\n" , ip , port, strerror(errno));
          fflush(stdout);
        
            
        }
        //connected
        else
        {
            printf("%-5d open\n",  port);
        }
        close(sock);
    
     
    printf("\n");
    fflush(stdout);
    
}
 
int main(int argc , char **argv)
{
    struct hostent *host;
    int err, i , sock ,start , end;
    char hostname[100];
    struct sockaddr_in sa;
     
    //Get the hostname to scan
   // printf("Enter hostname or IP : ");
    //gets(hostname);
     
    //Get start port number
    start = 1;
    end = 100;
    for(int i = 1; i<256; i++){
        char *d = (char *) generateip(i);
        scan(sa, PORT, d, 10);
    }
    
  
}

