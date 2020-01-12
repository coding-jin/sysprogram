all: kth

kth: kth.c
	gcc kth.c -o kth -g -std=c99 -Werror -Wall -fsanitize=address

clean:
	-rm -f kth
