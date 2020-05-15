#include <stdio.h>
#include <string.h>

int main()
{
	unsigned int a = 89;
	int b;
        char p[4];

        
        FILE * file = fopen("hel21o.txt", "a+");

        fwrite(&a, strlen(p), 1, file);

	
	fscanf(file, "%x",&a);
	
	printf("Value of a: Hex: %X, Decimal: %d\n",a,a);

         for(int ctr = 0; ctr < 100; ctr++) fwrite(&ctr, strlen(p), 1, file);

        fclose(file);

	
	return 0;
}
