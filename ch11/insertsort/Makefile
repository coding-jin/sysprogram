all: insertsort

insertsort: insertsort.c
	gcc insertsort.c -o insertsort -Werror -Wall -fsanitize=address -std=c99

clean:
	-rm -rf insertsort
