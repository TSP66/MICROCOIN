#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double minimum ;
    double maximum ;
    double average ;
    int daynumber ;
}Measurement;

#define QUANT 31

void measure(Measurement *);
void output(FILE *, Measurement *);

int main(int argc, char** argv) {

    Measurement m[QUANT];
    int i;
    FILE *f;

    printf("Input data:\n");
    for(i=0; i<1; i++)
        measure(&m[i]);

    printf("\nData was saved into xml file\n");
    f = fopen("data.xml","w");
    if(f==NULL){
        printf("Error");
        return 0;
    }
    fprintf (f,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    for(i=0;i<1;i++){
        output(f,m);
    }
    fclose(f);

    return (EXIT_SUCCESS);
}

void measure(Measurement *x){
    printf("Input minimum temperature: ");
    scanf("%lf",&x->minimum);
    printf("Input maximum temperature: ");
    scanf("%lf",&x->maximum);
    printf("Input average temperature: ");
    scanf("%lf",&x->average);
    printf("Input day number: ");
    scanf("%d",&x->daynumber);
}
void output(FILE *f, Measurement *x){
    fprintf(f,"<day>\n");
    fprintf(f,"<minimum>%f</minimum>\n",x->minimum);
    fprintf(f,"<maximum>%f</maximum>\n",x->maximum);
    fprintf(f,"<average>%f</average>\n",x->average);
    fprintf(f,"<daynumber>%d</daynumber>\n",x->daynumber);
    fprintf(f,"</day>\n");
}