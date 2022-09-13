#include <stdio.h>
#include <stdlib.h>

// flexibe array members
// Felipe Pegoraro, 13/09/2022

typedef struct {
	size_t num;
	int data[]; // last member of the struct
} str;

str *f(size_t size);
void g(str *p, size_t size);

int main(void){
	size_t x;
	printf("array size: "); scanf("%zu", &x);

	str *p = f(x);
	g(p, x);

	return(EXIT_SUCCESS);
}

str *f(size_t size){
	str *p = (str *) malloc(sizeof(str)+sizeof(int)*size);
	if (p == NULL){
		perror("f");
		return NULL;
	}

	p->num = size;
	return p;
}

void g(str *p, size_t size){
	if (p == NULL){
		printf("g: null pointer\n");
		return;
	}

	if (size > 0){
		printf("array values: ");
		for (size_t i=0; i<size; ++i){
			p->data[i] = i;
			printf((i+1==p->num) ? 
					"%d\n" : "%d ", p->data[i]);
		}
	} else {
		printf("empty array\n");
	}
}

