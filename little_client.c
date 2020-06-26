//little_client.c 

#include "sockets.h"

int main (){
    int sock = setup_as_client(8987, "127.0.0.1");
    char * message = "verify-1-hhnjs|";
    send(sock , message , strlen(message) , 0 );
    return 0;
}