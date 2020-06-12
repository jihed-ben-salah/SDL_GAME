prog:main.o hero1.o hero_deux.o background.o 
	gcc main.o hero1.o hero_deux.o background.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
hero1.o:hero1.c
	gcc -c hero1.c -g
hero_deux.o:hero_deux.c
	gcc -c hero_deux.c -g
background.o:background.c
	gcc -c background.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
