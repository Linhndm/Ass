#include <stdio.h>
#include <stdlib.h>

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


parse_status_t parseData(uint8_t pInput[], parse_data_struct_t *pOutput);
{

}

int lineNumber(char *inname, FILE* infile)
{
	char line_buffer[BUFSIZ];
	char line_number;
	char *line[BUFSIZ];

	line_number = 0;
	while (fgets(line_buffer, sizeof(line_buffer), infile)) {
		++line_number;
		/* note that the newline is in the buffer */
		printf("%4d: %s", line_number, line_buffer);

	}
	printf("\nTotal number of lines = %d\n", line_number);

	return line_number;

}

int main()
{
	char *inname = "filehandling.srec";
	FILE *infile;

	infile = fopen(inname, "r");
	if (!infile) {
		printf("Couldn't open file %s for reading.\n", inname);
		return 0;
	}
	printf("Opened file %s for reading.\n", inname);

	int count = lineNumber(inname, infile);

	printf("\nTotal number of lines count = %d\n", count);
	for(int i =0; i < count; i++)
	{
		printf("\nTotal number of lines count = %d\n", line_buffer[i]);
	}
	
	return 0;
}

