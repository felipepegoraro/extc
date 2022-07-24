#include <stdio.h>  // printf, perror
#include <stdlib.h> // exit(EXIT_SUCESS)
#include <unistd.h> // getlogin, getuid
#include <pwd.h>    // getpwuid, (struct passwd)

/*
 * Felipe Pegoraro, 22/07/2022
 * displays the username
 * getlogin was not working
*/

char * myName(void);

int
main(void) {
	char *name = getlogin();

	if (!name)
		name = myName();

	printf("Welcome, %s!\n", name); // `id -un`

	exit(EXIT_SUCCESS);
}

char *
myName(void){
	// `id -n`
	uid_t  uid= getuid();             // get the user id ("real user ID")
	struct passwd *p = getpwuid(uid); // read the passwd of the user

	if (p == NULL){
    perror("getpwuid() error");
		return "error";
	}
  else {
		return p->pw_name;
	}
}

/*
 * pw_name 
 * pw_uid  
 * pw_gid  
 * pw_dir  
 * pw_shell
*/

// B1.7 Error Functions 
// perror:   fprintf(stderr, "%s: %s\n", s, strerror(errno));

// B3. String Functions
// strerror: return a string corresponding to errno
 
