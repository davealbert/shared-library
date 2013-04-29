#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#define MAX_STRING_LEN 80

#include "helpCommand.h"
#define HELP_LIB "/usr/lib64/libchelpCommand.so"

void runCommand(char *lib, char *cmd){
	 void *lib_handle;
	 char *error;
	 double (*fn)(int *);
	 int x;

	 lib_handle = dlopen(lib, RTLD_LAZY);
	 if (!lib_handle){
			fprintf(stderr, "%s\n", dlerror());
	 } else {
			fn = dlsym(lib_handle, cmd);
			if ((error = dlerror()) != NULL)
			{
				 fprintf(stderr, "%s\n", error);
			}
			(*fn)(&x);
			dlclose(lib_handle);
	 }
}


// This is the public function
void processCommands() {
	 char commandInput[MAX_STRING_LEN];
	 char *prompt = "dyno";
	 printf("\nLoaded ...\n");
	 while(strcmp(commandInput,"reset")!=0){
			printf("%s> ",prompt);
			scanf("%s",commandInput);
			if(strcmp(commandInput,"exit")==0) { 
				 printf("\nExiting system\n\n");
				 exit(0); 
			}

			if(strcmp(commandInput,"help")==0) { runCommand(HELP_LIB, "showHelp"); }

	 }
}


