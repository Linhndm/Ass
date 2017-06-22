#include "linked_list.h"

#define MAX_NAME 50
#define MAX_TYPE 2
#define QUIT_INPUT 2
#define FULL_STUDENT 10


void printStudent()
{	
	int i = 0;
	student_t* pPrint = pHead;
	printf("\n******************************************************************");
	printf("\n			---STUDENT LIST---");
	while (pPrint != NULL)
	{
		printf("\nStudent %-4d: %-40s	Mark: %-3d",++i, ( pPrint -> name ), (pPrint -> mark ));
		pPrint = pPrint->pNext;
	}
}

void insertTopStudent(const char* name, int lenName, int mark)
{
	student_t *newStudent =(student_t*)malloc(sizeof(student_t));
	newStudent -> pNext = NULL;

	int i;

	for (i = 0; i < lenName; i++)
	{
		newStudent -> name[i] = name[i];
	}

	newStudent -> mark =  mark;

	if (pHead == NULL)
	{
		pHead = newStudent;
		pTail = newStudent;
	}
	else
	{
		newStudent-> pNext = pHead;
		pHead = newStudent;
	}

	g_count++;

}

void insertBotStudent(const char* name, int lenName, int mark)
{
	student_t *newStudent = (student_t*)malloc(sizeof(student_t));

	newStudent -> pNext = NULL;
	newStudent -> mark = mark;
	int i;
	for (i = 0; i < lenName; i++)
	{
		newStudent -> name[i] = name[i];
	}

	if (pTail == NULL)
	{
		pHead = newStudent;
		pTail = newStudent;
	}
	else
	{
		pTail -> pNext = newStudent;
		pTail = newStudent;
	}

	g_count++;
}

student_t* findNameStudent(const char* name)
{
	student_t *pFindN = pHead;
	while (pFindN != NULL)
	{
		if(strcmp(pFindN-> name, name) == 0)
		{	
			printf("\nMark of Student have a Name %s", name);
			printf("\nName: %s Mark: %d\n", (pFindN->name), (pFindN->mark));
			return pFindN;
		}
		else
		{
			pFindN = pFindN -> pNext;
		}
	}
	return NULL;
}
student_t* findMarkStudent(int mark)
{
	student_t *pFindM = pHead;
	while (pFindM != NULL)
	{
		if(( pFindM -> mark ) == mark)
		{	
			printf("\nName of Student have a Mark %d", mark);
			printf("\nName: %s Mark: %d\n", (pFindM->name), (pFindM->mark));
			return pFindM;
		}
		else
		{
			pFindM = pFindM -> pNext;
		}
	}
	return NULL;
}

void checkFindStudent()
{
	char selectFind[MAX_TYPE];
	int checkQuitFind = 0;
	char selectQuitFind[MAX_TYPE];
	char name[MAX_NAME];
	int mark;
	do
	{
		printf("\nSelect number to Find Student from Student List");
		printf("\n 1 - Find by name Student");
		printf("\n 2 - Find by mark Student \n ");
		gets(selectFind);
		if(strcmp(selectFind,"1") == 0)
		{
			printf("\nEnter name of Student: ");
			fflush(stdin);
			gets(name);
			findNameStudent(name);
		}
		else if(strcmp(selectFind,"2") == 0)
		{
			printf("\nEnter mark of Student: ");
			scanf("%d",&mark);
			findMarkStudent(mark);
		}


		printf("\nYou want to continute??? \nSelect number: \n1 - Yes\n2 - No\n --  ");
		gets(selectQuitFind);
		if(strcmp(selectQuitFind,"1") == 0)
		{
		}
		else if(strcmp(selectQuitFind,"2") == 0)
		{
			checkQuitFind
			 = 1;
		}
	}
	while(checkQuitFind == 0);
}

void removeNameStudent(const char* name)
{
	student_t* address=findNameStudent(name);

	if (address == NULL)
		return;

	student_t* pPre = pHead;

	if(address == pHead)
	{
		pHead = pHead -> pNext;
		return;
	}

	{
		pPre = pPre -> pNext;
	}

	pPre-> pNext = address -> pNext;

	g_count--;
}

void removeMarkStudent(int mark)
{
	student_t* address=findMarkStudent(mark);

	if (address == NULL)
		return;

	student_t* pPre = pHead;

	if(address == pHead)
	{
		pHead = pHead -> pNext;
		return;
	}

	{
		pPre = pPre -> pNext;
	}

	pPre-> pNext = address -> pNext;

	g_count--;
}

void checkRemoveStudent()
{	
	char selectRemove[MAX_TYPE];
	int checkQuitRemove = 0;
	char selectQuitRemove[MAX_TYPE];
	char name[MAX_NAME];
	int mark;
	do
	{
		printf("\nSelect number to remove Student from Student List");
		printf("\n 1 - Remove by name Student");
		printf("\n 2 - Remove by mark Student \n ");
		gets(selectRemove);
		if(strcmp(selectRemove,"1") == 0)
		{
			printf("\nEnter name of Student: ");
			fflush(stdin);
			gets(name);
			removeNameStudent(name);
		}
		else if(strcmp(selectRemove,"2") == 0)
		{
			printf("\nEnter mark of Student: ");
			scanf("%d",&mark);
			removeMarkStudent(mark);
		}
		printStudent();


		printf("\nYou want to remove student???\nSelect number: \n1 - Yes\n2 - No\n --  ");
		gets(selectQuitRemove);
		if(strcmp(selectQuitRemove,"1") == 0)
		{
			if(g_count == 0)
			{
				printf("\nClass havenot students");
				checkQuitRemove = 1;
			}
		}
		else if(strcmp(selectQuitRemove,"2") == 0)
		{
			checkQuitRemove = 1;
		}
	}
	while(checkQuitRemove == 0);
}



void inputNewStudent()
{
	char name[MAX_NAME];
	int mark;
	char type[MAX_TYPE];
	printf("\nNew student's name : ");
	fflush(stdin);
	gets(name);
	printf("Mark: ");
	scanf("%d",&mark);
	printf("\nSelect number for Position to insert: ");
	printf("\n 1 - insert to top linked list");
	printf("\n 2 - insert to bottom linked list \n ");
	printf("\n-- ");
	fflush(stdin);
	gets(type);
	if(strcmp(type,"1") == 0)
	{
		insertTopStudent(name,MAX_NAME,mark);
	}
	else if(strcmp(type,"2") == 0)
	{
		insertBotStudent(name,MAX_NAME,mark);
	}
}

void checkAddStudent()
{
	int checkQuitInput = 0;
	char selectQuitInput[QUIT_INPUT];
	do
	{
		inputNewStudent();
		printStudent();
		printf("\n\nYou want to add new student???\nSelect number: \n1 - Yes\n2 - No\n --  ");
		gets(selectQuitInput);
		if(strcmp(selectQuitInput,"1") == 0)
		{
			if(g_count > FULL_STUDENT)
			{
				printf("\nClass have been full");
				checkQuitInput = 1;
			}
		}
		else if(strcmp(selectQuitInput,"2") == 0)
		{
			checkQuitInput = 1;
		}
	}

	while(checkQuitInput == 0);
}


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
		printf("\n**************************************************\n");
	};
	return 0;
}
