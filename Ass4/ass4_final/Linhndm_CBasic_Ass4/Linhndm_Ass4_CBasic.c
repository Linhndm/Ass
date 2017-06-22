#include "linked_list.h"


/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/
/*!
 *Function : {void} printStudent()
 * @brief: Print Student List
 *
 * @param: pPrint - Poiter use for print student list
 *
 * @return: <none>.
 */
void printStudent();
/*!
 *Function : void inputNewStudent();
 * @brief <Enter new student from keyboard>
 *
 * @param name <none>.
 *
 * @return <none>.
 */
void inputNewStudent();
/*!
 *Function : void checkAddStudent();
 * @brief <Check process of Add New Student>
 *
 * @param name <none>.
 *
 * @return <none>.
 */
void checkAddStudent();
/*!
 *Function : {void} insertTopStudent(const char* name, int lenName, int mark)
 * @brief <Insert new student to top of the Student List>
 *
 * @param: name<Student's name>
 * @param: lenName<lengh of student's name, max is define by MAX_NAME>.
 * @param: mark<Student's mark>
 *
 * @return: <none>.
 */

void insertTopStudent(const char* name, int lenName, int mark);
/*!
 *Function : void insertBotStudent(const char* name, int lenName, int mark)
 * @brief <Insert new student to bottom of the Student List>
 *
 * @param: name<Student's name>
 * @param: lenName<lengh of student's name, max is define by MAX_NAME>.
 * @param: mark<Student's mark>
 *
 * @return: <none>.
 */
void insertBotStudent(const char* name, int lenName, int mark);
/*!
 *Function : student_t* findMarkStudent(int mark)
 * @brief <Find student's mark from the Student List>
 *
 * @param mark <Student's mark>.
 *
 * @return <none>.
 */
student_t* findMarkStudent(int mark);
/*!
 *Function : student_t* findNameStudent(const char* name)
 * @brief <Find student's name from the Student List>
 *
 * @param name <Student's name>.
 *
 * @return <NULL>.
 */
student_t* findNameStudent(const char* name);
/*!
 *Function : student_t* findIDStudent(int ID)
 * @brief <Find student's ID from the Student List>
 *
 * @param name <Student's name>.
 *
 * @return <NULL>.
 */
student_t* findIDStudent(int ID);
/*!
 *Function : void checkFindStudent();
 * @brief <Check and select other function Find student's from the Student List>
 *  
 * @param name <None>.
 *
 * @return <none>.
 */
void checkFindStudent();
/*!
 *Function : removeNameStudent(const char* name)
 * @brief <remove student's name from the Student List>
 *
 * @param name <Student's name>.
 *
 * @return <NULL>.
 */
void removeNameStudent(const char* name);
/*!
 *Function : removeMarkStudent(int mark)
 * @brief <remove student's name from the Student List>
 *
 * @param mark<Student's mark>.
 *
 * @return <NULL>.
 */
void removeMarkStudent(int mark);
/*!
 *Function : int removeIDStudent(int ID);
 * @brief <remove student's ID from the Student List>
 *
 * @param ID<Student's ID>.
 *
 * @return <TRUE or FALSE>.
 */
int removeIDStudent(int ID);
/*!
 *Function : void checkRemoveStudent();
 * @brief <Check and select other function remove student's from the Student List>
 *  
 * @param name <None>.
 *
 * @return <none>.
 */
void checkRemoveStudent();

/***********************************************************************************************************************
 *  CODE
 **********************************************************************************************************************/

/*main*/
int main()
{
    char selectMain[MAX_TYPE];

    /*Select funciton for Student List*/
    while(1)
    {
        printf("\n\nSelect a function:");
        printf("\n1 - Add new Student");
        printf("\n2 - Find Student");
        printf("\n3 - Remove Student");
        printf("\n4 - Print Student List");
        printf("\n5 - Close Program");
        printf("\n-- ");
        gets(selectMain);
        /*Use add new student*/
        if(strcmp(selectMain,"1") == 0)
        {
            checkAddStudent();
        }
        /*Use find student*/
        if(strcmp(selectMain,"2") == 0)
        {
            checkFindStudent();
        }
        /*Use remove student*/
        if(strcmp(selectMain,"3") == 0)
        {
            checkRemoveStudent();
        }
        /*Use print Student's list*/
        if(strcmp(selectMain,"4") == 0)
        {
            printStudent();
        }
        /*Use Close program*/
        if(strcmp(selectMain,"5") == 0)
        {
            return 0;
        }

    };
    return 0;
}

/*!
 *Function : {void} printStudent()
 * @brief: Print Student List
 *
 * @param: pPrint - Poiter use for print student list
 *
 * @return: <none>.
 */
void printStudent()
{   
    int i = 0;
    student_t* pPrint = pHead;
    printf("\n**************************************************************************************************");
    printf("\n                  ---STUDENT LIST---");
    printf("\n                     ____***____\n");
    while (pPrint != NULL)
    {
        printf("\nStudent %-3d:ID: %-3d\tName: %-40s\tMark: %-3d",++i, (pPrint->ID), (pPrint->name), (pPrint->mark));
        pPrint = pPrint->pNext;
    }
    printf("\n***************************************************************************************************");
}

