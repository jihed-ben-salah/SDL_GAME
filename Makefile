prog:enigmeavecfichier.o main.o 
	gcc enigmeavecfichier.o main.o  -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g 
enigmeavecfichier.o:enigmeavecfichier.c
	gcc -c enigmeavecfichier.c -g 
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
