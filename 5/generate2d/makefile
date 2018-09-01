CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
OBJ = generate.o randomarray.o
EXEC = generate

EXEC : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	
generate.o : generate.c randomarray.h
	$(CC) $(CFLAGS) -c generate.c

randomarray.o : randomarray.c randomarray.h
	$(CC) $(CFLAGS) -c randomarray.c

clean :
	rm -f $(OBJ) $(EXEC)


