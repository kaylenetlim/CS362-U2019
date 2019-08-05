CFLAGS = -Wall -fpic -coverage -lm -std=c99

testme:
	gcc -o testme -g testme.c $(CFLAGS)
	./testme
	
testmecov:
	gcov -b -f testme

clean:
	rm -f testme *.gcov *.gcda *.gcno *.o
