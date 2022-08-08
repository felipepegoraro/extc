#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

/*
 * Felipe Pegoraro, 08/08/2022
 * rewriting the cat command 
 * (buffered version)
 * (now with system calls)
*/

void err(char *fmt, ...);
void ccat(char *name);

int main (int argc, char *argv[])
{
	if (argc <= 1){
		ccat(NULL);
	} else {
		for (int i=1; i<argc; i++)
			ccat(argv[i]);
	}
}

void ccat(char *name){
	int n = 0, fd;
	char buf[BUFSIZ];

	if ((fd = open(name, O_RDONLY)) == -1)
		err("%d, %s", errno, "file not found!");
	else {
		while ((n = read(fd, buf, BUFSIZ)) > 0){
			write(1, buf, n);
		}
	}
}

void err(char *fmt, ...){
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "erro: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(EXIT_FAILURE);
}
