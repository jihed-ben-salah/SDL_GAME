prog: background.o hero.o main.o
	gcc background.o hero.o  main.o -o  prog  -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o: main.c
	gcc -c main.c -g
background.o: background.c
	gcc -c background.c   -g
hero.o: hero.c
	gcc -c hero.c   -g

