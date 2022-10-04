#include<stdio.h>
#include<stdlib.h>
FILE *fp;

int main()
{
  int i;
  float a[3];
  char b[3];
  fp = fopen("binfile3.dat","rb");

  if(fp==NULL)
  {
  	printf("Can't open file\n");
    exit(1);
  }
  for(i=0; i<3; i++)
  {
	if(fread(&a[i],sizeof(float),1,fp) == 1)
		printf("%f\n",a[i]);
	else
	    printf("Fail to read");
  }
  for(i=0; i<3; i++)
  {
	if(fread(&b[i],sizeof(char),1,fp) == 1)
		printf("%c\n",b[i]);
	else
	    printf("Fail to read");
  }
  fclose(fp);
  printf("Finish!\n");
  return 0;
}
