CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
OBJ = plot.o display.o
EXEC = display

EXEC : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

display.o : display.c plot.h
	$(CC) $(CFLAGS) -c display.c
	
plot.o : plot.h
	$(CC) $(CFLAGS) -c plot.c

clean :
	rm -f $(OBJ) $(EXEC)


