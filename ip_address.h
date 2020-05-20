#include <stdio.h>

#define MAXCHAR 1000

const int number_of_addresses = 1000;

struct CONNECTION{
    char * address;
    int port;
};

struct CONNECTION address[number_of_addresses];

int get_address(){
    char str[MAXCHAR];
    FILE * ipaddresses = fopen("ip_addresses.txt", "r");
    int i = 0;
    while(fgets(str, MAXCHAR, ipaddresses) != NULL){
        address[i].address = str;
        //printf("Address: ");
        //puts(str);
        i++;
    }
    return 0;
}
