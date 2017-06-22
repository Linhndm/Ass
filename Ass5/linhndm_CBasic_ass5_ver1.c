#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_DATA_SIZE 100;

typedef enum {
    e_parseStatus_done = 0U,
    e_parseStatus_inprogress = 1U,
    e_parseStatus_error = 2U,
    e_parseStatus_undefined = 3U
} parse_status_t;

typedef struct
{
    uint32_t address;
    uint8_t data[MAX_DATA_SIZE];
    uint8_t dataLength;
} parse_data_struct_t;

parse_status_t parseData(uint8_t pInput[], parse_data_struct_t *pOutput)
{
	char *type;
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

void parseAdd(char* str)
{
	
}

void readFile()
{
	
}

uint32_t main()
{
	char str[100][100];
	uint32_t i = 0;
	FILE *pFile  = fopen("filehandling.srec", "r");
	while (!feof(pFile)) {
		fgets(str[i++], 100, pFile);
	}

	uint32_t j = 0;
	uint32_t len = 0;
	for (j = 0; j < i; j++) {
		len = strlen(str[j]);
		printf("Length: %d --- %s", len, str[j]);
		parse(str[j]);
	}

	return 0;
}