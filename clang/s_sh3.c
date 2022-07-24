#include <stdio.h>       // fprintf, perror 
#include <stdlib.h>      // exit, malloc, realloc
#include <unistd.h>      // fork, getpid, chdir
#include <sys/wait.h>    // waitpid (instead of sleep())
#include <string.h>      // strtok, strcmp

/*
 * Felipe Pegoraro, 22/07/2022
 * simple shell
 * 
 * THANKS to Stephen Brennan for the 
 * tutorial on his website.
*/ 

#define SH_NAME "xxfsh"
#define BUFSIZE 1024
#define MTCHR " \n\t\r\a"

void main_loop(void);
char *readline(void);
char **readargs(char *line);
int ex_ps(char **args);

int cd(char *path);
int exitt(void);

int
main(void) {
	main_loop();
}

void 
main_loop(void){
	char  *line;
	char **args;
	int  status = -1; 
	char *cdir;

	do {
		if ((cdir = getcwd(NULL, 0)) != NULL)
			fprintf(stdout, "%s", cdir);
		fprintf(stdout, " > ");

		line = readline();
		args = readargs(line);

		// creating commands ----------------------
		if (strcmp(args[0], "cd") == 0){
			if (cd(args[1]) == -1) perror(args[1]);
			continue;
		}
		if (strcmp(args[0], "exitt") == 0){
			exitt();
			continue;
		}

		status = ex_ps(args);

		free(line);
		free(args);
		free(cdir);
	} while (status != -1);

	exit(EXIT_SUCCESS);
}


char *
readline(){
	int s, pos = 0, bufsize = BUFSIZE;
	char *buf = malloc(bufsize * sizeof(char));
	if (!buf) { perror(SH_NAME) ; exit(EXIT_FAILURE); }

	while (1){
		s = getchar();
		if (s == EOF || s == '\n'){
			buf[pos] = '\0'; // end
			return buf;
		}
		buf[pos] = s;
		pos++;
	}
	if (pos > bufsize){
		bufsize += BUFSIZ;
		buf = realloc(buf, bufsize);
		if (!buf){ perror(SH_NAME) ; exit(EXIT_FAILURE); }
	}
}

char **
readargs(char *line){
	int pos = 0, bufsize = BUFSIZE;
	char **tokens = malloc(bufsize * sizeof(char *));
	if(!tokens){ perror(SH_NAME) ; exit(EXIT_FAILURE); }

	char *token;
	token = strtok(line, MTCHR);

	// signal(SIGINT, SIG_IGN); // ignore ^C -> shell "run forever"
	// signal(SIGINT, SIG_DFL); // default behavior ^C
	
	while (token != NULL){
		tokens[pos] = token;
		pos++;
		if (pos > bufsize){
			bufsize += BUFSIZ;
			tokens = realloc(tokens, bufsize*sizeof(char *));
			if (!tokens){ perror(SH_NAME); exit(EXIT_FAILURE); }
		}
		token = strtok(NULL, MTCHR);
	}

	tokens[pos] = NULL;
	return tokens;
}

int
ex_ps(char **args){
	int e_status = 0;       // end_status 
	pid_t ch_pid, wait_pid; // child_pid, wait_pid

	// this function [fork] create a new process
	if ((ch_pid = fork()) == 0) { // child process
		if (execvp(args[0], args) == -1) perror(SH_NAME);
		exit(EXIT_FAILURE);
	}
	else if (ch_pid < 0){ // error while trying to fork
		perror(SH_NAME);
	} 
	else do { // parent process (getpid) (waitpid will wait ch_pid finish)
		wait_pid = waitpid(ch_pid, &e_status, WUNTRACED);
		if (wait_pid <= 0) exit(EXIT_FAILURE);
	} while (!WIFEXITED(e_status) && !WIFSIGNALED(e_status));//exit_error|^C/^D

	return 1;
}

int exitt(void){ return 0; }
int cd(char *path){ return chdir(path); } // unistd 
