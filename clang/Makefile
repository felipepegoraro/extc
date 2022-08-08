DIR=./bin

all: 
	mkdir -p $(DIR)
	for i in $$(ls -1 *.c); do \
		gcc -o ./bin/$${i%.c} $$i; \
	done	
