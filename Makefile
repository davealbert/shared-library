all: 		objects 
				gcc -Wall -L./ main.c -lcprocessCommands -o prog

dyno: objects
				gcc -rdynamic -o dyno dyno.c -ldl
				
objects:
				gcc -Wall -fPIC -c processCommands.c helpCommand.c
				gcc -shared -Wl,-soname,libcprocessCommands.so -o libcprocessCommands.so *.o
				gcc -shared -Wl,-soname,libchelpCommand.so -o libchelpCommand.so *.o
				
clean: 
				rm *.o *.so 

cleanbin: clean
				rm dyno prog
				
.PHONY: clean cleanbin
