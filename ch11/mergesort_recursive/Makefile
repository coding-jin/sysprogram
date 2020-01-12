all: mergesort

mergesort: mergesort.c
	gcc mergesort.c -o mergesort -Werror -Wall -std=c99 -fsanitize=address

clean:
	-rm -rf mergesort
