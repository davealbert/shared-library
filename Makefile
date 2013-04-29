all: 		objects 
				gcc -Wall -L./ main.c -lcprocessCommands -o prog

dyno: objects
				gcc -rdynamic -o dyno dyno.c -ldl
				
objects:
				gcc -Wall -fPIC -c processCommands.c
				gcc -shared -Wl,-soname,libcprocessCommands.so -o libcprocessCommands.so *.o
				
clean: 
				rm *.o *.so 

cleanbin: clean
				rm dyno prog
				
.PHONY: clean cleanbin
