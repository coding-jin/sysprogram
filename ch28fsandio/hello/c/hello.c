#include <stdio.h>
#include <unistd.h>
#include <string.h>

char msg[14] = "Hello, world!\n";

int main(int argc, char **argv)
{
	int len = strlen(msg);
	write(1, msg, len);
	_exit(0);
	return 0;
}

