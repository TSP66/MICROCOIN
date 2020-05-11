//passing_window.c

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


//verify-1-hellowmskmk|  - Command and hash used to test, should return 1 zero


char line[1024];
char information[100];
char * i = "hello";

int main(){
    

   puts("Starting...");
   puts("Welcome to MicroCoin terminal interaface. Waiting to connect to other node(s)...");
   puts("Commands (global mode): ");
    puts("Verify - Usage: verify-difficulty-hash");
    puts("Test - Usage: test");
    

   int status = boot();
   if(status == 1){

   READ();
   while(&free){       
       clear();
       for(int i = 0; i < 1024; i++) line[i] = '\040';
       puts("Commands (to other nodes): ");
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
    char * d = buffer+7;
    int difficulty = (int) *d;
    difficulty = difficulty - 48;
    
    puts("verifying");
    int n_of_zeros = verify(buffer);
    
   if(difficulty == n_of_zeros) puts("confirmed");
   else puts("not confirmed: not enough zeros");
    
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


