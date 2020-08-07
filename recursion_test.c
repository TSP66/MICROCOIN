#include <math.h>
#include <stdio.h> 
#include <time.h> 

int split(int time, int digit){
    if(digit == 1){
      return(time-10*(floor(time/10)));
    }
    int result = floor(time/(pow(10, digit)));
    return(split((time-(time-10*(floor(time/10))))/10, digit-1));
}
int main(){
printf("%d", split(12345678, 4));
return 0;
}