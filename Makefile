

SRC = $(wildcard *.c) #fichiers sources
OBJ = $(SRC:.c=.o) #fichiers objets
PROG = tp6 # nom de l'exécutable
CC = gcc


$(PROG) : $(OBJ)
# On compile le programme
# on transforme tous les .o en un exécutable
	$(CC) $^ -o $@ 


.c.o :
#on génère les fichiers .o
	$(CC) -c $^ -o $@


PHONY : clean


clean :
# on supprime tous les fichiers liés à la complilation
	rm -f $(OBJ)
