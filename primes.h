//
//  primes.h
//  Cipher
//
//  Created by Tom Petty on 8/3/20.
//  Copyright © 2020 Tom Petty. All rights reserved.
//
#include <math.h>


#ifndef primes_h
#define primes_h

const int PRIMES = 28; //has to be more then 27

int primes[PRIMES];

long nofprimes = 1;

void generate_primes(){
    primes[0] = 2;
    int d;
    int j = 1;
    int i = 3;
    while(1){
        d = 0;
        for(int b = 2; b < (sqrt(floor(i))+1); b++){
            if((i % b) == 0){
                d = 1;
                break;
            }
            
        }
        if(d == 0){
            primes[nofprimes] = i;
            nofprimes++;
            j++;
            if(j == PRIMES){
                break;
            }
           
        }
         i++;
    }
    
}

int checkprime(long prime){
    int d = 1;
    for(int b = 2; b < (sqrt(floor(prime))+1); b++){
        if((prime % b) == 0){
            d = 0;
            break;
            
        }
        
    }
    return(d);
}



#endif /* primes_h */
