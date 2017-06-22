#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

typedef struct student
{
	int mark;
	char name[MAX_NAME];
	struct student *pNext;
} student_t;

int g_count = 1;

student_t *pHead = NULL;
student_t *pTail = NULL;

#endif/*__LINKED_LIST_H_*/