#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double square_ave);
int N;

int main(void)
{
    double val,ave=0,var=0,square_ave=0,u;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    N=0;

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        N++;
        var = var_online(val,ave,square_ave);
        ave = ave_online(val,ave);
        square_ave = ave_online(pow(val,2),square_ave);
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    u = N*var/(N-1);

    printf("sample mean:%lf\n", ave);
    printf("sample variance:%lf\n", var);
    printf("population mean:%lf\n", ave);
    printf("poplation variance:%lf\n", u);

    return 0;


}

double ave_online(double val,double ave)
{
    double ave1;

    ave1 = ((N-1)*ave + val) / N;

    return ave1;
}

double var_online(double val,double ave,double square_ave)
{
    double var;

    var = ((N-1)*square_ave/N + pow(val,2) / N) - pow(ave_online(val,ave),2);

    return(var);
}
