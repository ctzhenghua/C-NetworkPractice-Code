CC = g++ -std=c++11 
objects = BinaryTree.o Main.o
OutName = Binary

$(OutName): $(objects)
	$(CC)  $(objects) -o $(OutName)

Main.o :Main.cc BinaryTree.h
	$(CC) -c Main.cc
BinaryTree.o: BinaryTree.cc BinaryTree.h
	$(CC) -c BinaryTree.cc

clean:
	rm $(OutName) $(objects)
