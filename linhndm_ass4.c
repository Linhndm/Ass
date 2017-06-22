#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int mark;
	char name[64];
	struct student *pNext;
};

typedef struct student student_t;

student_t *pHead = NULL;
student_t *pTail = NULL;

void insertTopStudent(const char* name, int lenName, int mark)
{
	student_t *newStudent =(student_t*)malloc(sizeof(student_t));
	newStudent -> mark =  mark;

	for (int i = 0; i < lenName; i++)
	{
		newStudent -> name[i] = name[i];
	}



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

}


void insertBotStudent(const char* name, int lenName, int mark)// cso the dung strlen
{
	student *newStudent = (student_t*)malloc(sizeof(student_t));

	newStudent -> mark = mark;
	for (int i = 0; i < lenName; i++)
	{
		newStudent -> name[i] = name[i];
	}

if (pHead == NULL)
	{
		pHead = newStudent;
		pTail = newStudent;
	}
	else
	{	
		newStudent-> pNext = pTail;
		pTail = newStudent;
	}

}

student_t* findStudent(const char* name)
{
	student_t *pFind = pHead;
	while (pFind != pTail)
	{
		if(strcmp(pFind-> name, name) == 0)
		{
			printf("Name: %s", pFind->name);
			return pFind;
		}
		else
		{
			pFind = pFind -> pNext;
		}
	}

}

void removeStudent(const char* name)
{
	student_t* address=findStudent(name);
	student_t* pPre = pHead;

	if(address == pHead)
	{
		pHead = pHead -> pNext;
	}

	while(pPre -> pNext != address)
	{
		pPre = pPre -> pNext;
	}

	pPre-> pNext = address -> pNext;

}
void printStudent()
{	
	student_t* pPrint = pHead;
	while(pPrint != NULL )
	{
		printf("Name: %s- %d\n", pPrint->name, pPrint -> mark);
		pPrint = pPrint->pNext;
	}
}

int main()
{
	insertBotStudent("Linhndm", 8, 12);
	// printStudent();
	insertBotStudent("anhnnt", 8, 11);
	printStudent();

	return 0;
}





















//
//struct node  
//{
//   int data;
//   int key;
//   struct node *next;
//};
//
//void insertFirst(int key, int data)
//{
//   //tao mot link
//   struct node *link = (struct node*) malloc(sizeof(struct node));
//	
//   link->key = key;
//   link->data = data;
//	
//   //tro link nay toi first node cu
//   link->next = head;
//	
//   //tro first toi first node moi
//   head = link;