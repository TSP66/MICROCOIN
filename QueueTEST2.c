#include "STACK_PILE.h"
#include<stdio.h>


int main(){
    struct stack_t *theStack = newStack();
  char *data;
  push(theStack, "foo");
  push(theStack, "bar");
  data = top(theStack);
  printf("%s", data);
  pop(theStack);
  clear(theStack);
  destroyStack(&theStack);
  return 0;
}