#include "student.h"

static void getLine(uint8_t *str);

static void getLine(uint8_t *str)
{
	uint8_t c;
	uint8_t i = 0;
	for (i = 0;; i++)
	{
		c = getchar();
		if (c == '\n')
		{
			str[i] = '\0';
			fflush(stdin);
			return;
		}
		str[i] = c;
	}
}
static uint8_t testId(list_t* list, uint8_t id)
{
	
}
void initList(list_t *list)
{
	list->size = 0;
	list->pHead = NULL;
	list->pTail = NULL;
}

student_t* inputStudent()
{
	student_t* newStudent = (student_t*)malloc(sizeof(student_t));;
	printf("\nEnter full name: ");
	getLine(newStudent->fullName);
	do
	{
		printf("\nEnter mark: ");
		scanf("%d", &newStudent->mark);
		fflush(stdin);
		if(newStudent->mark > MAX_VALUE_MARK || newStudent->mark < MIN_VALUE_MARK)
		{
			printf("\nERROR!Please enter mark again.");
		}/*if mark > MAX_VALUE_MARK or mark < MIN_VALUE_MARK*/
		else
		{
			/*continue*/
		}
	}while(newStudent->mark > MAX_VALUE_MARK || newStudent < MIN_VALUE_MARK);/*again enter mark*/
	newStudent->pNext = NULL;
	return newStudent;
}

void outputStudent(student_t* tempStudent)
{
	printf("ID: %d\n", tempStudent->id);
	printf("Full name: %s\n", tempStudent->fullName);
	printf("Mark: %d\n",tempStudent->mark);
}

void insertTop(list_t* list, student_t* newStudent)
{
	list->size++;
	newStudent->id = list->size;
	if(list->size > MAX_SIZE_CLASS)
	{
		printf("Class full slot.\n");
		return;
	}
	else if(list->pTail == NULL || list->pHead == NULL)
	{
		/*phead and pTail as student first*/
		list->pHead = newStudent;
		list->pTail = newStudent;
	}/*if pHead as NULL*/
	else
	{
		/*set link newStudent to pHead*/
		newStudent->pNext = list->pHead;
		/*set newStudent as pHead*/
		list->pHead = newStudent;
	}/*if not pHeap as NULL*/
}

void insertBot(list_t* list, student_t* newStudent)
{
	list->size++;
	newStudent->id = list->size;
	if(list->pTail == NULL || list->pHead == NULL)
    {
    	/*phead and pTail as student first*/
        list->pHead=newStudent;
        list->pTail=newStudent;
    }/*if */
    else
    {
    	/*set link pTail to newStudent*/
        list->pTail->pNext = newStudent;
        /*set newStudent as pTail*/
        list->pTail=newStudent;
    }
}

void printList(list_t* list)
{
	uint8_t count = 0;
	/*initialization tempStudent*/
	student_t* tempStudent;
	printf("\nClass has %d student\n", list->size);
	/*Browse the link list*/
	for(tempStudent = list->pHead; tempStudent != NULL; tempStudent = tempStudent->pNext)
	{
		outputStudent(tempStudent);
	}
}

int main()
{
	list_t L;
	student_t *S;
	initList(&L);
	S = inputStudent();
	insertBot(&L,S);
	S = inputStudent();
	insertBot(&L,S);
	S = inputStudent();
	insertBot(&L,S);
	printList(&L);
	return 0;
}