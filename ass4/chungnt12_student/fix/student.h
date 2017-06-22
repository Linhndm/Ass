#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_LENG_NAME 20
#define Min_LENG_NAME 5
#define MAX_VALUE_MARK 10
#define MIN_VALUE_MARK 0
#define MAX_SIZE_CLASS 255
#define FALSE 0
#define TRUE
struct student
{
	uint8_t id;
	uint8_t fullName[MAX_LENG_NAME];
	uint8_t mark;
	struct student *pNext;
};
typedef struct student student_t;

struct list
{
	uint8_t size;
	student_t *pHead;
	student_t *pTail;
};
typedef struct list list_t;


#endif/*__STUDENT_H_*/