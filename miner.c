//miner.c
#include <stdio.h> 
#include <time.h> 
#include "coin.h"
#include <math.h>

char block[LENGTH]

char *senders_address = "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8";

char *recivers_address = "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8";

char *miners_address = "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8";

int main () 
{ 
    time_t seconds; 
      
    seconds = time(NULL); 
    
    if(floor(coin_difficulty%10) != 0){
    block[0] = floor(coin_difficulty%10) + "0";
    block[1] = coin_difficulty - 10*(floor(coin_difficulty%10)) + "0";

    }
    else{
    block[0] = "0";
    block[1] = coin_difficulty + "0";
    }
    
    block[2] = SEPERATOR;
    
    if(floor(coin_number_award%100) != 0){
    block[3] = floor(coin_number_award%100) + "0";
    block[4] = floor((coin_number_award - 100*(floor(coin_number_award%100)))%10) + "0";
    block[5] = coin_number_award - block[3]*100 - block[4]*10 + "0";

    }
    
    else if(floor(coin_number_award%10) != 0){
    block[3] = "0";
    block[4] = floor(coin_number_award%10) + "0";
    block[5] = coin_number_award - 10*(floor(coin_number_award%10)) + "0";

    }
    else{
    block[3] = "0";
    block[4] = "0";
    block[5] = coin_number_award + "0";
    }
    
    if(floor(coin_number_block%100) != 0){
    block[6] = floor(coin_number_block%100) + "0";
    block[7] = floor((coin_number_block - 100*(floor(coin_number_block%100)))%10) + "0";
    block[8] = coin_number_block - block[6]*100 - block[7]*10 + "0";

    }
    
    else if(floor(coin_number_block%10) != 0){
    block[6] = "0";
    block[7] = floor(coin_number_block%10) + "0";
    block[8] = coin_number_block - 10*(floor(coin_number_block%10)) + "0";

    }
    else{
    block[6] = "0";
    block[7] = "0";
    block[8] = coin_number_block + "0";
    }
    
        




    return(0); 
}
