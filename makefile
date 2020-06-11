prog:main.o background.o ennemi.o 
	gcc main.o background.o ennemi.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g

background.o:background.c
	gcc -c background.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
