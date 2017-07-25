CC = g++ -std=c++11
objects = HeapSort.o
OutName = HeapSort

$(OutName): $(objects)
	$(CC)  $(objects) -o $(OutName)

$(objects): HeapSort.cc
	$(CC) -c HeapSort.cc

clean:
	rm $(OutName) $(objects)
