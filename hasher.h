//hasher.h
//119 lines
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include "md5.h"

void process(int);

/*void get_hash_of(char * message, char * info, struct connection C){
   FILE * hash;
   FILE * transfer;
   hash = fopen("US_TEXT.txt", "w+");
   fprintf(hash, "%s", C.message);
   fclose(hash);
    puts("coming from get_hash_of");
   system("python3 verify.py");
   char ch;
   char data[32];
    process(3);
   transfer = fopen("transfer_PtoC.txt", "r");
   int i = 0;
   for(int b = 0; b < 32; b++){
        ch = fgetc(transfer);
        data[i] = ch;
        i++;
   }
    
 info = data;
    fclose(transfer);

}
*/

char global_array_forhash[32];
int pointofGAFA = 0;

void clear_data(){
    pointofGAFA = 0;
    
}
void send_data(char data){
    global_array_forhash[pointofGAFA] = data;
    pointofGAFA++;
}
int run_get_hash_of(char * info){
    int returner = 0;
    //system("python3 miner_good.py");
    
    char ch;
    //  puts("coming from run_get_hash_of");
    char zero = (char) 48;
    //process(1);
    //system("sync; sync; sync; sync; sync");
    //puts("hello");
    //char *ZERO = *zero
    //puts("opening file");
    //FILE *transfer = fopen("transfer_PtoC.txt", "r");
    //if(transfer == NULL) {
      //   perror("Error in opening file");
    //}
    
    int gh = 0;
    int prev = 0;
   // puts("Getting info");
    char * ata;
    ata = (char *) malloc(32*sizeof(char));
    ata = (char *) md5(info, 256);
    
    
   // puts("Done");
    for(int b = 0; b < 32; b++){
    
        
        ch = ata[gh];
           //  printf("%c", ch);
        
        
     //   puts("");
        if((int)ch == 48){
            if(prev == 0){
                returner++;
            }
        }
        else {
           prev = 1;
        }
        
        gh++;
       

    }
//    puts("Gotten info");
   // fclose(transfer);
   // puts("Closen text file");
    /*for(int i = 0;i<20;i++){
       
        if(data[i] != *zero){
            returner = i;
            break;
        }
        
    }
     
     */
   // puts(ata);
    return(returner);
}
void process(int time){
    long x = time*3600;
    long c = time*3000;
    for(int i = 0; i < x; i++){
        for(int d = 0; d < c; d++) {
            long b = i^d;
        }
    }
}
