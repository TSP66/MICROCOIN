#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include "sockets.h"
#include "hasher.h"
#include "BASIC_FUNCTIONS.h" 



char line[1024];
char information[100];
char * i = "hello";

int main(){
printf("started");
   int status = boot();
   if(status == 1){

   READ();
   while(&free){
       clear();
       for(int i = 0; i < 1024; i++) line[i] = '\040';
       printf("Data to send (n to continue): ");
       scanf("%s", line);
       //char * data = line;
        // char * d2 = line;
       if ( (char *) strstr((const char *) line, "quit") != (char) 0) 
{ printf("quitting");
printf("LastSend");
  message = "quited";
  SEND();
  break;
}
printf("sending");
       message = line;
       SEND();
       
       

   }

}
  if(status == 0){
  message = "c";
  SEND();
  while(&free){
       clear();
       READ();
       printf("going");
   }

  }
   return 0;
}


