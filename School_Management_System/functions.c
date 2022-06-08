#include"HEADER.h"

/*...................................................................................................
    Function name:MAIN_MENU
    Function definition:this function displays the welcome screen and targeted activates.
    Arguments:void
    Return Type:void
    Pre:No precondition
    Post:none
......................................................................................................*/

void MAIN_MENU(void)
{
    int i;
    for(i=0;i<120;i++)
        printf("*");
    printf("*\t\t\t\t\tWelcome to School Management System\t\t\t\t\t       *");
     printf("* List of activities:- \t\t\t\t\t\t\t\t\t\t\t\t       *");
    printf("*\t\t\t(1)New student\t(2)Delete student\t(3)Student list\t\t\t\t\t       *");
    printf("*\t\t\t(4)Student edit\t(5)Rank student\t\t(6)Student score\t\t(7)Exit\t\t       *");
    printf("* Please choose the activity: \t\t\t\t\t\t\t\t\t\t\t       *");
    for(i=0;i<120;i++)
        printf("*");
}
/*...................................................................................................
    Function name:NEW_STUDENT
    Function definition:this function creates a new student account.
                        it asks about details of the student such as name, date of birth, ID, address
                         and phone number.
    Arguments:(address of struct of type ListaEntry,address of the list)
    Return Type:void
    Pre:No precondition
    Post:none
......................................................................................................*/

void NEW_STUDENT(ListEntry*Ps,List*Pl)
{
    ListNode*temp=Pl->head;
NewID:
    fflush(stdin);
    printf("Please enter student Id:");
    scanf("%d",&Ps->ID);
    for(int i=0;i<Pl->size;i++)
    {
        if(Ps->ID==temp->entry.ID)
            {
            printf("id is repeated\n");
            goto NewID;
            }
        else
            temp=temp->next;
    }
    printf("Please enter student name:");
    fflush(stdin);
    fgets(&Ps->StudentName,50,stdin);
    printf("Please enter student phone number:");
    fflush(stdin);
    fgets(&Ps->PhoneNum,13,stdin);
    fflush(stdin);
    printf("Please enter student date of birth (dd/mm/yyyy):");
    scanf("%d/%d/%d",&Ps->Birthday.Day,&Ps->Birthday.Month,&Ps->Birthday.Year);
    printf("Please enter student grade in embedded course:");
    fflush(stdin);
    scanf("%d",&Ps->Grade);
    fflush(stdin);
    printf("Please enter student gender(f:for female students,m:for male students):");
    fgets(&Ps->Gender,2,stdin);
    fflush(stdin);
    InsertList(Ps,0,Pl);//creates a new student account
}

/*...................................................................................................
    Function name:DELETE_STUDENT
    Function definition:this function is for deleting a customer account using customer ID.
    Arguments:(int,address of the list)
    Return Type:char(0:if id is not found,1:if id is found,2:if list is empty)
    Pre:List exists and not empty
    Post:the wanted node will be deleted
......................................................................................................*/


char DELETE_STUDENT(int ID,List*Pl)
{
    if(!ListEmpty(Pl))//checks if there are students in the list or not
    {
    ListNode*temp=Pl->head;//temp pointer to loop all over the list
    for(int i=0;i<Pl->size;i++)
    {
            if(temp->entry.ID==ID)
            {
                DeleteList(i,Pl);//deletes the chosen account
                break;
            }
            else
                temp=temp->next;
    }
    if (!temp)//temp pointer reaches the last node and ID not found(temp=NULL)
        return 0;
    return 1;
    }
    else return 2;
}
/*...................................................................................................
    Function name:STUDENT_LIST
    Function definition:this function, you can view the students information such as
                        name, date of birth, ID, address and phone number in
                        table form(alphabetically ascending).
    Arguments:address of the list
    Return Type:void
    Pre:List is exists and not empty
    Post:Displays the whole list
......................................................................................................*/

