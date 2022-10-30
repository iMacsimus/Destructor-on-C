all: prog
prog: main.o list.o destruct_manager.o
	gcc -oprog main.o list.o destruct_manager.o
main.o: main.c include/list.h include/destruct_manager.h include/base_struct.h
	gcc -g -c main.c
list.o: list.c include/list.h include/base_struct.h
	gcc -g -c list.c
destruct_manager.o: destruct_manager.c include/list.h include/destruct_manager.h include/base_struct.h
	gcc -g -c destruct_manager.c
clean:
	rm *.o
	rm prog