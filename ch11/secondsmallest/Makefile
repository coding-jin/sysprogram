all: second

second: second.c
	gcc second.c -o second -Werror -Wall -std=c99 -fsanitize=address

clean:
	-rm -ff second
