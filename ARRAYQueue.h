

void add(char r[5][10], int spot, char * value){
     *(r[spot]) = *value;
}
char* pop(char r[5][10], int spot){
    return (r[spot]);
}