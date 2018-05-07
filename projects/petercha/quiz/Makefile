CFLAGS = -Wall -fpic -lm -std=c99

default: tests.out

tests.out: testme.c
	gcc -o testme testme.c $(CFLAGS)
	testme

clean:
	rm testme
