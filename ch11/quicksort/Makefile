all: quicksort

quicksort: quicksort.c
	gcc quicksort.c -o quicksort -g -Werror -Wall -fsanitize=address -std=c99

clean:
	-rm -f quicksort
