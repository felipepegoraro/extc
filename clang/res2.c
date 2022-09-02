#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

// Felipe Pegoraro (02/09/2022)

// trying to understand "volatile" keyword,
// function pointer, and threads in C ...
// ~$: gcc -pthread -o c c.c

bool isdone = false;

void f(){printf(" + running the function f()\n"); sleep(3);}
void g(){printf(" + running the function g()\n"); sleep(3);}
void h(){printf(" + running the function h()\n"); sleep(3);} 

void *escF(void *arg)
{
	(void) arg;
	unsigned int reply=0;

	char fc[4][2] = {
		{1, 'f'}, {2, 'g'}, {3, 'h'}
	};

	for (unsigned i=0; i<3; i++){
		printf(" | [%u]: %c\n", i, fc[i][1]);
	}
	
	// array  of pointer to  function (int)  returning void
	void (*arr[])(int) = { f, g, h }; // void (*arr[])(int)

	printf(" > enter a value: "); scanf("%u", &reply);

	if (reply >= 3) { 
		printf(" + not found!\n");
		return NULL; 
	}

	arr[reply](reply);
	isdone=true;
	return NULL;
}

int main()
{
	pthread_t t1;
	pthread_create(&t1, NULL, escF, NULL);

	while (!isdone){
		// do something here
		// thread! thread! thread!
	}
	printf(" + done\n");

	return EXIT_SUCCESS;
}
