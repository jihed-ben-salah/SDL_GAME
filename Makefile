prog:fonction.o main1.o
	gcc fonction.o main1.o -o prog -lSDL -lSDL_image -lSDL_ttf -g
main1.o:main.c
	gcc -c main1.c -g
fonction.o:fonction.c
	gcc -c fonction.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
