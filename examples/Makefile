SHELL=/bin/bash

all: ppm.o alpha.o example1.o example2.o example3.o example4.o example5.o example6.o example7.o example8.o
	gcc -o example1 example1.o ppm.o alpha.o
	gcc -o example2 example2.o ppm.o alpha.o
	gcc -o example3 example3.o ppm.o alpha.o
	gcc -o example4 example4.o ppm.o alpha.o
	gcc -o example5 example5.o ppm.o alpha.o
	gcc -o example6 example6.o ppm.o alpha.o
	gcc -o example7 example7.o ppm.o alpha.o
	gcc -o example8 example8.o ppm.o alpha.o

clean:
	rm *.o
	rm example{1..8}

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

.PHONY: all clean
