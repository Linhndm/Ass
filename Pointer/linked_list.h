#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printStudent();
void insertTopStudent(const char* name, int lenName, int mark);
void insertBotStudent(const char* name, int lenName, int mark);
student_t* findMarkStudent(int mark);
student_t* findNameStudent(const char* name);
student_t* findIDStudent(int ID);
void checkFindStudent();
void removeNameStudent(const char* name);
void removeMarkStudent(int mark);
int removeIDStudent(int ID);
void checkRemoveStudent();
void inputNewStudent();
void checkAddStudent();

#endif/*__LINKED_LIST_H_*/
