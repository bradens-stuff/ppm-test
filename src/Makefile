all: test.o ppm.o alpha.o
	gcc $^ -o test

test.o: test.c
	gcc -c $^ -Wall -O2
ppm.o: ppm.c
	gcc -c $^ -Wall -O2
alpha.o: alpha.c
	gcc -c $^ -Wall -O2

clean:
	rm *.o

.PHONY: all clean
