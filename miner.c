//miner.c
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include "coin.h"
#include "hasher.h"
#include <math.h>

char block[256];


int split(long long time, int digit);
int get_digits(int num);
int internal_get_digits(int number, int point);
int Randoms(int lower, int upper);

char *senders_address = "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8";

char *recivers_address = "d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3";

char *miners_address = "86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47";

char *senders_signature = "397eb05607c41db8a1ebb2a2c27f06998e9b2a31be71db2167d24c8b5c879e6c509c71c5bf2562fc642cc4efd585b54981306cd96bbc29e50c04748e05562008";

int value = 120;
int transation_cost = 8;
char *zero = "0";
int main () 
{ 
    //time_t seconds;
      
    long long seconds = (long long) time(NULL);
    
    //printf("%lld", seconds);
    
    if(floor(coin_difficulty/10) != 0){
    block[0] = floor(coin_difficulty/10) + *zero;
    block[1] = coin_difficulty - 10*(floor(coin_difficulty/10)) + *zero;

    }
    else{
    block[0] = *zero;
    block[1] = coin_difficulty + *zero;
    }
    
    block[2] = *SEPERATOR;
    
    if(floor(coin_number_award/100) != 0){
    block[3] = floor(coin_number_award/100) + *zero;
    block[4] = floor((coin_number_award - 100*(floor(coin_number_award/100)))/10) + *zero;
    block[5] = coin_number_award - block[3]*100 - block[4]*10 + *zero;

    }
    
    else if(floor(coin_number_award/10) != 0){
    block[3] = *zero;
    block[4] = floor(coin_number_award/10) + *zero;
    block[5] = coin_number_award - 10*(floor(coin_number_award/10)) + *zero;

    }
    else{
    block[3] = *zero;
    block[4] = *zero;
    block[5] = coin_number_award + *zero;
    }
    
    block[6] = *SEPERATOR;
    
    if(floor(coin_number_block/100) != 0){
    block[7] = floor(coin_number_block/100) + *zero;
    block[8] = floor((coin_number_block - 100*(floor(coin_number_block/100)))/10) + *zero;
    block[9] = coin_number_block - block[7]*100 - block[8]*10 + *zero;

    }
    
    else if(floor(coin_number_block/10) != 0){
    block[7] = *zero;
    block[8] = floor(coin_number_block/10) + *zero;
    block[9] = coin_number_block - 10*(floor(coin_number_block/10)) + *zero;

    }
    else{
    block[7] = *zero;
    block[8] = *zero;
    block[9] = coin_number_block + *zero;
    }
    
    block[10] = *SEPERATOR;
    
    for(int i = 0; i < 32; i++){
        block[11+i] = *(recivers_address + i); //put recivers address into array
    }
    block[43] = *SEPERATOR;
    for(int i = 0; i < 32; i++){
           block[44+i] = *(senders_address + i); //put senders address into array
       }
    block[75] = *SEPERATOR;
    
    for(int i = 0; i < 32; i++){
        block[76+i] = *(senders_address + i); //put miners address into array
    }
    
    block[108] = *SEPERATOR;
    
    if(floor(value/100) != 0){
    block[109] = floor(value/100) + *zero;
    block[110] = floor((value - 100*(floor(value/100)))/10) + *zero;
    block[111] = split(value, 1) + *zero;

    }
    
    else if(floor(value/10) != 0){
    block[109] = *zero;
    block[110] = floor(value/10) + *zero;
    block[111] = split(value, 1);

    }
    else{
    block[109] = *zero;
    block[110] = *zero;
    block[111] = value + *zero;
    }
    
    block[112] = *SEPERATOR;

    if(floor(transation_cost/100) != 0){
       block[113] = floor(transation_cost/100) + *zero;
       block[114] = floor((transation_cost - 100*(floor(transation_cost/100)))/10) + *zero;
        block[115] = transation_cost - block[113]*100 - block[114]*10 + *zero;
    }
    else if(floor(transation_cost/10) != 0){
    block[113] = *zero;
    block[114] = floor(transation_cost/10) + *zero;
    block[115] = value - 10*(floor(transation_cost/10)) + *zero;

    }
    else{
    block[113] = *zero;
    block[114] = *zero;
    block[115] = transation_cost + *zero;
    }
    
    block[116] = *SEPERATOR;
    
    for(int i = 0; i < 64; i++){
        block[117+i] = *(senders_address + i); //put senders signature into array
    }

    block[181] = *SEPERATOR;
    //
    //Timestamp
    
    for(int i = 0; i < 10; i++){
        block[182+i] = (char) split(seconds, (10-i)) + *zero;
    }
     
    
    block[192] = *SEPERATOR;
    long long ses = (long long) time(NULL);
    for(unsigned long long ff = 0; ff < 100000000000; ff++){
        
        
        srand(ff);
       
        int j = 193;
        for(int zz = 193; zz<256; zz++){
            sprintf(&block[zz], "%x", Randoms(0,15));
        }
        
        int d = run_get_hash_of(block);
        if(d == 7){
            printf("Yeah");
            long long ses2 = time(NULL) - ses;
            printf("%lld", ses2);
            break;
        }
        
    }
    
 
    return(0);
}

int split(long long time, int digit){
    if(digit == 1){
      return(time-10*(floor(time/10)));
    }
    int result = floor(time/(pow(10, digit)));
    long long push = (long long) ((time-(time-10*(floor(time/10))))/10);
    
    return(split(push, digit-1));
}
int get_digits(int num){
    return (internal_get_digits(num, 0));
}
int internal_get_digits(int number, int point){ //function only for internal use
    if(floor(number/10) < 2){
        return point;
    }
    else{
        return(internal_get_digits(floor(number/10), point++));
    }
}
int Randoms(int lower, int upper)
{
   int num = (rand() %(upper - lower + 1)) + lower;
   return(num);

}
  
