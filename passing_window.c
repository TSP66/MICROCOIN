//passing_window.c
//156 lines

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
const int MAX_number_of_connections = 10;
int number_of_sockets = 0;
int socket_number = 0;
char line[1024];
char information[100];
char * i = "hello";
struct connection SOCKETS[MAX_number_of_connections];

void OVERRIDEBOOT(){
    boot(SOCKETS[number_of_sockets]);
    number_of_sockets++;
}

int main(){

   puts("Starting...");
    
   for(int i = 0; i < MAX_number_of_connections; i++){
   SOCKETS[i].PORT = 8080;
   SOCKETS[i].ip = "127.0.0.1";
   SOCKETS[i].sock = 0
       }
    for(int i = 0; i < MAX_number_of_connections; i++){
        
    }
    defualts_for_first();
   int status = boot();
    inerface(status);
    
}
    
    void * inerface(void *vargp){
        int status = boot(SOCKETS[number_of_sockets]);
        number_of_sockets++;
         if(status == 1){
           puts("Welcome to MicroCoin terminal interaface. Waiting to connect to other node(s)...");
           puts("Commands (global mode): ");
            puts("  Verify - Usage: verify-difficulty-hash");
            puts("  Test - Usage: test");
            puts("  Quit - Usage: quit");
            puts("");
           READ();
           while(&free){
               //printf("Loading...");
               clear();
               for(int i = 0; i < 1024; i++) line[i] = '\000';
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
              puts("Connected as client, processes are automatic.");
          message = "c";
          SEND();
          wipe_sockets();
        int value = 0;
        int stopper = 0;
          while(1){
              puts("Loading...");
               clear();
               
             //  for(int i = 0; i < 1024; i++) buffer[i] = '\040';

               READ();
              //const char * string = buffer;
             // puts("deEbug");
              if(stopper == 1){
                stopper = 0;
              }
              else {

               //char * d1 = buffer;
             if ( (char *) strstr((const char *) buffer, "verify") != (char) 0)
        {
            char * d = buffer+7;
            int difficulty = (int) *d;
            difficulty = difficulty - 48;
            
            puts("verifying");
            int n_of_zeros = verify(buffer);
            
           if(difficulty == n_of_zeros) puts("confirmed");
           else puts("not confirmed: not enough zeros");
            
            clear();
            
        }

        else if ( (char *) strstr((const char *) buffer, "test") != (char) 0)
        {
           puts("Connected ");
           //clear();
            stopper = 1;
            
            clear();
           
        }

        else if ( (char *) strstr((const char *) buffer, "quited") != (char) 0)

        {
          puts(" quitting ");
          value = 1;
            clear();
          break;
         
          //stopper = 1;
        }

        else  {
        puts("Unkown command: ");
        puts(buffer);
        puts("TESTING");
        puts(" ");
        stopper = 1;
            clear();
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

    }

