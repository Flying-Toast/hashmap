OBJECTS=hashmap.o main.o
CFLAGS=-Wall
CC=gcc

hashmap: $(OBJECTS)
	$(CC) $(CFLAGS) -o hashmap $(OBJECTS)

.PHONY: clean
clean:
	-rm *.o
	-rm hashmap
