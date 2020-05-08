#include <unistd.h> 
#include <stdio.h>
#include <ctype.h>
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
    

puts("started");

   int status = boot();
   if(status == 1){

   READ();
   while(&free){       
       clear();
       for(int i = 0; i < 1024; i++) line[i] = '\040';
       puts("Data to send (n to continue): ");
       scanf("%s", line);
       //char * data = line;
        // char * d2 = line;
       if ( (char *) strstr((const char *) line, "quit") != (char) 0) 
{ puts("quitting");
  message = "quited";
  SEND();
  Close();
  break;
  
}
      //printf("debug");
       message = line;
       SEND();
       wipe_sockets();
       

   }


}
  if(status == 0){
  message = "c";
  SEND();
  wipe_sockets();
int value = 0;
int stopper = 0;
  while(1){
      
       clear();
       
     //  for(int i = 0; i < 1024; i++) buffer[i] = '\040';

       READ();
      const char *  string = buffer;
     // puts("deEbug");
      if(stopper == 1){
          stopper = 0;
      }
      else {

       //char * d1 = buffer;
     if ( (char *) strstr((const char *) string, "verify") != (char) 0) 
{
  puts("verifying");
  int n_of_zeros = verify(buffer);
    putchar((char)(n_of_zeros + 48));
    puts("");
    stopper = 1;
} 

else if ( (char *) strstr((const char *) string, "test") != (char) 0)
{
   puts("Connected ");
   //clear();
    stopper = 1;
   
} 

else if ( (char *) strstr((const char *) string, "quited") != (char) 0)

{ 
  puts(" quitting ");
  
  break;
  value = 1;
  //stopper = 1;
} 

else  {
puts("Unkown command: ");
puts(string);
puts("TESTING");
puts(" ");
stopper = 1;
}
 
if (value == 1){ break; }

      
      // printf("%s", information);

clear();
       
      }
wipe_sockets();
       
    
   }


  }
   Close();
   return 0;

}


