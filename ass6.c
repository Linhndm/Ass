#include <stdlib.h>
#include <stdio.h>

#define MAX_N 20

typedef struct student {
	long ID;
	char mark;
	struct student* next;
} student_t;

student_t array[20];
student_t *pHead = NULL;
student_t *pTail = NULL;
int count = 0;

void addStudent(long _ID, char _mark) {
	count++;
	if (pHead == NULL) {
		pHead = array;
		pTail = array;

		array[0].ID = _ID;
		array[0].mark = _mark;
		array[0].next = NULL;
		return;
	}

	pTail->next = pTail + 1;
	pTail++;
	pTail->next = NULL;
	pTail->ID = _ID;
	pTail->mark = _mark;
}

student_t* findStudent(long _ID) {
	student_t* ptr = pHead;
	do {
		if (ptr->ID == _ID) 
			return ptr;
		ptr = ptr->next;
	} while (ptr != NULL);
	return ptr;
}

void removeStudent(long _ID) {
	count--;
	student_t *ptr = findStudent(_ID);

	if (ptr == NULL)
		return;
	
	if (ptr == pHead) {
		pHead = pHead->next;
		return;
	}
		
	student_t* prev_ptr = pHead;
	do {
		if (prev_ptr->next == ptr) 
			break;
		prev_ptr = prev_ptr->next;
	} while (prev_ptr != NULL);

	prev_ptr->next = ptr->next;
}

void swap(student_t *p1, student_t *p2) {
	long _ID;
	char _mark;

	_ID = p1->ID; _mark = p1->mark;
	p1->ID = p2->ID; p1->mark = p2->mark;
	p2->ID = _ID; p2->mark = _mark;
}

void sortListIncreased() {
	student_t *ptr = pHead;
	student_t *nextPtr;

	int i;
	for (i = count; i >= 2; i--) {
		ptr = pHead;
		while (ptr != pTail) {
			nextPtr = ptr->next;
			if (ptr->mark > nextPtr->mark) 
				swap(ptr, nextPtr);
			ptr = ptr->next;
		}
	}
}

void printList() {
	printf("\n__List__\n");
	student_t* ptr = pHead;
	do {
		printf("%ld %d\n", ptr->ID, ptr->mark);
		ptr = ptr->next;
	} while (ptr != NULL);
}

int main() {
	addStudent(0, 10);
	addStudent(1, 9);
	addStudent(2, 6);
	addStudent(3, 7);
	addStudent(4, 2);
	addStudent(5, 5);
	addStudent(6, 6);
	sortListIncreased();
	printList();

	removeStudent(1);
	removeStudent(4);
	printList();
	return 0;
}