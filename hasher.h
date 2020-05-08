#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>


void get_hash_of(char * message, char * info){
   FILE * hash;
   FILE * transfer;
   hash = fopen("US_TEXT.txt", "w+");
   fprintf(hash, "%s", message);
   fclose(hash);
   system("python3 miner_good.py");
   char ch;
   char data[32];
   transfer = fopen("transfer.txt", "r+");
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
void run_get_hash_of(char * info, int no0){
    int returner = 0;
    FILE * transfer;
    system("python3 miner_good.py");
    char ch;
    char data[32];
    char zero = (char) 48;
    //char *ZERO = *zero
    transfer = fopen("transfer.txt", "r+");
    int i = 0;
    int prev = 0;
    for(int b = 0; b < 32; b++){
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
    /*for(int i = 0;i<20;i++){
       
        if(data[i] != *zero){
            returner = i;
            break;
        }
        
    }
     
     
*/
    puts("ZEROS: ");
    printf("%d", returner);
    puts("");
    puts(data);
    no0 = returner;
    info = data;
}
