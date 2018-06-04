CC=g++
CFLAGS=-I.
DEPS = Node.h BinaryTree.h
OBJ = main.o Node.o BinaryTree.o 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 
	
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
