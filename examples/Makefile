CXX = gcc
lib = ../src/ppm.c ../src/alpha.c
files = example1 example2 example3 example4 example5 example6 example7 example8 example9 example10

all:
	for i in $(files); do\
		$(CXX) $${i}.c $(lib) -o $$i;\
	done

run:
	for i in $(files); do\
		./$$i;\
	done

clean:
	rm $(files) *.ppm

.PHONY: all clean
