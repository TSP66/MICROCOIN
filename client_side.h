//client_side.h
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "sockets.h"
#include <string.h>

struct connection conts;

const char*generateip(int i){
   //printf("%d", i);
   // char ** var;
   char first_part[11] = "10.1.1.";

   char first = (char) floor(i/100)+ 48;
   //printf("%c", first);
   char second = (char) floor((i-((first-48)*100))/10) + 48;
   //printf("%c", second);
   char third = (char) i - (first-48)*100 - (second-48)*10 + 48;
   //printf("%c", third);
   int pos = 7;
   char * zero = "0";
   if(first != *zero) {
      first_part[pos] = first;
      pos++;
   }
   if((second != *zero)||(pos != 7)){
      first_part[pos] = second;
      pos++;
   }
   
   first_part[pos] = third;


  
   char  *dita = first_part;
    char * var = (char *) malloc(11);;
    sprintf(var, "%s", dita);
    
  //  return (const char *) d
    
    return var;
   //d =  ip;
}

void scanports(){
 for(int i = 1; i < 255; i++){
  
   
   //  char * ipa = (char *) generateip(i);
  
  //conts.ip = ipa;
   //  char *d;
     char *d;
    d = (char *) generateip(i);
     puts(d);

 }
}

