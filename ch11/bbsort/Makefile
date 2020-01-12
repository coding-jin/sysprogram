all: bbsort

bbsort: bbsort.c
	gcc bbsort.c -o bbsort -Werror -Wall -std=c99 -fsanitize=address

clean:
	-rm -f bbsort