/*!
 *Function : void inputNewStudent();
 * @brief <Enter new student from keyboard>
 *
 * @param name <none>.
 *
 * @return <none>.
 */
void inputNewStudent()
{
    /*Variables*/
    char name[MAX_NAME];
    int mark;
    int checkMark = 0;
    int ID;
    char type[MAX_TYPE];
    printf("\nNew student's name : ");
    fflush(stdin);
    gets(name);

    /*Check condition of Mark*/
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

    /*Select position to insert new student*/
    printf("\nSelect number for Position to insert: ");
    printf("\n 1 - insert to top linked list");
    printf("\n 2 - insert to bottom linked list \n ");
    printf("\n-- ");
    fflush(stdin);
    gets(type);
    /*insert to top*/
    if(strcmp(type,"1") == 0)
    {
        insertTopStudent(name,MAX_NAME,mark);
    }
    /*insert to bottom*/
    else if(strcmp(type,"2") == 0)
    {
        insertBotStudent(name,MAX_NAME,mark);
    }
}

/*!
 *Function : void checkAddStudent();
 * @brief <Check process of Add New Student>
 *
 * @param name <none>.
 *
 * @return <none>.
 */
void checkAddStudent()
{
    /*Variables*/
    int checkQuitInput = 0;
    char selectQuitInput[QUIT_INPUT];

    /*Check condition to add new student*/
    do
    {
        /*Use function*/
        inputNewStudent();
        printStudent();

        /*Select quit or continue*/
        printf("\n\nYou want to add new student???\nSelect number: \n1 - Yes\n2 - No\n-- ");
        gets(selectQuitInput);
        if(strcmp(selectQuitInput,"1") == 0)
        {   
            /*Close if class full*/
            if(g_count > FULL_STUDENT)
            {
                printf("\nClass have been full");
                checkQuitInput = 1;
            }
        }
        /*Close*/
        else if(strcmp(selectQuitInput,"2") == 0)
        {
            checkQuitInput = 1;
        }
    }

    while(checkQuitInput == 0);
}
/*!
 *Function : {void} insertTopStudent(const char* name, int lenName, int mark)
 * @brief <Insert new student to top of the Student List>
 *
 * @param: name<Student's name>
 * @param: lenName<lengh of student's name, max is define by MAX_NAME>.
 * @param: mark<Student's mark>
 *
 * @return: <none>.
 */
void insertTopStudent(const char* name, int lenName, int mark)
{

    /*Dynamic memory allocation*/
    student_t *newStudent =(student_t*)malloc(sizeof(student_t));

    /*Use linked list*/
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

    /*count number student*/
    g_count++;
    /*Render auto Student's ID*/
    newStudent -> ID = g_countAdd++;
}

void insertBotStudent(const char* name, int lenName, int mark)
{
    /*Dynamic memory allocation*/
    student_t *newStudent = (student_t*)malloc(sizeof(student_t));

    /*Use linked list*/
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

    /*count number student*/
    g_count++;
    /*Render auto Student's ID*/
    newStudent -> ID = g_countAdd++;
}

/*!
 *Function : student_t* findNameStudent(const char* name)
 * @brief <Find student's name from the Student List>
 *
 * @param name <Student's name>.
 *
 * @return <NULL>.
 */
student_t* findNameStudent(const char* name)
{   
    student_t *pFindN = pHead;
    printf("\n**************************************************************************************************\n");
    while (pFindN != NULL)
    {
        if(strcmp(pFindN-> name, name) == 0)
        {   
            printf("\nMark of Student have a Name %s", name);
            printf("\n ID: %-3d\tName: %-40s Mark: %-3d\n",(pFindN->ID), (pFindN->name), (pFindN->mark));
        }
            pFindN = pFindN -> pNext;

    }
    printf("\n**************************************************************************************************\n");
    return NULL;
}

/*!
 *Function : student_t* findMarkStudent(int mark)
 * @brief <Find student's mark from the Student List>
 *
 * @param mark <Student's mark>.
 *
 * @return <none>.
 */
student_t* findMarkStudent(int mark)
{   
    int flag = 0;
    student_t *pFindM = pHead;
    printf("\n**************************************************************************************************\n");
    while (pFindM != NULL)
    {
        if(( pFindM -> mark ) == mark)
        {   
            printf("\nName of Student have a Mark %d", mark);
            printf("\n ID: %-3d\tName: %-40s Mark: %-3d\n",(pFindM->ID), (pFindM->name), (pFindM->mark));
        }
            pFindM = pFindM -> pNext;
    }
    printf("\n**************************************************************************************************\n");
    return NULL;
}

/*!
 *Function : student_t* findIDStudent(int ID)
 * @brief <Find student's ID from the Student List>
 *
 * @param name <Student's name>.
 *
 * @return <NULL>.
 */
