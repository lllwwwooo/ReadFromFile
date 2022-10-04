#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
struct ST
{
    char name[10];
    char id[10];
    float score[3];
};
int main(int args,char *argv[])
{
void *handle;
struct ST* (*readtxtfile)(char txtfile[]);
char *error;
handle = dlopen("./libfileop.so", RTLD_LAZY);
if (!handle) {
   fprintf(stderr, "%s\n", dlerror());
   exit(1);
}
readtxtfile = dlsym(handle, "readtxtfile");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }
     struct ST *stu=readtxtfile("testfile.txt");
      if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    return 0;
}




