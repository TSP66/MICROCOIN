#include <math.h>
#include <stdlib.h>
#include "sockets.h"

struct connection conts;

char first_part[10] = "10.1.1.";


void scanports(){
 for(int i = 1; i < 255; i++){
   char first = (char) floor(i/100)+ 48;
  
   char second = (char) floor((i-((first-48)*100))/10) + 48;

   char third = (char) i - (first-48)*100 - (second-48)*10 + 48;

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
      pos++;
   
  char * ip = first_part;
  puts(ip);

 }
}