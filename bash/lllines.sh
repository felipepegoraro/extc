#!/bin/bash
# Felipe Pegoraro
# 24/07/2022

test "$(command -v loc)" && { 
		awk '
			BEGIN {FIELDWIDTHS="23 52 6"}
			NR > 3 { 	printf(" %3.d |%s\n", $3, $1) }
		' <(loc ../) | head -n -3 ;
	} || echo "loc: command not found"
