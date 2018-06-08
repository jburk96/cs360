CC=g++
CXXFLAGS= -std=c++0x -I.
DEPS = Node.h BinaryTree.h
OBJ = main.o Node.o BinaryTree.o 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 
	
bst: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o bst
