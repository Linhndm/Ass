#include "linked_list.h"

int g_count = 0;

student_t *pHead = NULL;
student_t *pTail = NULL;

void printStudent()
{
	int i = 0;
	student_t* pPrint = pHead;
	printf("\n******************************************************************");
	printf("\n			---STUDENT LIST---");
	printf("\n			   ____***____");
	while (pPrint != NULL)
	{
		printf("\nStudent %-3d:ID: %-3d\tName: %-40s\tMark: %-3d",++i, (pPrint->ID), (pPrint->name), (pPrint->mark));
		pPrint = pPrint->pNext;
	}
	printf("\n******************************************************************");
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
	newStudent -> ID = g_count;
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
	newStudent -> ID = g_count;
}

student_t* findNameStudent(const char* name)
{
	int flag = 0;
	student_t *pFindN = pHead;
	printf("\n******************************************************************\n");
	while (pFindN != NULL)
	{
		if(strcmp(pFindN-> name, name) == 0)
		{
			printf("\nMark of Student have a Name %s", name);
			printf("\n ID: %-3d\tName: %-40s Mark: %-3d\n",(pFindN->ID), (pFindN->name), (pFindN->mark));
		}
			pFindN = pFindN -> pNext;

	}
	printf("\n******************************************************************\n");
	return NULL;
}

student_t* findMarkStudent(int mark)
{
	int flag = 0;
	student_t *pFindM = pHead;
	printf("\n******************************************************************");
	while (pFindM != NULL)
	{
		if(( pFindM -> mark ) == mark)
		{
			printf("\nName of Student have a Mark %d", mark);
			printf("\nName: %s Mark: %d\n", (pFindM->name), (pFindM->mark));
		}
			pFindM = pFindM -> pNext;
	}
	printf("\n******************************************************************");
	return NULL;
}

student_t* findIDStudent(int ID)
{
	student_t* pFindID = pHead;
	printf("\n******************************************************************");
	while (pFindID != NULL)
	{
		if(( pFindID -> ID ) == ID)
		{
			printf("\nName of Student have a ID %d", ID);
			printf("\nName: %s Mark: %d\n", (pFindID->name), (pFindID->mark));
			return pFindID;
		}
		else
		{
			pFindID = pFindID -> pNext;
		}
	}
	printf("\n******************************************************************");
	return NULL;
}

void checkFindStudent()
{
	char selectFind[MAX_TYPE];
	int checkQuitFind = 0;
	char selectQuitFind[MAX_TYPE];
	char name[MAX_NAME];
	int mark;
	int ID;
	do
	{
		printf("\nSelect number to Find Student from Student List");
		printf("\n 1 - Find by name Student");
		printf("\n 2 - Find by mark Student ");
		printf("\n 3 - Find by ID Student \n ");
		printf("\n-- ");
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

		else if(strcmp(selectFind,"3") == 0)
		{
			printf("\nEnter ID of Student: ");
			scanf("%d",&ID);
			findIDStudent(ID);
		}


		printf("\nYou want to continute??? \nSelect number: \n1 - Yes\n2 - No\n --  ");
		gets(selectQuitFind);
		if(strcmp(selectQuitFind,"1") == 0)
		{
		}
		else if(strcmp(selectQuitFind,"2") == 0)
		{
			checkQuitFind= 1;
		}
	}
	while(checkQuitFind == 0);
}

void removeNameStudent(const char* name)
{
	student_t* address=findNameStudent(name);

	if (address == NULL)
	{
		return;
	}

	student_t* pPre = pHead;

	if(address == pHead)
	{
		pHead = pHead -> pNext;
		return;
	}
	while(pPre -> pNext != address)
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
	{
		return;
	}

	student_t* pPre = pHead;

	if(address == pHead)
	{
		pHead = pHead -> pNext;
		return;
	}
	while(pPre -> pNext != address)
	{
		pPre = pPre -> pNext;
	}

	pPre-> pNext = address -> pNext;

	g_count--;
}

int removeIDStudent(int ID)
{
	student_t* pTemp;
	student_t* pPre;
	pTemp=pHead;
	pPre=pHead;
	{
		if (pHead -> ID == ID)
		{
			pHead = pHead -> pNext;
			return 1;
		}
		if(pTemp -> ID == ID)
		{
			printf("\nID number %d  %s  Mark: %d", (pTemp->ID), (pTemp->name), (pTemp->mark));

				pPre -> pNext = pTemp -> pNext;
				printf("\nRemove successfull...\n");
				return 1;
		}

		pPre = pTemp;
		pTemp = pTemp -> pNext;
	}	printf("\nNot found !!!\n");

	g_count--;
	free(pTemp);
	return 0;

}

void checkRemoveStudent()
{
	char selectRemove[MAX_TYPE];
	int checkQuitRemove = 0;
	char selectQuitRemove[MAX_TYPE];
	char name[MAX_NAME];
	int mark;
	int ID;
	do
	{
		printf("\nSelect number to remove Student from Student List");
		printf("\n 1 - Remove by name Student");
		printf("\n 2 - Remove by mark Student ");
		printf("\n 3 - Remove by ID Student \n ");
		gets(selectRemove);
		if(strcmp(selectRemove,"1") == 0)
		{
			printf("\nEnter name of Student: ");
			fflush(stdin);
			gets(name);
			findNameStudent(name);
			printf("\nEnter ID student's you want to remove: ");
			scanf("%d", &ID);
			removeIDStudent(ID);
		}
		else if(strcmp(selectRemove,"2") == 0)
		{
			printf("\nEnter mark of Student: ");
			scanf("%d",&mark);
			findMarkStudent(mark);
			printf("\nEnter ID student's you want to remove: ");
			scanf("%d", &ID);
			removeIDStudent(ID);
		}
		else if(strcmp(selectRemove,"3") == 0)
		{
			printf("\nEnter ID of Student: ");
			scanf("%d",&ID);
			removeIDStudent(ID);
		}
		printStudent();

		printf("\nYou want to continue remove student???\nSelect number: \n1 - Yes\n2 - No\n --  ");
		fflush(stdin);
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
	int checkMark = 0;
	int ID;
	char type[MAX_TYPE];
	printf("\nNew student's name : ");
	fflush(stdin);
	gets(name);
	do
	{
		printf("\nMark: ");
		scanf("%d",&mark);
		if(( 0 <= mark) && (mark <= MAX_MARK))
		{
			checkMark = 1;
		}
		else
		{
			printf("\nPlease input mark between 0 and %d", MAX_MARK);
		}
	}
	while(checkMark == 0);
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
		printf("\n\nYou want to add new student???\nSelect number: \n1 - Yes\n2 - No\n-- ");
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

