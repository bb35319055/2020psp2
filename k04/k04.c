#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct File_data{
    int gender;
    double heights;
    int ID;
} sample[14];

int main(void)
{
    char fname_1[FILENAME_MAX], fname_2[FILENAME_MAX];
    char buf[256];
    FILE* fp_1;
    FILE* fp_2;
    int gender,ID,Input_ID;
    double heights;
    int i,nodata=0;

    struct File_data;

    printf("input the filename of sample heights: ");
    fgets(fname_1,sizeof(fname_1),stdin);
    fname_1[strlen(fname_1)-1] = '\0';
    printf("input the filename of sample ID: ");
    fgets(fname_2,sizeof(fname_2),stdin);
    fname_2[strlen(fname_2)-1] = '\0';

    fp_1 = fopen(fname_1,"r");
    if(fp_1==NULL){
        fputs("File open error\n", stderr);
        exit(EXIT_FAILURE);
    }

    fp_2 = fopen(fname_2,"r");
    if(fp_2==NULL){
        fputs("File open error\n", stderr);
        exit(EXIT_FAILURE);
    }

    i = 0;

    while(fgets(buf,sizeof(buf),fp_1) != NULL){
        sscanf(buf,"%d,%lf",&gender,&heights);
        sample[i].gender = gender;
        sample[i].heights = heights;
        i++;
    }

    if(fclose(fp_1) == EOF){
        fputs("file close error\n", stderr);
        exit(EXIT_FAILURE);
    }

    i = 0;

    while(fgets(buf,sizeof(buf),fp_2) !=NULL){
        sscanf(buf,"%d",&ID);
        sample[i+1].ID = ID;
        i++;
    }

    if(fclose(fp_2) == EOF){
        fputs("file close error\n", stderr);
        exit(EXIT_FAILURE);
    }

    printf("Which ID's data do you want?: ");
    scanf("%d", &Input_ID);

    for(i = 1;i < 15;i++){
        if(sample[i].ID == Input_ID){
            printf("ID :%d\n",sample[i].ID);

            if(sample[i].gender == 1){
                printf("gender :Male\n");
            }
            else{
                printf("gender :Female\n");
            }
            
            printf("heights :%.2lf\n", sample[i].heights);
        }
        else{
            nodata++;
        }
    }

    if(nodata == 14){
        printf("-------\n");
        printf("NO data\n");
        printf("-------\n");
    }

    return 0;

}
