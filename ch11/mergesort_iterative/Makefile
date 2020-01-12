all: mergesort

mergesort: mergesort.c
	gcc mergesort.c -o mergesort -Werror -Wall -std=c99 -fsanitize=address -g

clean:
	-rm -rf mergesort
