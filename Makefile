all: prog
prog: main.o list.o destruct_manager.o
	gcc -oprog main.o list.o destruct_manager.o
main.o: main.c list.h destruct_manager.h base_struct.h
	gcc -g -c main.c
list.o: list.c list.h base_struct.h
	gcc -g -c list.c
destruct_manager.o: destruct_manager.c list.h destruct_manager.h base_struct.h
	gcc -g -c destruct_manager.c
clean:
	rm *.o
	rm prog