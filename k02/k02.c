#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>


extern double p_stdnorm(double z);

int main(void)
{
    double ave_A=170.8,var_A=pow(5.43,2),ave_B=169.7,var_B=pow(5.5,2);
    double val,y_A,y_B,f_A,f_B;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        y_A = (val - ave_A)/sqrt(var_A);
        y_B = (val - ave_B)/sqrt(var_B);
        f_A = p_stdnorm(y_A);
        f_B = p_stdnorm(y_B);
        L1 = L1 * f_A;
        L2 = L2 * f_B;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L1);
    printf("L_B: %f\n",L2);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

