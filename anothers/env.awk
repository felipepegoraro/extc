#!/bin/awk -f

BEGIN {
	if (ARGC > 1){
		for (i=1;i<ARGC;++i){
			x=toupper(ARGV[i])
			if (length(ENVIRON[x])>0)
				printf("%s:%s\n", x, ENVIRON[x])
		}
	}
	else {
		print("USAGE:\n\t./env.awk VAR")
		exit 1
	}
}
