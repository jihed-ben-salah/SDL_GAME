prog:enigme.o main.o
	gcc enigme.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
