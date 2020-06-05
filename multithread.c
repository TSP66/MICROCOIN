#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include "hasher.h"
#include "BASIC_FUNCTIONS.h"
  
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    int i =verify("verify-1-helloworld");
    puts("verifying...");
    return NULL;
}
   
int main()
{
    printf("Before Thread\n");
    pthread_t thr[10];
    for(int i = 0; i< 3; i++){
    pthread_create( &thr[i], NULL ,myThreadFun , NULL);
    }
    for(int i = 0; i< 3; i++){
    pthread_join(thr[i], NULL);
    }
    printf("After Thread\n");
    exit(0);
}
