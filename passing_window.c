//passing_window.c
//156 lines

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h>
#include <pthread.h>
#include <string.h> 
#include "sockets.h"
#include "hasher.h"
#include "BASIC_FUNCTIONS.h"

void * inerface(void *);
//verify-1-hellowmskmk|  - Command and hash used to test, should return 1 zero
const int MAX_number_of_connections = 1;
int number_of_sockets = 0;
int socket_number = 0;
char line[1024];
char information[100];
char * i = "hello";
struct connection SOCKETS[MAX_number_of_connections];

int main(){

   puts("Starting...");
    
   for(int i = 0; i < MAX_number_of_connections; i++){
   SOCKETS[i].PORT = 8080;
   SOCKETS[i].ip = "127.0.0.1";
       SOCKETS[i].sock = 0;
       }
    for(int i = 0; i < MAX_number_of_connections; i++){
     pthread_create( &SOCKETS[i].thread, NULL , inerface , NULL);
        puts("Creating Threads");
    }
    //defualts_for_first();
   //int status = boot();
  for(int i = 0; i < MAX_number_of_connections; i++){
      puts("Starting Threads");
      pthread_join(SOCKETS[i].thread, NULL);
  }
    
    
    
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
             
           READ(SOCKETS[socket_number]);
           while(&free){
               //printf("Loading...");
               clear(SOCKETS[socket_number]);
               for(int i = 0; i < 1024; i++) line[i] = '\000';
               puts("Commands (to other nodes): ");
               scanf("%s", line);
               //char * data = line;
                // char * d2 = line;
               if ( (char *) strstr((const char *) line, "quit") != (char) 0)
        { puts("quitting");
          message = "quited";
          SEND(SOCKETS[socket_number]);
          Close(SOCKETS[socket_number]);
          break;
          
        }
              //printf("debug");
               message = line;
               SEND(SOCKETS[socket_number]);
               wipe_sockets(SOCKETS[socket_number]);
               

           }


        }
          if(status == 0){
              puts("Connected as client, processes are automatic.");
              
          SOCKETS[socket_number].message = "c";
          SEND(SOCKETS[socket_number]);
          wipe_sockets(SOCKETS[socket_number]);
        int value = 0;
        int stopper = 0;
          while(1){
              puts("Loading...");
               clear(SOCKETS[socket_number]);
               
             //  for(int i = 0; i < 1024; i++) buffer[i] = '\040';

               READ(SOCKETS[socket_number]);
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
            int n_of_zeros = verify(buffer, SOCKETS[socket_number]);
            
           if(difficulty == n_of_zeros) puts("confirmed");
           else puts("not confirmed: not enough zeros");
            
            clear(SOCKETS[socket_number]);
            
        }

        else if ( (char *) strstr((const char *) buffer, "test") != (char) 0)
        {
           puts("Connected ");
           //clear();
            stopper = 1;
            
            clear(SOCKETS[socket_number]);
           
        }

        else if ( (char *) strstr((const char *) buffer, "quited") != (char) 0)

        {
          puts(" quitting ");
          value = 1;
            clear(SOCKETS[socket_number]);
          break;
         
          //stopper = 1;
        }

        else  {
        puts("Unkown command: ");
        puts(buffer);
        puts("TESTING");
        puts(" ");
        stopper = 1;
            clear(SOCKETS[socket_number]);
        }
         
        if (value == 1){ break; }

              
              // printf("%s", information);

        clear(SOCKETS[socket_number]);
               
              }
        wipe_sockets(SOCKETS[socket_number]);
               
            
           }


          }
           Close(SOCKETS[socket_number]);
           return 0;

        }


