#include <stdio.h>
//#include <stlib.h>
#include <string.h>

#define MAXCHAR 1000

const int number_of_addresses = 1000;

struct CONNECTION{
    char * address;
    int port;
};

struct CONNECTION address[number_of_addresses];

int get_address(){
    /*char str[100];
    char emt[100];
    FILE * ipaddresses = fopen("ip_addresses.txt", "r");
    int i = 0;
    while(fgets(str, sizeof(str), ipaddresses)){
        
       // puts(str);
        address[i].address = str;
        //printf("Address: ");
        //puts(address[i].address);
        i++;
    }
    //printf("%d",i);
    return (i-1);
     */
    address[0].address = "112.213.34.190";
    
    return 0;
}
