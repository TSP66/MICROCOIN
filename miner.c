//miner.c
#include <stdio.h> 
#include <time.h> 
#include "coin.h"
#include <math.h>

char block[LENGTH]

char *senders_address = "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8";

char *recivers_address = "d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3";

char *miners_address = "86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47;

int main () 
{ 
    time_t seconds; 
      
    seconds = time(NULL); 
    
    if(floor(coin_difficulty/10) != 0){
    block[0] = floor(coin_difficulty/10) + "0";
    block[1] = coin_difficulty - 10*(floor(coin_difficulty/10)) + "0";

    }
    else{
    block[0] = "0";
    block[1] = coin_difficulty + "0";
    }
    
    block[2] = SEPERATOR;
    
    if(floor(coin_number_award/100) != 0){
    block[3] = floor(coin_number_award/100) + "0";
    block[4] = floor((coin_number_award - 100*(floor(coin_number_award/100)))/10) + "0";
    block[5] = coin_number_award - block[3]*100 - block[4]*10 + "0";

    }
    
    else if(floor(coin_number_award/10) != 0){
    block[3] = "0";
    block[4] = floor(coin_number_award/10) + "0";
    block[5] = coin_number_award - 10*(floor(coin_number_award/10)) + "0";

    }
    else{
    block[3] = "0";
    block[4] = "0";
    block[5] = coin_number_award + "0";
    }
    
    block[6] = SEPERATOR;
    
    if(floor(coin_number_block/100) != 0){
    block[7] = floor(coin_number_block/100) + "0";
    block[8] = floor((coin_number_block - 100*(floor(coin_number_block/100)))/10) + "0";
    block[9] = coin_number_block - block[6]*100 - block[7]*10 + "0";

    }
    
    else if(floor(coin_number_block/10) != 0){
    block[7] = "0";
    block[8] = floor(coin_number_block/10) + "0";
    block[9] = coin_number_block - 10*(floor(coin_number_block/10)) + "0";

    }
    else{
    block[7] = "0";
    block[8] = "0";
    block[9] = coin_number_block + "0";
    }
    
    block[10] = SEPERATOR;
    
    for(int i = 0; i < 32; i++){
        
    }
        




    return(0); 
}