student_t* findIDStudent(int ID)
{
    student_t* pFindID = pHead;
    printf("\n**************************************************************************************************\n");
    while (pFindID != NULL)
    {
        if(( pFindID -> ID ) == ID)
        {   
            printf("\nName of Student have a ID %d", ID);
            printf("\n ID: %-3d\tName: %-40s Mark: %-3d\n",(pFindID->ID), (pFindID->name), (pFindID->mark));
            return pFindID;
        }
        else
        {
            pFindID = pFindID -> pNext;
        }
    }
    printf("\n**************************************************************************************************\n");
    return NULL;
}

/*!
 *Function : void checkFindStudent();
 * @brief <Check and select other function Find student's from the Student List>
 *  
 * @param name <None>.
 *
 * @return <none>.
 */
void checkFindStudent()
{
    /*Variable*/
    char selectFind[MAX_TYPE];
    int checkQuitFind = 0;
    char selectQuitFind[MAX_TYPE];
    char name[MAX_NAME];
    int mark;
    int ID;

    /*Select other function Find student's from the Student List*/
    do
    {
        printf("\nSelect number to Find Student from Student List");
        printf("\n 1 - Find by name Student");
        printf("\n 2 - Find by mark Student ");
        printf("\n 3 - Find by ID Student \n ");
        printf("\n-- ");
        gets(selectFind);
        /*Find by name*/
        if(strcmp(selectFind,"1") == 0)
        {
            printf("\nEnter name of Student: ");
            fflush(stdin);
            gets(name);
            findNameStudent(name);
        }
        /*Find by mark*/
        else if(strcmp(selectFind,"2") == 0)
        {
            printf("\nEnter mark of Student: ");
            scanf("%d",&mark);
            findMarkStudent(mark);
        }

        /*Find by ID*/
        else if(strcmp(selectFind,"3") == 0)
        {
            printf("\nEnter ID of Student: ");
            scanf("%d",&ID);
            findIDStudent(ID);
        }

        /*Select continue or quit*/
        printf("\nYou want to continute??? \nSelect number: \n1 - Yes\n2 - No\n --  ");
        gets(selectQuitFind);

        /*Continue*/
        if(strcmp(selectQuitFind,"1") == 0)
        {
        }
        /*Quit*/
        else if(strcmp(selectQuitFind,"2") == 0)
        {
            checkQuitFind= 1;
        }
    }
    while(checkQuitFind == 0);
}

/*!
 *Function : removeNameStudent(const char* name)
 * @brief <remove student's name from the Student List>
 *
 * @param name <Student's name>.
 *
 * @return <NULL>.
 */
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

    /*count number student*/
    g_count--;
}

/*!
 *Function : removeMarkStudent(int mark)
 * @brief <remove student's name from the Student List>
 *
 * @param mark<Student's mark>.
 *
 * @return <NULL>.
 */
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

    /*count number student*/
    g_count--;
}

/*!
 *Function : int removeIDStudent(int ID);
 * @brief <remove student's ID from the Student List>
 *
 * @param ID<Student's ID>.
 *
 * @return <TRUE or FALSE>.
 */
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
    }   printf("\nNot found !!!\n");

    /*count number student*/
    g_count--;
    //free(pTemp);
    return 0;

}

/*!
 *Function : void checkRemoveStudent();
 * @brief <Check and select other function remove student's from the Student List>
 *  
 * @param name <None>.
 *
 * @return <none>.
 */
void checkRemoveStudent()
{   
    /*Variable*/
    char selectRemove[MAX_TYPE];
    int checkQuitRemove = 0;
    char selectQuitRemove[MAX_TYPE];
    char name[MAX_NAME];
    int mark;
    int ID;

    /*Select other function remove student's*/
    do
    {
        printf("\nSelect number to remove Student from Student List");
        printf("\n 1 - Remove by name Student");
        printf("\n 2 - Remove by mark Student ");
        printf("\n 3 - Remove by ID Student \n ");
        gets(selectRemove);
        /*Remove by name Student*/
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
        /*Remove by mark Student*/
        else if(strcmp(selectRemove,"2") == 0)
        {
            printf("\nEnter mark of Student: ");
            scanf("%d",&mark);
            findMarkStudent(mark);
            printf("\nEnter ID student's you want to remove: ");
            scanf("%d", &ID);
            removeIDStudent(ID);
        }
        /*Remove by ID Student*/
        else if(strcmp(selectRemove,"3") == 0)
        {
            printf("\nEnter ID of Student: ");
            scanf("%d",&ID);
            removeIDStudent(ID);
        }
        printStudent();

        /*Continue or quit function*/
        printf("\nYou want to continue remove student???\nSelect number: \n1 - Yes\n2 - No\n --  ");
        fflush(stdin);
        gets(selectQuitRemove);

        /*Continue*/
        if(strcmp(selectQuitRemove,"1") == 0)
        {   
            /*Close If Class havenot students */
            if(g_count == 0)
            {
                printf("\nClass havenot students");
                checkQuitRemove = 1;
            }
        }
        /*Close */
        else if(strcmp(selectQuitRemove,"2") == 0)
        {
            checkQuitRemove = 1;
        }
    }
    while(checkQuitRemove == 0);
}



