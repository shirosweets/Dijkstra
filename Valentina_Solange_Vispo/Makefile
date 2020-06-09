# Makefile del Laboratorio 6
# all: main.o graph.o cost.o dijkstra.o

CC = gcc
# CFLAGS sirve para usarlo como $(CFLAGS) para usarlo como una variable
# y no repetir todo el tiempo escrito todo eso
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
AUTOR = Valentina Solange Vispo
NUM_LAB = 6
MAT = Algoritmos y Estructura de Datos II - FAMAF - 2020

# all Depende de main.o dijkstra.o cost.o set.o graph.o
all: main.o dijkstra.o cost.o set.o graph.o
		$(CC) $(CFLAGS) -o dijkstra main.o graph.o cost.o dijkstra.o set.o

# main.o Depende de main.c y dijkstra.h
main.o: main.c dijkstra.h
		$(CC) $(CFLAGS) -c main.c

# graph.o Depende de graph.c cost.c
graph.o: graph.c cost.c
		$(CC) $(CFLAGS) -c graph.c

# cost.o Depende de cost.h
cost.o: cost.h
		$(CC) $(CFLAGS) -c cost.c

# dijkstra.o Depende de dijkstra.c set.h graph.h cost.h
dijkstra.o: dijkstra.c set.h graph.h cost.h
		$(CC) $(CFLAGS) -c dijkstra.c

.PHONY: clean # Regla "ficticia" que elimina los ficheros creados (.o) junto con el programa (all)
clean: # Se usa con $ make clean
		rm -f all main.o graph.o cost.o dijkstra.o

autor: # Imprime el nombre del autor # Se usa con $ make autor # @echo silencia el echo en consola
		@echo $(AUTOR)

lab: # Imprime el número del laboratorio # Se usa con $ make lab
		@echo $(NUM_LAB)

materia: # Imprime el nombre de la materia, junto con su facultad y año # Se usa con $ make materia
		@echo $(MAT)