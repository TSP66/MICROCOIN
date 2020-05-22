#include <stdio.h>
#include "sockets.h"
#include "ip_address.h"

int main(){
    int f = 0;
    puts("Getting addresses");
    int he = get_address();
    puts("Done... Connecting");
    for(int d = 0; d < 1; d++){

        ip = address[d].address;
        puts("gotten address: ");
        puts(ip);
       // for(int c; c<100; c++){
            if(setup_as_client(8000) != -1) {
                f = 1;
                break;
            }
        //}
        if(f == 1) break;
    }
while(&free){
   READ();
    
}
return 0;
}

