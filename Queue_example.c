/*
 * File   : main.c
 * Author : zentut.com
 * Purpose: queue program
 */
#include <stdio.h>
#include <stdlib.h>
 
#include "ARRAYQueue.h"
 #define MAX 5
 char array[MAX][20];

int spot = 0;
int main()

{   

    while(spot < MAX){
    printf("Enter a String:");
    scanf("%s", array[spot]);
    spot++;
    
    }
    while(spot >= 0){
    printf("%s", array[spot]);
    puts("");
    spot--;
    
    }
    
}
