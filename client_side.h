//client_side.h
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "sockets.h"
#include <string.h>

struct connection conts;

const char*generateip(int i){
   //printf("%d", i);
   // char ** var;
    const int size = 11;
   char first_part[size] = "10.1.1.";

   char first = (char) floor(i/100)+ 48;
   //printf("%c", first);
   char second = (char) floor((i-((first-48)*100))/10) + 48;
   //printf("%c", second);
   char third = (char) i - (first-48)*100 - (second-48)*10 + 48;
   //printf("%c", third);
   int pos = size-4;
   char * zero = "0";
   if(first != *zero) {
      first_part[pos] = first;
      pos++;
   }
   if((second != *zero)||(pos != 7)){
      first_part[pos] = second;
      pos++;
   }
   
   first_part[pos] = third;


  
   char  *dita = first_part;
    char * var = (char *) malloc(size);;
    sprintf(var, "%s", dita);
    
  //  return (const char *) d
    
    return var;
   //d =  ip;
}

/*void scanports(){
    struct sockaddr_in sa;
    conts.PORT = 8987;
    conts.sock = 0;
    //
   strncpy((char*)&sa , "" , sizeof sa);
   sa.sin_family = AF_INET;
   for(int i = 0 ; i <= 256 ; i++)
   {
       int sock = 0;
       char *d = (char *) generateip(i);
       sa.sin_addr.s_addr = inet_addr(d);
       //Fill in the port number
       sa.sin_port = 8987;
       //Create a socket of type internet
       sock = socket(AF_INET , SOCK_STREAM , 0);
        
       //Check whether socket created fine or not
       if(sock < 0)
       {
           perror("\nSocket");
           exit(1);
       }
       //Connect using that socket and sockaddr structure
       int err = connect(sock , (struct sockaddr*)&sa , sizeof sa);
        
       //not connected
       //printf("hello \n");
       if( err < 0 )
       {
           puts("Cannot Connect");
           fflush(stdout);
       }
       //connected
       else
       {
           printf("%-5d open\n",  i);
       }
       close(sock);
   }
    
    
     
}
 */

