prog:personnage.o main.o collision.o
	gcc personnage.o main.o collision.o -o prog -lSDL -lSDL_image -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -g
enigme.o:personnage.c
	gcc -c personnage.c -g
collision.o:collision.c
	gcc -c collision.c -g
