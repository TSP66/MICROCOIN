//from decimal import Decimal
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int gcd2(int a,int b);

int gcd(int a,int b){
    if (b==0){
       return a;
    }
    else{
        return gcd2(b,a%b);
    }
}
int gcd2(int a,int b){
    if (b==0){
       return a;
    }
    else{
        return gcd(b,a%b);
    }
}


void getRSA(){
    unsigned long no, p, q, d;
    no = 9;
    p = 256203221;
    q = 275604541;
    unsigned long t;
    
    unsigned long n = p*q;
    t = (p-1)*(q-1);
    unsigned long e = 2;


    for(e = 2; e < t; e++){
    if (gcd(e,t)== 1){
        break;
    }
    }

    for(int i; i < 10; i++){
        int x = 1 + i*t;
        if (x % e == 0){
            d = (int) x/e;
            break;
        }
    }
    
    
   
    double ctt = pow(no,e);
    double ct = ((int) ctt) % n;

   
    double dtt = pow(ct,d);
    double dt = ((int) dtt) % n;
    puts("N: ");
    printf("%lu\n", n);
    puts("E: ");
    printf("%lu\n", e);
    puts("T: ");
    printf("%lu\n", t);
    puts("D: ");
    printf("%lu\n", d);
    puts("Cipher: ");
    printf("%f\n", ct);
    puts("Decrpyted: ");
    printf("%f\n", dt);
    

//print('n = '+str(n)+' e = '+str(e)+' t = '+str(t)+' d = '+str(d)+' cipher text = '+str(ct)+' decrypted text = '+str(dt))


}

int main(){
        
        getRSA();
        return 0;
}
