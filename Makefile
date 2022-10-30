all: prog
prog: example_main.o list.o destruct_manager.o
	gcc -oprog example_main.o list.o destruct_manager.o
example_main.o: example_main.c include/list.h include/destruct_manager.h include/base_struct.h
	gcc -g -c example_main.c
list.o: list.c include/list.h include/base_struct.h
	gcc -g -c list.c
destruct_manager.o: destruct_manager.c include/list.h include/destruct_manager.h include/base_struct.h
	gcc -g -c destruct_manager.c
clean:
	rm *.o
	rm prog