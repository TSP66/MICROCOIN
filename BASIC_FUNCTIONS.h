//basic_functions.h
//85 lines

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

#include "hasher.h"

char * output;

int verify(char * message){ // returns number of zeors
 //char * message = stuff;
 //char * str = message;
    int returner =0;
 char * data;
char n0 =  *message;
 char * v= "v";
 if(n0 != *v){

 puts("Wrong command \n");

 }

 else{
    char * d = message+7;
    int difficulty = (int) *d;
    difficulty = difficulty - 48;
    char * ENDCHAR = "|";
   // char * ENDCHAR2 = " ";
    char * zero = "0";
    //clear_data();
     int pd = 0;
     int zero_counter = 0;
     char stringtobehashed[55];
     
    for(int i = 9;i<66;i++){
        
        char l = *(message + i);
        if(l == *ENDCHAR) break;
        stringtobehashed[(i-9)] = l;
        //if(l == *ENDCHAR2) break;
        
         //send character to txt file

    }
     char *pointertobehashed = stringtobehashed;
     puts("Hashing..");
     
    returner = run_get_hash_of(pointertobehashed);
  
    // puts("Done...");
     
     //char *data_string_ah = (char*) malloc(48 * sizeof(char));
     
     /*char data_string_ah[48] = output;
     for(int i = 0;i<20;i++){
        
         char dinfo = *(data_string_ah + i);
         puts("Infomation: ");
         printf("%c", dinfo);
         if(dinfo != *zero){
             returner = i;
             break;
         }
         
     }
    */
     
     
 }
  //  const char * returner = pointertobehashed;
        return returner;
  //puts("verfied");
}

void vote(){
printf("voted");
}

void addTransaction(){

printf("added transation");
}

void getChain(){
 printf("got chain");
}

void newBlock(){
    
}
