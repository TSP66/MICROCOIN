#include <stdio.h>
#include <stdlib.h>

int main (){
   for(int i = 0; i < 6; i++) {
   system("python3 test_readpython.py");
   FILE * file = fopen("test.txt", "r");
   int number = (int) fgetc(file) - 48;
   number = number+100;
printf("%d", number);
puts(" ");
   fclose(file);
   file = fopen("test.txt", "w");
   fprintf(file, "%d", number);
   fclose(file);
   }
}