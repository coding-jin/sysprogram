#include <stdio.h>
#include <stdlib.h>

int bar(int c, int d) {
	int e = c+d;
	return e;
}

int foo(int a, int b) {
	return bar(a, b);
}

int main(int argc, char **argv) {
	foo(2, 3);
	return 0;
}

