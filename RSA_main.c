#include <stdio.h>
#include "rsa.h"
#include "primes.h"

int main(){
    
    puts("Opening files...");
    FILE * primes = fopen("Private_Key.txt", "r");
    FILE * public = fopen("Public_Key.txt", "r");
    puts("Done");
    if((primes == NULL)||(public == NULL)){
    puts("Generating public and private keys.. This should take a couple minutes");
    init();
        puts("Done... Writing data to files");
    FILE * primes = fopen("Private_Key.txt", "w+");
    int aBack1 = (int)(Q >> 8);
    int bBack2 = (int)Q; 
    fputc( (char) aBack1, primes);
    fputc( (char) bBack2, primes);
    fclose(primes);
        FILE * public = fopen("Public_Key.txt", "w+");
    int cBack1 = (int)(P >> 8);
        int dBack2 = (int) P;
        fputc( (char) cBack1, public);
        fputc( (char) dBack2, public);
        fclose(public);
    puts("Done");
    }
    
    
    else{
    
        puts("Getting info...");
    int data[4];
     
     int ch;
     
     //unsigned long SIZE = 100;
     int i = 0;
     while((ch = fgetc(primes)) != EOF){
         data[i] = ch;
         i++;
    }
        Q = (data[0] * 256) + data[1];
        printf("Q is: %ld", Q);
        puts("");
    
    int data2[4];
     
     int ch2;
     
     //unsigned long SIZE = 100;
     int i2 = 0;
     while((ch2 = fgetc(primes)) != EOF){
         data2[i] = ch2;
         i2++;
    }
        P = (data2[0] * 256) + data2[1];
        
        printf("P is: %ld", P);
    }

    
    return 0;

}
