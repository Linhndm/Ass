#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parse(char* str) {
	char *type, *data;
	char address[8], data[100];
	
	if (str[1] == '0' || str[1] == '1' || str[1] == '5' || str[1] == '9')
	{
		memset(address, '\0', sizeof(address));
		strncpy(address, str + 2, 4);
		printf("%s\n", address);
	} else 
	if (str[1] == '2' || str[1] == '6' || str[1] == '8')
	{
		memset(address, '\0', sizeof(address));
		strncpy(address, str + 2, 6);
		printf("%s\n", address);
	} 
	else
	if (str[1] == '3' || str[1] == '7')
	{
		memset(address, '\0', sizeof(address));
		strncpy(address, str + 2, 8);
		printf("%s\n", address);
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