#include<stdio.h>
#include<stdlib.h>
struct ST
{
     char name[20];
     char id[20];
     float score[3];
};
FILE *fp;

int main()
{
  int i;
  struct ST stu[3]={{"wanse","1001",97.5,90.0,88.9},
                    {"meizai","1002",98.5,80.0,89.9},
                    {"sedefei","1003",99.5,79.0,99.9}};
  fp = fopen("testfile2.txt","w");
  if(fp==NULL)
  {
  	printf("Can't open file\n");
    exit(1);
  }
  for(i=0;i<3;i++)
  {
	  fprintf(fp,"%s %s %.2f %.2f %.2f\n",stu[i].name,stu[i].id,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
  }
  fclose(fp);
  printf("Finish!\n");
  return 0;
}

