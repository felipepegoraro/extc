#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Felipe Pegoraro, 22/07/2022
 * display the current time
*/

char *t;
time_t rawtime;
struct tm *timeinfo;

char *week[]={
	"Sunday", "Monday", "Tuesday",
	"Wednesday", "Thursday", "Friday",
	"Saturday"
};

char *month[]={
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};

int 
main(int argc, char *argv[])
{
  time(&rawtime);
  timeinfo = localtime(&rawtime);

	if (argc > 1 && strcmp(argv[0], "-s")){
		fprintf(stdout, "%s", asctime(timeinfo)); // convert timeinfo to string
	}
	else {
		fprintf(stdout, "%s %d %s %d %d:%d:%d %s\n",
			week[timeinfo->tm_wday], 
			timeinfo->tm_mday, 
			month[timeinfo->tm_mon],
			timeinfo->tm_year + 1900,
			timeinfo->tm_hour,
			timeinfo->tm_min,
			timeinfo->tm_sec,
			timeinfo->tm_zone
		);  
	} 

	return EXIT_SUCCESS;
}

