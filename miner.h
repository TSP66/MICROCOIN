#include "hasher.h"
#include "BASIC_FUNCTIONS.h"

char *data;
char *hash;

void mine(){
   get_hash_of(data, hash);
}
