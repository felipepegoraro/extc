#!/bin/bash
# Felipe Pegoraro, 28/07/2022

hxx(){
	for i in "$@"; do
		: $((16#${i#*x}))
		printf \\$(printf '%03o' $_)
	done
}

hxx $@

# ./hxx.sh 46 65 6c 69 70 65 0a
# Felipe

# ./hxx.sh \x46 \x65 \x6c \x69 \x70 \x65 \x0a
# Felipe
