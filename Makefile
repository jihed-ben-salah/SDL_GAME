prog:othello.o main.o 
	gcc othello.o main.o  -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g 
othello.o:othello.c
	gcc -c othello.c -g 
