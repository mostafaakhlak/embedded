/*************************************************************************************
    Project Name:School Management System
    Author: Mostafa Akhlak Mohamed
    Date  : 1/6/2022
**************************************************************************************/


#include"HEADER.h"
int main()
{
    char cont;//This variable determines if the user wants to continue using the system after every activity or not
    Student S; //Student account contains his information
    List L1;  //Student list
    CreatList(&L1);//to create a list of students
    int choice; //Activity number which user wants to access

there:
    MAIN_MENU();//Introduction window
    printf("Activity number:");
    fflush(stdin);
    scanf("%d",&choice);
    if(!(choice<=7 && choice>0))
    {
        printf("Wrong choice \nPlease enter a new activity number \n");
        goto there;
    }
    switch(choice)//switch case to access the user desired activity
    {             //(1:New student,2:Delete student,3:Student list,4:Edit student,5:Rank student,6:Student score,7:Exit)
    case 1://New student window
        for(int i=0;i<120;i++)
            printf("*");
        NEW_STUDENT(&S,&L1);//creates anew student account
        for(int i=0;i<120;i++)
            printf("*");
        printf("New student data:\n\n");
        printf("\t\t");
        printf("ID=%d\n\n",S.ID);
        printf("\t\t");
        printf("Name:");
        puts(&S.StudentName);
        printf("\t\t");
        printf("Date of birth:(%d/%d/%d)\n\n",S.Birthday.Day,S.Birthday.Month,S.Birthday.Year);
        printf("\t\t");
        printf("Phone number:");
        puts(&S.PhoneNum);
        printf("\t\t");
        printf("Gender:%c\n\n",S.Gender);
        printf("\t\t");
        printf("Grade:%d\n\n",S.Grade);
        for(int i=0;i<120;i++)
            printf("*");
        fflush(stdin);
        printf("Press 'y' to go to main menu or another key to exit\n");
        scanf("%c",&cont);
        if (cont=='y')//checks if user wants to go to main menu
            goto there;
        for(int i=0;i<120;i++)
            printf("*");
        break;
    case 2://Delete student
        for(int i=0;i<120;i++)
            printf("*");
        int id;
        char rtrn=0;    //rtrn is used to store the return of the function(0:if the id is not found,1:if the id is found,2:if the list is empty)
    recase:
        fflush(stdin);
        printf("Please enter an ID:");
        scanf("%d",&id);
        if (id=='e') break;//checks if user wants to exit or not
        rtrn=DELETE_STUDENT(id,&L1);//Deletes student account
        if(rtrn==0)//if the desired id is not found
        {
        fflush(stdin);
        printf("ID not found \npress 'y' to go to main menu or another key to continue\n");
        scanf("%c",&cont);
        if(cont=='y')//checks if user wants to go to main menu
            goto there;
        else
            goto recase;
        }
        else if(rtrn==1)printf("Student has been deleted successfully\n");
        else printf("List is empty\n");
        fflush(stdin);
        printf("Press 'y' to go to main menu or another key to exit\n");
        scanf("%c",&cont);
        if (cont=='y')
            goto there;
        else
        {
            for(int i=0;i<120;i++)
                printf("*");
            break;
        }
    case 3://student list
        for(int i=0;i<120;i++)
            printf("*");
        if(ListEmpty(&L1))
        {
            fflush(stdin);
            printf("There is no students in the list\n");
            printf("Press 'y' to main menu or another key to exit\n");
            scanf("%c",&cont);
            if (cont=='y')
                goto there;
            else
                break;
        }
        else
        {
        STUDENT_LIST(&L1);//displays the whole list
        for(int i=0;i<120;i++)
            printf("*");
        printf("Students has been ordered alphabetically\n");
        for(int i=0;i<120;i++)
            printf("*");
        fflush(stdin);
        printf("Press 'y' to go to main menu or another key to exit\n");
        scanf("%c",&cont);
        if (cont=='y')
            goto there;
        else
        {
            for(int i=0;i<120;i++)
                printf("*");
            break;
        }
        }
    case 4://student edit window
        for(int i=0;i<120;i++)
            printf("*");
        int ID;
        char Rtrn=0;    //rtrn is used to store the return of the function(0:if the id is not found,1:if the id is found,2:if the list is empty)
    Recase:
        fflush(stdin);
        printf("Please enter ID of the student you want to edit\n");
        scanf("%d",&ID);
        if (id=='e') break;
        Rtrn=STUDENT_EDIT(ID,&S,&L1);//Edits certain student account
        if(Rtrn==0)
        {
        fflush(stdin);
        printf("ID not found \npress 'y' to go to main menu or another key to continue\n");
        scanf("%c",&cont);
        if(cont=='y')
            goto there;
        else
            goto Recase;
        }
        else if(Rtrn==1)printf("Student has been edited successfully\n");
        else printf("List is empty\n");
        fflush(stdin);
        printf("Press 'y' to go to main menu or another key to exit\n");
        scanf("%c",&cont);
        if (cont=='y')
            goto there;
        else
        {
            for(int i=0;i<120;i++)
                printf("*");
            break;
        }
    case 5://Rank student window
        for(int i=0;i<120;i++)
            printf("*");
        if(ListEmpty(&L1))
        {
            fflush(stdin);
            printf("There is no students in the list\n");
            printf("Press 'y' to go to main menu or another key to exit\n");
            scanf("%c",&cont);
            if (cont=='y')
                goto there;
            else
                break;
        }
        else
        {
        RANK_STUDENT(&L1);//sorts the students according to their grades
        for(int i=0;i<120;i++)
            printf("*");
        printf("Students has been ordered according to their grades\n");
        for(int i=0;i<120;i++)
            printf("*");
        fflush(stdin);
        printf("Press 'y' to go to main menu or another key to exit\n");
        scanf("%c",&cont);
        if (cont=='y')
            goto there;
        else
        {
            for(int i=0;i<120;i++)
                printf("*");
            break;
        }
        }
    case 6://STUDENT_SCORE
        for(int i=0;i<120;i++)
            printf("*");
        if(ListEmpty(&L1))
        {
            fflush(stdin);
            printf("There is no students in the list\n");
            printf("Press 'y' to go to main menu or another key to exit\n");
            scanf("%c",&cont);
            if (cont=='y')
                goto there;
            else
                break;
        }
        else
        {
        STUDENT_SCORE(&L1);//user will enter students scores
        fflush(stdin);
        printf("Press 'y' to go to main menu or another key to exit\n");
        scanf("%c",&cont);
        if (cont=='y')
            goto there;
        else
        {
            for(int i=0;i<120;i++)
                printf("*");
            break;
        }
        }
        break;
    case 7://Exit window
        printf("\n");
        for(int i=0;i<120;i++)
            printf("*");
        printf("\n");
        printf("*********************************   Thank you for using School Management System   *************************************\n");
        for(int i=0;i<120;i++)
            printf("*");
        break;
    default:
        for(int i=0;i<120;i++)
        printf("*");
        printf("Invalid chice");
        for(int i=0;i<120;i++)
        printf("*");
        break;
    }
    return 0;
}
