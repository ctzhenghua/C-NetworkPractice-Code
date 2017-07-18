CC = g++ -std=c++11 
objects = HeapSort.cc
OutName = HeapSort

$(OutName): $(objects)
	$(CC)  $(objects) -o $(OutName)

clean:
	rm $(OutName) $(objects)
