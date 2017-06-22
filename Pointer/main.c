 #include "linked_list.h"

int main()
{
	char selectMain[MAX_TYPE];

	while(1)
	{
		printf("\n\n\nSelect a function:");
		printf("\n1 - Add new Student");
		printf("\n2 - Find Student");
		printf("\n3 - Remove Student");
		printf("\n4 - Print Student List");
		printf("\n5 - Close Program");
		printf("\n-- ");
		gets(selectMain);
		if(strcmp(selectMain,"1") == 0)
		{
			checkAddStudent();
		}
		if(strcmp(selectMain,"2") == 0)
		{
			checkFindStudent();
		}
		if(strcmp(selectMain,"3") == 0)
		{
			checkRemoveStudent();
		}
		if(strcmp(selectMain,"4") == 0)
		{
			printStudent();
		}
		if(strcmp(selectMain,"5") == 0)
		{
			return 0;
		}

	};
	return 0;
}
