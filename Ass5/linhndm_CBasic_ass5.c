#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define DEBUG 1

#if defined(DEBUG) && (DEBUG)
	#define PRINTF  printf
#else
	#define PRINTF
#endif

#define MAX_ADDRESS 8
#define MAX_LENG_S_RECORD 78

void parse(char* str) {
	char *type;
	char address[MAX_ADDRESS + 1], data[MAX_LENG_S_RECORD+1];
	
	if (str[1] == '0' || str[1] == '1' || str[1] == '5' || str[1] == '9')
	{
		//memset(address, '\0', sizeof(address));
		strncpy(address, str + 4, 4);
		PRINTF(" address %s\n", address);
		
	} else 
	if (str[1] == '2' || str[1] == '6' || str[1] == '8')
	{
		//memset(address, '\0', sizeof(address));
		strncpy(address, str + 4, 6);
		PRINTF("address %s\n", address);
	} 
	else
	if (str[1] == '3' || str[1] == '7')
	{
		//memset(address, '\0', sizeof(address));
		strncpy(address, str + 4, 8);
		PRINTF("address %s\n", address);
	}
}

int main(){
	char str[100][79];
	uint32_t i = 0;
	FILE *pFile  = fopen("filehandling.srec", "r");
	while (!feof(pFile)) {
		fgets(str[i++], 100, pFile);
	}

	uint32_t j = 0;
	uint32_t len = 0;

	for (j = 0; j < i; j++) {
		len = strlen(str[j] - 1);
		// PRINTF("Length: %d --- %s", len, str[j]);
		parse(str[j]);
	}

	return 0;
}
