#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

#define MAX_STRING_LEN 80

#include "helpCommand.h"
#define HELP_LIB "/usr/lib64/libchelpCommand.so"

#include "echoServer.h"
#define ECHO_SERVER_LIB "/usr/lib64/libcechoServer.so"

void runCommand(char *lib, char *cmd);
// This is the public function
void processCommands() {
	 char commandInput[MAX_STRING_LEN];
	 char *prompt = "dyno";
	 printf("Loaded ... \n");
	 while(strcmp(commandInput,"reset")!=0){
			printf("%s> ",prompt);
			fgets(commandInput,MAX_STRING_LEN,stdin);
			commandInput[strlen(commandInput)-1] = 0;
			if(strcmp(commandInput,"exit")==0) { 
				 printf("\nExiting system\n\n");
				 exit(0); 
			}
			else if(strcmp(commandInput,"")==0) { /* Do nothing blank line */ }
			else if(strcmp(commandInput,"help")==0) { runCommand(HELP_LIB, "showHelp"); }
			else if(strcmp(commandInput,"echo")==0) { runCommand(ECHO_SERVER_LIB, "echoServer"); }
			else if(strcmp(commandInput,"reset")==0) { printf("Restarting ... "); }
			else if(strcmp(commandInput,"vim")==0) { system("vim");  }
					
			else { printf("Invalid command : '%s'.\n",commandInput);}
	 }
}

void runCommand(char *lib, char *cmd) {
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



