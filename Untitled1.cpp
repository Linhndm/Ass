#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 * Variables
 ******************************************************************************/

struct student
{
	int mark;
	char name[50];
	int order;
	int order_inlist;
	struct student *pNext;
};
typedef struct student student_t;


student_t *pHead=NULL;
student_t *pTail=NULL;
int g_order=0;

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief <Print student list>
 *
 * @return <none>.
 */
void Print_list();

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief <Insert new student to top of the List>
 *
 * @param name <Student's name>.
 * @param lenName <lengh of student's name, max is 50 characters>.
 *
 * @return <none>.
 */
void insertTopStudent(const char* name,int lenName,int mark);

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
/*!
 * @brief <Insert new student to bottom of the List>
 *
 * @param name <Student's name>.
 * @param lenName <lengh of student's name, max is 50 characters>.
 *
 * @return <none>.
 */
void insertBotStudent(const char* name,int lenName,int mark);

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
/*!
 * @brief <Search member in list by name, mark or input order>
 *
 * @parma mode <1: Search by name
				2: Search by mark
				3: Search by input order
 * @param name <Name to search>.
 * @param mark <Mark to search>.
 * @param order <Input order to search>.
 *
 * @return <none>.
 */
void filter(char mode,char* name,int mark,char order);

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief <Enter new student's specification>
 *
 * @return <none>.
 */
void enter_new();

/*******************************************************************************
 * Code
 ******************************************************************************/
int main()
{
	char k=0;
	printf("\nPress anykey to insert new student....");
	getch();
	do
	{
		enter_new();		
		printf("\n Press SPACE if you want to show the list...\nPress S to search in list or ESC to QUIT\n");
		k=getch();
		if(k==32)
		{
			printf("\n\n************************************************\n");
			printf("****              STUDENT LIST             *****");
			printf("\n************************************************\n");
			Print_list();
			printf("\n\n************************************************\n\n");	
		}
		else if(k==115)
		{
			char m,name[50];
			int mark=0;
			int order=0;
			printf("\nSearch mode:\n1 : name\n2 : mark\n3 : input order\nYour mode:");
			scanf("%d",&m);
			switch(m)
			{
				case 1:
					{
						printf("\nSearch by name : ");
						fflush(stdin);
						gets(name);
						break;
					}
				case 2:
					{
						printf("\nSearch by mark : ");
						scanf("%d",&mark);
						break;
					}
				case 3:
					{
						printf("\nSearch by input order : ");
						scanf("%d",&order);			
						break;			
					}
			}
			filter(m,name,mark,order);			
		}
	}
	while(k!=27);	
}

void enter_new()
{
	char name[50],type[3];
	int mark;
	printf("\nNew student's name : ");
	fflush(stdin);
	gets(name);
	printf("Mark: ");
	scanf("%d",&mark);
	printf("\nPosition to insert: ");
	fflush(stdin);
	gets(type);
	if(strcmp(type,"bot"))
	{
		insertTopStudent(name,50,mark);
	}
	else
	{
		insertBotStudent(name,50,mark);
	}
}

void insertTopStudent(const char* name,int lenName,int mark)
{
	int i;
	student_t *newstudent= (student_t*)malloc(sizeof(student_t));
	//memset(newstudent->name,0,50);
	newstudent->pNext=NULL;
	newstudent->order=++g_order;
	for(i=0;i<lenName;i++)
	{
		newstudent->name[i]=name[i];
	}
	newstudent->mark=mark;
	if(pHead==NULL)
	{
		pHead=newstudent;
		pTail=newstudent;
	}
	else
	{
		newstudent->pNext=pHead;
		pHead=newstudent;
	}
}

void insertBotStudent(const char* name,int lenName,int mark)
{
	int i;
	student_t *newstudent= (student_t*)malloc(sizeof(student_t));
	
	//memset(newstudent->name,0,50);
	newstudent->pNext=NULL;
	newstudent->order=++g_order;
	
	for(i=0;i<lenName;i++)
	{
		newstudent->name[i]=name[i];
	}
	newstudent->mark=mark;
	if(pTail==NULL)
	{
		pHead=newstudent;
		pTail=newstudent;
	}
	else
	{
		pTail->pNext=newstudent;
		pTail=newstudent;
	}
}

void Print_list()
{	
	int i=1;
	student_t* temp;
	temp=pHead;
	while(temp!=NULL)
	{
		printf("\nStudent %d : Order number %d	%s	Mark: %d",i++,(temp->order),(temp->name),(temp->mark));
		//order_inlist=i;
		temp=temp->pNext;
	}
	
}

void filter(char mode,char* name,int mark,char order)
{
	student_t* temp;
	temp=pHead;
	printf("\n\n************************************************\n");
	switch(mode)
	{
		case 1:
			{
				while(temp!=NULL)
				{
					if(strcmp(temp->name,name)==0)
					{
						printf("\nOrder number %d	%s	Mark: %d",(temp->order),(temp->name),(temp->mark));
					}
					temp=temp->pNext;
				}
				break;
			}
		case 2:
			{
				while(temp!=NULL)
				{
					if((temp->mark)==mark)
					{
						printf("\nOrder number %d	%s	Mark: %d",(temp->order),(temp->name),(temp->mark));
					}
					temp=temp->pNext;
				}
				break;
			}
		case 3:
			{
				while(temp!=NULL)
				{
					if((temp->order)==order)
					{
						printf("\nOrder number %d	%s	Mark: %d",(temp->order),(temp->name),(temp->mark));
					}
					temp=temp->pNext;
				}
				break;
			}
	}
				printf("\n************************************************\n\n");
}



