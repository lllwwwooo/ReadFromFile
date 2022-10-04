#include<stdio.h>
#include<stdlib.h>
FILE *fp;

int main()
{
  int i;
  float a[3]={3.14,4.56,0.68};
  char b[3]={'a','b','c'};
  fp = fopen("binfile3.dat","wb");
  if(fp==NULL)
  {
  	printf("Can't open file\n");
    exit(1);
  }
  for(i=0;i<3;i++)
  {
	  fwrite(&a[i], sizeof(float), 1, fp);
  }

  for(i=0; i<3; i++)
  {
	 fwrite(&b[i], sizeof(char), 1, fp);
  }
  fclose(fp);
  printf("Finish!\n");
  return 0;
}

