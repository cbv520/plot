CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
OBJ = logreader.o string_processing.o
EXEC = logreader

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

logreader.o : logreader.c string_processing.h
	$(CC) $(CLFAGS) -c logreader.c

string_processing.o : string_processing.c string_processing.h
	$(CC) $(CLFAGS) -c string_processing.c

clean :
	rm -f $(EXEC) $(OBJ)