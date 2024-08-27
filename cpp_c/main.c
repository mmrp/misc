#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

#define cpplib "libtest.so"

int main(void)
{
    void * dlh = dlopen(cpplib, RTLD_NOW);
    if (!dlh) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    char * (*cpp_test)(char *) = dlsym(dlh,"cpp_test");
    if (!cpp_test) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    char *p = cpp_test("1");
    if (p != NULL) {
      printf("%s\n", p);
    }
    return 0;
}
