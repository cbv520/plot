CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
OBJ = copy.o
EXEC = copy

EXEC : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

copy.o : copy.c
	$(CC) $(CFLAGS) -c copy.c

clean :
	rm -f $(OBJ) $(EXEC)


