#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 80


void processCommands() {
	 char commandInput[MAX_STRING_LEN];
	 char *prompt = "";
	 printf("\nLoaded ...\n");
	 while(strcmp(commandInput,"reset")!=0){
		 printf("%s> ",prompt);
		 scanf("%s",commandInput);
	}
}
