all: test.o ppm.o
	gcc $^ -o test

test.o: test.c
	gcc -c $^ -Wall -O2
ppm.o: ppm.c ppm.h
	gcc -c $^ -Wall -O2

clean:
	rm *.o *.gch

.PHONY: all clean
