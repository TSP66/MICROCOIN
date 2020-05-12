//
//  rsa.h
//  Cipher
//
//  Created by Tom Petty on 8/3/20.
//  Copyright © 2020 Tom Petty. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "primes.h"
#include <time.h>
#include <math.h>

long R;
long D;

long prime1;
long prime2;

#define INT "%d"
#define LONG "%ld"


#ifndef rsa_h
#define rsa_h

const int prime_set_size = 27;
const int r_prime_set_size = prime_set_size*prime_set_size;
int primeset[prime_set_size];
int r_primeset[r_prime_set_size];


int Rd = 0;

char c[11] = "hello_world";



long P;
long Q;

int random_number(int min_num, int max_num);

int random_number(int min_num, int max_num)
{
    int result = 0;

    long gen = time(NULL);

    srand((unsigned int) gen + Rd);
    srand((unsigned int) gen + Rd);
    
    Rd++;
    
    result = (rand() % (max_num - min_num)) + min_num;
    return(result);
}

void find_PQ(long phi){
    int p_n = random_number(0, PRIMES);
    P = primes[p_n];
    //int K;
    int d = 0;
    //for
    long ppp = P;
    for (int v1 = 1; v1 < (phi*P); v1++){
        for (int K = 1; K < (phi*P); K++){
            if(ppp * v1 == K*phi){
                printf("Q is: ");
                printf("%d", v1);
                printf(" ");
                printf("P is: ");
                printf("%ld", P);
                
                
                
                Q = v1;
                d = 1;
                
                break;
            }
            
        }
        if (d==1){
            break;
        }
    }
    
  
}

long d(long public_key, long phi){
    long D = 0;
    for(long d = 1; d < 32000; d++){
    if(((public_key * d) % phi) == 1){
        D = d;
        break;
    }
    }
    return(D);
}

void setup_primes(){
    generate_primes();
    for(int i = 0; i < 27; i++){
        primeset[i] = primes[i];
    }
}

void setup_reverse_primes(){
    r_primeset[0] = 0;
    r_primeset[1] = 0;
    r_primeset[2] = 1;
    int counter = 1;
    for(int i = 1; i < r_prime_set_size; i++){
        if(checkprime(i)){
            r_primeset[i] = counter;
            counter++;
        }
    }
    r_primeset[1] = 0;
}

//865-475
int convert(char i){
    int b = i - 'a'-1; //0
    int r = primeset[b];
    return(r);// 2

}
char reverse(int i){
    int b = r_primeset[i];
    return((char) b+'a');
}


long long POWER(long i, long i2){
    long result = i;
    for(long d = 0; d < (i2-1); d++){
        result = result * i;
    }
    return(result);
}

void test_converter(){
    setup_primes();
    setup_reverse_primes();
    char tester[] = "abc";
    int m = convert(tester[0]);
    printf("%c", reverse(m));
    printf(" ");
}

void ENCRYPT(char c[] , long lenght_of_c, long R){
    setup_primes();
    setup_reverse_primes();
    long len_i = lenght_of_c;
    //int converted_message[10];
    unsigned long long converted_message[len_i];
    unsigned long long final_message[len_i];
    for(int i = 0; i < len_i; i++){
        converted_message[i] = (int) convert(c[i]);
    }
    printf(" ");
    for(int i = 0; i < len_i; i++){
        final_message[i] = ((POWER(converted_message[i], P)) % R) % prime_set_size;
        char ch = (char) reverse((int) final_message[i]);
        printf("%c", ch);
    }
}


void init(){
    generate_primes();
    int V1 = random_number(0, PRIMES);
    int V2 = random_number(0, PRIMES);
    long U = primes[V1];
    long V = primes[V2];
    prime1 = U;
    prime2 = V;
    printf("%ld", U);
    printf(" ");
    printf("%ld", V);
    printf(" ");
    R = U*V;
    long phi = (U-1)*(V-1);
   // double PQ = phi + 1;
    find_PQ(phi);
    //find_PQ(phi);
    printf(" D is: ");
    D = d(P, phi);
    printf("%ld", D);
    printf(" ");
    
    //char message[] = {"h"};
    
    //ENCRYPT(message, 5, R);
    
    
    
    //double info = (int) (pow( (int) message,(int) P) % R);
    
   // printf("%f", info);
    
    
    
    

}




#endif /* rsa_h */
