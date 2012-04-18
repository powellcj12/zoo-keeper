CC = g++
CFLAGS = -c -Wall -Wextra
all: zoo

zoo: zoo.o animals.o cluster.o
	$(CC) zoo.o animals.o cluster.o -o zoo

zoo.o: zoo.cpp
	$(CC) $(CFLAGS) zoo.cpp

animals.o: animals.cpp
	$(CC) $(CFLAGS) animals.cpp

cluster.o: cluster.cpp
	$(CC) $(CFLAGS) cluster.cpp

clean:
	rm -rf *o zoo
