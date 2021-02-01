#options de compilation
CC = gcc
CCFLAGS = -Wall -g 

#Fichiers du projet
SRC = bmp.c bmp.c main.c
OBJ = $(SRC: .c=.o)
EXEC = AsciiArt

.PHONY: clean all mproper

#règle générale
all : $(EXEC)

#dépendance des .h
bmp.o : bmp.h
main.o : bmp.h

#règle de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

#édition de liens
$(EXEC) : $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o