#!/bin/bash
# Felipe Pegoraro
# 24/07/2022

lines(){
	test "$(command -v loc)" && { 
		awk '
			BEGIN {FIELDWIDTHS="23 52 6"}
			NR > 3 { 	printf(" %3.d |%s\n", $3, $1) }
		' <(loc ../) | head -n -3 2>&1 | tee file.csv ;

		sed -i '1i count,name' file.csv
		sed -i 's/ //g;s/Bourne//;s/|/,/g' file.csv
		
		Rscript rplot.R >/dev/null 2>&1 &
	} || echo "loc: command not found"

}

lines
