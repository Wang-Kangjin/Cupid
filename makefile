cupid: main.o heart.o panel.o arrows.o logo.o
	gcc -o cupid main.o heart.o panel.o arrows.o logo.o
heart.o: heart.c panel.o panel.h heart.h
	gcc -c heart.c 
panel.o: panel.c panel.h heart.h
	gcc -c panel.c
arrows.o :arrows.c panel.o heart.h arrows.h
	gcc -c arrows.c
logo.o: logo.c logo.h panel.h panel.c
	gcc -c logo.c panel.o
