#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_TYPE 3
#define QUIT_INPUT 2
#define FULL_STUDENT 2

typedef struct student
{
	int mark;
	char name[MAX_NAME];
	struct student *pNext;
} student_t;

static int g_count = 1;

student_t *pHead = NULL;
student_t *pTail = NULL;


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

void insertBotStudent(const char* name, int lenName, int mark)// cso the dung strlen
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

student_t* findStudent(const char* name)
{
	student_t *pFind = pHead;
	while (pFind != NULL)
	{
		if(strcmp(pFind-> name, name) == 0)
		{
			printf("Find Name: %s", pFind->name);
			return pFind;
		}
		else
		{
			pFind = pFind -> pNext;
		}
	}
	return NULL;
}

void removeStudent(const char* name)
{
	student_t* address=findStudent(name);

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

void printStudent()
{	

	int i = 0;
	student_t* pPrint = pHead;
	printf("\n******************************************************************");
	printf("\n			---STUDENT lIST---");
	while (pPrint != NULL)
	{

		printf("\nStudent %-4d: %-40s	Mark: %-3d",++i, ( pPrint -> name ), (pPrint -> mark ));
		pPrint = pPrint->pNext;
	}
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
	printf("\n -- ");
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


int main()
{	
	int checkQuitInput = 0;
	char selectQuitInput[QUIT_INPUT];
	do
	{
		inputNewStudent();
		printStudent();
		printf("\nYou want to add new student???\nSelect number: \n1 - Yes\n2 - No\n --  ");
		gets(selectQuitInput);
		if(strcmp(selectQuitInput,"1") == 0)
		{
			if(g_count > FULL_STUDENT)
			{
				printf("\nClass have been full");
				checkQuitInput = 1;
			}
		}
		else if(strcmp(selectQuitInput,"0") == 0)
		{
			checkQuitInput = 1;
		}

	}
	while(checkQuitInput == 0);

	return 0;
}

