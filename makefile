prog:test.o  main.o 
	gcc test.o  main.o -o prog -lSDL -lSDL_image 
main.o:main.c
	gcc -c main.c -g
test.o:test.c
	gcc -c test.c -g
