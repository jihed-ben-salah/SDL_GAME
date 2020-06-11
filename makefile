prog:entite.o  main.o 
	gcc entite.o  main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
entite.o:entite.c
	gcc -c entite.c -g
