#include <stdio.h>   // fscanf FILE printf perror
#include <stdlib.h>  // exit EXIT_(SUCCESS|FAILURE)
#include <string.h>  // strcat, strtok, strcmp

/*
 * Felipe Pegoraro, 23/07/2022 
 * (first time) C word counter,
 * using `strtok()` for the tokens
*/

#define TOTAL 32
#define BFSIZE 65536
#define CH " \n\t\r\a{}+=;*,][()<>#/"

struct key {
	char *word;
	int count;
} keyword[] = {
	{"auto", 0},     {"break", 0},    {"case", 0},
	{"char", 0},     {"const", 0},    {"continue", 0},
	{"default", 0},  {"do", 0},       {"double", 0},
	{"else", 0},     {"enum", 0},     {"extern", 0},
	{"float", 0},    {"for", 0},      {"goto", 0},
	{"if", 0},       {"int", 0},      {"long", 0},
	{"register", 0}, {"return", 0},   {"short", 0},
	{"signed", 0},   {"sizeof", 0},   {"static", 0},
	{"struct", 0},   {"switch", 0},   {"typedef", 0},
	{"union", 0},    {"unsigned", 0}, {"void", 0},
	{"volatile", 0}, {"while", 0} 
};

FILE * readfile(int i, char *s[]);

int 
main(int argc, char *argv[])
{
	int i=0;
	FILE *fp = readfile(argc, argv);
	char line[BFSIZE]={}, words[BFSIZE]={}; // [TODO]

	while((i = fscanf(fp, " %s ", line)) && i != EOF) {
		strcat(words, line);
		strcat(words, "\n");
	}

	char *token = strtok(words, CH);

	while(token != NULL) {
		for (i=0; i<TOTAL; i++){
			if (strcmp(token, keyword[i].word) == 0){
				keyword[i].count++;
			}
		}
		token = strtok(NULL, CH);
	}

	for (i=0; i<TOTAL; i++){
		if (keyword[i].count>0)
			printf("%4.d: %s\n", 
					keyword[i].count,
					keyword[i].word);
	}

	fclose(fp);
	return EXIT_SUCCESS;
}


FILE *
readfile(int i, char *s[]){
	if (i <= 1){
		fprintf(stderr, "usage: ./parser file\n");
		exit(EXIT_FAILURE);
	}

	FILE *fp; 
	if ((fp = fopen(s[1], "r")) == NULL){
		perror("cwct");
		exit(EXIT_FAILURE);
	} 

	return fp;
}
