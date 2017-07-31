CC = g++ -std=c++11 -g
objects = TestVirtual.o
OutName = Test

$(OutName): $(objects)
	$(CC)  $(objects) -o $(OutName)

$(objects): TestVirtual.cc
	$(CC) -c TestVirtual.cc

clean:
	rm $(OutName) $(objects)
