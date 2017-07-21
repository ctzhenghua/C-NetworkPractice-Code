CC = g++ -std=c++11 
objects = LinkedList.o Main.o
OutName = LinkedList

$(OutName): $(objects)
	$(CC)  $(objects) -o $(OutName)

Main.o :Main.cc LinkedList.h
	$(CC) -c Main.cc
LinkedList.o: LinkedList.cc LinkedList.h
	$(CC) -c LinkedList.cc

clean:
	rm $(OutName) $(objects)
