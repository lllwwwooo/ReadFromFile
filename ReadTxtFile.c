#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct ST
{
    char name[10];
    char id[10];
    float score[3];
};
FILE *fp;
int main()
{
    int i;
    struct ST stu[3];
    fp = fopen("testfile.txt","r+");
    if(fp==NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }
    for(i=0; i<3; i++)
    {
        fscanf(fp,"%s%s%f%f%f",stu[i].name,stu[i].id,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        printf("%s, %s, %.2f, %.2f, %.2f\n",stu[i].name,stu[i].id,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
    fclose(fp);
    printf("Finish!\n");
    return 0;
}