void STUDENT_LIST(List*Pl)
{
    Sort(Pl,1);//Sorts the list alphabetically ascending
    ListNode*temp=Pl->head;//temp pointer to loop all over the list
    while(temp)//checks if temp reaches the last node or not
    {
        for(int i=0;i<120;i++)
            printf("*");
        printf("\t\t");
        printf("ID=%d\n\n",temp->entry.ID);
        printf("\t\t");
        printf("Name:");
        puts(&temp->entry.StudentName);
        printf("\t\t");
        printf("Date of birth:(%d/%d/%d)\n\n",temp->entry.Birthday.Day,temp->entry.Birthday.Month,temp->entry.Birthday.Year);
        printf("\t\t");
        printf("Phone number:");
        puts(&temp->entry.PhoneNum);
        printf("\t\t");
        printf("Gender:%c\n\n",temp->entry.Gender);
        printf("\t\t");
        printf("Grade:%d\n\n",temp->entry.Grade);
        for(int i=0;i<120;i++)
            printf("*");
        temp=temp->next;
    }
}
/*...................................................................................................
    Function name:STUDENT_EDIT
    Function definition:this function has been used for updating a particular student account.
    Arguments:(int,address of a ListEntry,address of the list)
    Return Type:char(0:if id is not found,1:if id is found,2:if list is empty)
    Pre:List is exists and not empty,ListEntry is exists
    Post:Wanted node will be edited
......................................................................................................*/
char STUDENT_EDIT(int ID,ListEntry*Ps,List*Pl)
{
    if(!ListEmpty(Pl))//checks if there are students in the list or not
    {
    ListNode*temp=Pl->head;//temp pointer to loop all over the list
    for(int i=0;i<Pl->size;i++)
    {
        if(temp->entry.ID==ID)//notice using fflush() function before any data in function to act proparly
        {
            fflush(stdin);
            printf("Please enter student new Id:");
            scanf("%d",&Ps->ID);
            printf("Please enter student new name:");
            fflush(stdin);
            fgets(&Ps->StudentName,50,stdin);
            printf("Please enter student new phone number:");
            fflush(stdin);
            fgets(&Ps->PhoneNum,13,stdin);
            fflush(stdin);
            printf("Please enter student new date of birth (dd/mm/yyyy):");
            scanf("%d/%d/%d",&Ps->Birthday.Day,&Ps->Birthday.Month,&Ps->Birthday.Year);
            printf("Please enter student new grade in embedded course:");
            fflush(stdin);
            scanf("%d",&Ps->Grade);
            fflush(stdin);
            printf("Please enter student new gender(f:for female students,m:for male students):");
            fgets(&Ps->Gender,2,stdin);
            fflush(stdin);
            ReplaceList(Ps,i,Pl);//Edits the account with new data
            break;
            }
            else
                temp=temp->next;
    }
    if (!temp)//temp pointer reaches the last node and ID not found(temp=NULL)
        return 0;
    return 1;
    }
    else return 2;
}

/*...................................................................................................
    Function name:RANK_STUDENT
    Function definition:this function can sort all students according to embedded course score.
    Arguments:(address of the list)
    Return Type:char(0:if id is not found,1:if id is found,2:if list is empty)
    Pre:List is exists and not empty,ListEntry is exists
    Post:Wanted node will be edited
......................................................................................................*/

void RANK_STUDENT(List*Pl)
{
    Sort(Pl,2);//Sorts the list according to students grades
    ListNode*temp=Pl->head;//temp pointer to loop all over the list
    while(temp)//checks if temp reaches the last node or not
    {
        for(int i=0;i<120;i++)
            printf("*");
        printf("\t\t");
        printf("ID=%d",temp->entry.ID);
        printf("\t");
        printf("Name:");
        puts(&temp->entry.StudentName);
        printf("\t");
        printf("Grade:%d\n\n",temp->entry.Grade);
        for(int i=0;i<120;i++)
            printf("*");
        temp=temp->next;
    }
}

/*...................................................................................................
    Function name:STUDENT_SCORE
    Function definition:this function can sort all students according to embedded course score.
    Arguments:(address of the list)
    Return Type:char(0:if id is not found,1:if id is found,2:if list is empty)
    Pre:List is exists and not empty,ListEntry is exists
    Post:Wanted node will be edited
......................................................................................................*/

void STUDENT_SCORE(List*Pl)
{
    ListNode*temp=Pl->head;//temp pointer to loop all over the list
    for(int i=0;i<Pl->size;i++)//notice using fflush() function before any data in function to act proparly
    {
        printf("Please enter student grade in embedded course:\n");
        printf("\t\tStudent ID:%d\n",temp->entry.ID);
        fflush(stdin);
        printf("\t\tStudent name:");
        puts(&temp->entry.StudentName);
        printf("\t\tGrade:");
        fflush(stdin);
        scanf("%d",&temp->entry.Grade);
        temp=temp->next;
    }
}
//**********************************************************************************************************************************
//End of functions
//**********************************************************************************************************************************
