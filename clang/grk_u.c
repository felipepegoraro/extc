#include <stdio.h>    // fprintf
#include <stdlib.h>   // exit, (EXIT_SUCCESS)
#include <locale.h>   // setlocale
#include <wchar.h>    // wcslen, fwprintf, (wchar_t)

/*
 * Felipe Pegoraro, 22/07/2022
 * testing some unicode characters
*/ 

char *res;
char locale[] = "pt_BR.UTF-8"; // list all: `/bin/locale`

wchar_t *greek[] = {
	L"03A3: \u03A3",
	L"0394: \u0394",
	L"03BE: \u03BE",
	L"03A9: \u03A9",
	L"03C8: \u03C8",
	L"03C0: \u03C0",
	L"0398: \u0398",
	L"039B: \u039B"
};

int 
main(void)
{
	// `echo "$LANG"`
	res = setlocale(LC_ALL,	""); // if $LANG isnt defined ... 
	setlocale(LC_CTYPE, locale); // specify the locale

	if (res == NULL)
		fprintf(stderr, "%s: %s\n", 
				"cannot change the locale", locale);

	unsigned long tam = sizeof(greek)/wcslen(greek[0]);
	for (size_t i=0; i<tam-1; i++){
		fwprintf(stdout, L"%ls\n", greek[i]);
	}

	// obs: "\u03A3": 3 bytes
	// fprintf(stdout, "%ld\n", sizeof("\u03A3"));

	exit(EXIT_SUCCESS);
}
