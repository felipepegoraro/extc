#include <stdio.h>
#include <stdlib.h>

/*
 * Felipe Pegoraro, 22/07/2022
 * rewriting the cat command
 * (buffered version)
*/

#define EXNAME "ccat"

void error(char *s);
int ccat(char *file);

int main(int argc, char *argv[]){
	if (argc <= 1){
		return ccat(NULL);
	} else {
		for (int i=1; i<argc; i++)
			ccat(argv[i]);
	}
}

void error(char *s){
	perror(s); exit(EXIT_FAILURE);
}

int ccat(char *file){
	int s;
	FILE *fp;

	if (file == NULL) 
		fp = stdin;
	else if ((fp = fopen(file, "r")) == NULL){
		perror(EXNAME);
		exit(EXIT_FAILURE);
	}

	while ((s = getc(fp)) != EOF)
		if (putc(s, stdout) == EOF)
			error(EXNAME);

	if (ferror(fp))
		error(EXNAME);

	return(EXIT_SUCCESS);
}
