#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_NAME 50
#define MAX_TYPE 2
#define QUIT_INPUT 2
#define FULL_STUDENT 10
#define MAX_MARK 100

typedef struct student
{
    int mark;
    int ID;
    char name[MAX_NAME];
    struct student *pNext;
} student_t;

/*Count number Student*/
int g_count = 0;
int g_countAdd = 1;

student_t *pHead = NULL;
student_t *pTail = NULL;

#endif/*__LINKED_LIST_H_*/
