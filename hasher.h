#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

void process(int);

void get_hash_of(char * message, char * info){
   FILE * hash;
   FILE * transfer;
   hash = fopen("US_TEXT.txt", "w+");
   fprintf(hash, "%s", message);
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
void clear_data(){
    FILE * hash;
    hash = fopen("US_TEXT.txt", "w+");
    fclose(hash);
    
}


void send_data(char data){
    FILE * hash;
    hash = fopen("US_TEXT.txt", "a+");
    fprintf(hash, "%c", data);
    fclose(hash);
}
int run_get_hash_of(char * info){
    int returner = 0;
    //system("python3 miner_good.py");
    
    char ch;
    char ata[32];
    //  puts("coming from run_get_hash_of");
    char zero = (char) 48;
    process(1);
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
    //puts("getting info");
    ata = hash(message);
    for(int b = 0; b < 32; b++){
    
        
        ch = ata[32];
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
    puts("Gotten info");
   // fclose(transfer);
   // puts("Closen text file");
    /*for(int i = 0;i<20;i++){
       
        if(data[i] != *zero){
            returner = i;
            break;
        }
        
    }
     
     
*/
    puts("");
    puts(ata);
    info = ata;
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
