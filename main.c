#include<stdio.h>                                                                                            
#include <stdlib.h>
#include"fileop.h"
int main(int args,char *argv[])
{
    struct ST *stu1,*stu2;
    stu1=readbinfile(argv[1]);
    writetxtfile(argv[2],stu1);
    stu2=readtxtfile(argv[3]);
    writebinfile(argv[4],stu2);
    return 0;
}
