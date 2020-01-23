CC = gcc -g
AR = ar -rcs
FLAGS = -Wall -fPIC

all: myTree
myTree: myTree.o main.o
	$(CC) $(FLAGS) -o frequency myTree.o main.o
myTree.o: myTree.c
	$(CC) $(FLAGS) -c myTree.c
main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so myTree