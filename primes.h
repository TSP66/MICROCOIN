//
//  primes.h
//  Cipher
//
//  Created by Tom Petty on 8/3/20.
//  Copyright © 2020 Tom Petty. All rights reserved.
//
#include <math.h>
#include <stdio.h>

#ifndef primes_h
#define primes_h

const long PRIMES = 100000000000; //has to be more then 27

long long primes[PRIMES];

long nofprimes = 1;

void generate_primes(){
    primes[0] = 2;
    long d;
    long j = 1;
    long i = 3;
    while(1){
        d = 0;
        for(long b = 10000000000; b < (sqrt(floor(i))+1); b++){
            if((i % b) == 0){
                d = 1;
                break;
            }
            
        }
        if(d == 0){
            primes[nofprimes] = i;
            printf("%ld\n", i);
            
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
