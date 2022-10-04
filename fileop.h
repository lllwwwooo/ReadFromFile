#ifndef FILEOP_H__
#define FILEOP_H__
struct ST
{
    char name[10];
    char id[10];
    float score[3];
};
struct ST* readtxtfile(char txtname[]);
struct ST* readbinfile(char binname[]);
void writetxtfile(char txtfile[],struct ST *stu);
void writebinfile(char binfile[],struct ST *stu);


#endif
