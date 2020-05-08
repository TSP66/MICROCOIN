
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include "sockets.h"

int main(){

message = " hello ";

int I = boot();
if(I == 0){
 
 READ();
    printf("Enter text: ");
   fgets(message,1024,stdin);
 SEND();
}
if(I == 1){
    printf("Enter text: ");
fgets(message,1024,stdin);
SEND();
READ();

}

return 0;

}
