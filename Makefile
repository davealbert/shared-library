all: 		objects 
				gcc -Wall -L./ main.c -lcprocessCommands -o prog

dyno: objects
				gcc -rdynamic -o dyno dyno.c -ldl
				
objects:
				gcc -Wall -fPIC -c processCommands.c helpCommand.c echoServer.c
				gcc -shared -Wl,-soname,libcprocessCommands.so -o libcprocessCommands.so processCommands.o
				gcc -shared -Wl,-soname,libchelpCommand.so -o libchelpCommand.so helpCommand.o
				gcc -shared -Wl,-soname,libcechoServer.so -o libcechoServer.so echoServer.o
				
clean: 
				rm *.o *.so 

cleanbin: clean
				rm dyno prog
				
.PHONY: clean cleanbin
