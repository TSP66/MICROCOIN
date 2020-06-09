
//basic_functions.h

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>



char * output;

int verify(char * message, struct connection C){ // returns number of zeors
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
    clear_data();
     int pd = 0;
     int zero_counter = 0;
    for(int i = 9;i<66;i++){
        
        char l = *(message + i);
        if(l == *ENDCHAR) break;
        //if(l == *ENDCHAR2) break;
        
        send_data(l); //send character to txt file

    }
     
     returner = run_get_hash_of(output, C);
     puts(output);
     
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
        printf("%d", returner);
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
