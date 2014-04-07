SHELL=/bin/bash
CC=gcc -o
LL=ppm.o alpha.o

all: $(LL) example1.o example2.o example3.o example4.o example5.o example6.o example7.o example8.o example9.o example10.o
	$(CC) example1 example1.o $(LL)
	$(CC) example2 example2.o $(LL)
	$(CC) example3 example3.o $(LL)
	$(CC) example4 example4.o $(LL)
	$(CC) example5 example5.o $(LL)
	$(CC) example6 example6.o $(LL)
	$(CC) example7 example7.o $(LL)
	$(CC) example8 example8.o $(LL)
	$(CC) example9 example9.o $(LL)
	$(CC) example10 example10.o $(LL)

clean:
	rm *.o
	rm example{1..10}

ppm.o:
	cd ../src && gcc -c ppm.c && mv ppm.o ../examples
alpha.o:
	cd ../src && gcc -c alpha.c && mv alpha.o ../examples

example1.o: example1.c
	gcc -c $^
example2.o: example2.c
	gcc -c $^
example3.o: example3.c
	gcc -c $^
example4.o: example4.c
	gcc -c $^
example5.o: example5.c
	gcc -c $^
example6.o: example6.c
	gcc -c $^
example7.o: example7.c
	gcc -c $^
example8.o: example8.c
	gcc -c $^
example9.o: example9.c
	gcc -c $^
example10.o: example10.c
	gcc -c $^

.PHONY: all clean
