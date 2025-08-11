CC = gcc
CFLAGS = -Wall

TARGET = test

$(TARGET): test.o
	$(CC) $(CFLAGS) -o $(TARGET) test.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -f $(TARGET) test.o