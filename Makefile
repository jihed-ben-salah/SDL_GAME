prog:roto.o main.o 
	gcc roto.o main.o  -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lSDL_gfx -g 
main.o:main.c
	gcc -c main.c -g 
enigmeavecfichier.o:roto.c
	gcc -c roto.c -g 

