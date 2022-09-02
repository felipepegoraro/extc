#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Felipe Pegoraro (02/09/2022)

void f(){printf(" + running the function f()\n");}
void g(){printf(" + running the function g()\n");}
void h(){printf(" + running the function h()\n");}

int main(){
	unsigned int reply=0;

	char fc[4][2] = {
		{1, 'f'}, {2, 'g'}, {3, 'h'}
	};
	for (unsigned i=0; i<3; i++){
		printf(" | [%u]: %c\n", i, fc[i][1]);
	}
	
	// void (*arr[])(int)
	void (*arr[])(int) = { f, g, h };

	printf(" > insert a value: "); scanf("%u", &reply);

	if (reply >= 3) { 
		printf(" + not found!\n");
		return EXIT_FAILURE; 
	}

	arr[reply](reply);
	sleep(3);
	printf(" + done\n");
	return EXIT_SUCCESS;
}
