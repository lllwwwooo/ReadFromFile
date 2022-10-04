#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <malloc.h>
struct ST
{
    char name[10];
    char id[10];
    float score[3];
};
struct ST* readtxtfile(char txtname[])
{
    int i,len;
    struct ST *stu;
    FILE* fp=fopen(txtname,"r");
    if(fp==NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }
    printf("请输入数组的元素个数：\n");
    scanf("%d", &len);
    stu = (struct ST *)malloc(len*sizeof(struct ST));
    for(i=0; i<len; i++)
    {
        fscanf(fp,"%s%s%f%f%f",stu[i].name,stu[i].id,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        printf("%s, %s, %.2f, %.2f, %.2f\n",stu[i].name,stu[i].id,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
    fclose(fp);
    printf("Finish!\n");
    return stu;
}
struct ST* readbinfile(char binname[])
{
    int i,len;
    struct ST *stu;
    FILE* fp=fopen(binname,"rb");
    if(fp==NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }
    printf("请输入数组的元素个数：\n");
    scanf("%d", &len);
    stu = (struct ST *)malloc(len*sizeof(struct ST));
    for(i=0; i<len; i++)
    {
        fread(&stu[i],sizeof(struct ST),1,fp);
        printf("%s, %s, %.2f, %.2f, %.2f\n",stu[i].name,stu[i].id,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
    fclose(fp);
    printf("Finish!\n");
    return stu;
}
void writetxtfile(char txtfile[],struct ST *stu)
{
    int i;
    FILE* fp=fopen(txtfile,"a+");
    if(fp==NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }
    for(i=0; i<3; i++)
    {
        fprintf(fp,"%s %s %.2f %.2f %.2f\n",stu[i].name,stu[i].id,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
    fclose(fp);
    printf("Finish!\n");
}
void writebinfile(char binfile[],struct ST *stu)
{
    int i;
    FILE* fp=fopen(binfile,"ab+");
    if(fp==NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }
    for(i=0; i<3; i++)
    {
        fwrite(&stu[i], sizeof(struct ST),1, fp);
    }
    fclose(fp);
    printf("Finish!\n");
}
