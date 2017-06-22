#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parse(char* str) {
	char *type, *address, *data;
	
	if (str[1] = '1')
	{
		strncpy(address, str, 4);
		printf("%s", address);
	}
}

int main(int argc, char *argv[]){
    char str[100][100];
	int i = 0;
	FILE *in  = fopen("filehandling.srec", "r");
    while (!feof(in)) {
		fgets(str[i++], 100, in);
	}

	int j = 0;
	int len = 0;
	for (j = 0; j < i; j++) {
		// len = strlen(str[j]);
		// printf("Length: %d --- %s", len, str[j]);
		parse(str[j]);
	}

    return 0;
}