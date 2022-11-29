#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

int main(){

	char *in;
	in = malloc(20 * sizeof(char));
	strcpy(in,"(3*(5/2)*2118)/2");
	char **cad, **ini;
	in = malloc(20 * sizeof(char));
	strcpy(in,"segunda");
	*cad++;
	*cad=in;

	printf("CAD %s\n",*ini);


	free(cad);
	free(in);
	return(0);
}