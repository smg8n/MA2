CC = gcc
CFLAGS = -w
TARGET = oss
OBJ = main.o 
OBJ = prime.o 
SRC = main.c 
SRC1 = prime.c
all: $(TARGET) 
$(TARGET):$(OBJ)
	$(CC) -o $(TARGET) $(OBJ)
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
$(OBJ1): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC1)
clean:
	/bin/rm -f *.o $(TARGET)
