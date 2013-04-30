#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "processCommands.h"

#define PROC_COM "/usr/lib64/libcprocessCommands.so"

int main(int argc, char const *argv[]) {
	 void *lib_handle;
	 char *error;
	 double (*fn)(int *);
	 int x;

	 while(1){
			lib_handle = dlopen(PROC_COM, RTLD_LAZY);
			if (!lib_handle){
				 fprintf(stderr, "%s\n", dlerror());
				 exit(1);
			} else {
				 fn = dlsym(lib_handle, "processCommands");
				 if ((error = dlerror()) != NULL)  
				 {
						fprintf(stderr, "%s\n", error);
						exit(1);
				 }
				 printf("Starting ... ");
				 (*fn)(&x);
				 dlclose(lib_handle);
				 sleep(1);
			}
	 }

	 return 0;

}
