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
   system("python3 verify.py");
   char ch;
   char data[32];
    process(3);
   transfer = fopen("transfer.txt", "r");
   int i = 0;
   for(int b = 0; b < 32; b++){
        ch = fgetc(transfer);
        data[i] = ch;
        i++;
   }
 info = data;

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
    FILE * transfer;
    system("python3 miner_good.py");
    char ch;
    char data[32];
    char zero = (char) 48;
    //process(3);
    //char *ZERO = *zero
    //puts("opening file");
    transfer = fopen("transfer.txt", "r+");
    int i = 0;
    int prev = 0;
    //puts("getting info");
    for(int b = 0; b < 32; b++){
        //printf("%d", b);
         ch = fgetc(transfer);
         data[i] = ch;
      //  printf("%c", ch);
     //   puts("");
        if((int)ch == 48){
            if(prev == 0){
                returner++;
            }
        }
        else prev = 1;

        
        
         i++;
        

    }
    puts("Gotten info");
    fclose(transfer);
    /*for(int i = 0;i<20;i++){
       
        if(data[i] != *zero){
            returner = i;
            break;
        }
        
    }
     
     
*/
    puts("");
    puts(data);
    info = data;
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
