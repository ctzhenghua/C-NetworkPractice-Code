CC = g++ -std=c++11 
objects = ThreadTest.o Main.o
OutName = ThreadTest

$(OutName): $(objects)
	$(CC) -pthread $(objects) -o $(OutName)

Main.o :Main.cc ThreadTest.h
	$(CC) -c Main.cc

ThreadTest.o: ThreadTest.cc ThreadTest.h
	$(CC) -c ThreadTest.cc

clean:
	rm $(OutName) $(objects)
