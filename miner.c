   
#include <stdio.h> 
#include <time.h> 
#include "coin.h"
#include <math.h>

char block[LENGTH]

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
        




    return(0); 
}