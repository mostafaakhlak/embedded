#include"LINKED_LIST.h"

/*.............................................................
    Function name:CreatList
    Function definition:Creates a linked list memory
    Arguments:The List address
    Return Type:void
...............................................................*/
void CreatList (List *Pl)
{
    Pl->head=NULL;
    Pl->size=0;
}

/*.............................................................
    Function name:InsertList
    Function definition:Takes a value(E) and puts it in a certain position
    Arguments:(ListEntry data type,int ,The List address)
    Return Type:char
    Pre: The list is initialized and not full and there is a space in memory
    Post:The element E has been stored in a certain position in the list; and E does not change

...............................................................*/


char InsertList(ListEntry *Ps,int Pos,List*Pl)
{
    ListNode*temp;//temp pointer to loop all over the list
    int i;
    ListNode*P=(ListNode*)malloc(sizeof(ListNode));//new node creation
    if (P)
    {
        Assign(Ps,P);
        P->next=NULL;
        if(Pos==0)
        {
            P->next=Pl->head;
            Pl->head=P;
        }
        else
        {

            for(temp=Pl->head,i=0;i<Pos-1;i++)
                temp=temp->next;
            P->next=temp->next;
            temp->next=P;
        }
        Pl->size++;
        return 1;
    }
    else return 0;
}
/*.............................................................
    Function name:DeleteList
    Function definition:Deletes a certain node in the list.
    Arguments:(int,The List address)
    Return Type:void
    Pre: The List is initialized and not empty
    Post:The element of position (Pos)  has been deleted

...............................................................*/
void DeleteList(int pos,List*Pl)
{
    ListNode *temp,*q;//temp pointers to loop all over the list
    int i;
    if(pos == 0)
    {
        temp=Pl->head;
        Pl->head=Pl->head->next;
        free(temp);
    }
    else
    {
        for( q=Pl->head, i=0;i<pos-1;i++)
            q=q->next;
        temp=q->next->next;
        free(q->next);
        q->next=temp;
    }
    Pl->size--;
}

/*.............................................................
    Function name:DestroyList
    Function definition:clears the whole list
    Arguments:The list address
    Return Type:void
    Pre: List is initialized.
    Post: destroy all elements; list looks initialized.

...............................................................*/
void DestroyList (List*Pl)
{
    ListNode*Pn=Pl->head;
    while(Pl->head)
    {
        Pl->head=Pl->head->next;
        free(Pn);
        Pn=Pl->head;
    }
    Pl->size=0;
}
/*.............................................................
    Function name:ListEmpty
    Function definition:Checks if the List is empty or not
    Arguments:The List address
    Return Type:char(0 (if the list is not empty)  or 1(if the list is empty))
...............................................................*/
char ListEmpty (List*Pl)
{
    return (Pl->size==0);
}
/*.............................................................
    Function name:ListFull
    Function definition:Checks if the list is full or not
    Arguments:The list address
    Return Type:char(0 (if the list is not full)  or 1(if the list is full))
...............................................................*/
char ListFull (List*Pl)
{
    return 0;
}
/*.............................................................
    Function name:ListSize
    Function definition:it returns the number of values in the List
    Arguments:The list address
    Return Type:int
    Pre: List is initialized.
    Post: returns how many elements exist.

...............................................................*/
int ListSize (List*Pl)
{
    return Pl->size;
}
/*.............................................................
    Function name:RetrieveList
    Function definition:Takes a certain value from the list and puts it in a variable (without deleting the node)
    Arguments:(address of variable of type ListEntry,int,The List address)
    Return Type:void
    Pre: The List is initialized and not empty
    Post:The element of position (Pos)  is returned
...............................................................*/
void RetrieveList(ListEntry*Pe,int pos,List*Pl)
{
    List*temp= Pl->head;
    for(int i=0;i<pos;i++)
        temp=temp->head->next;
    Extract(Pe,temp);
}
/*...................................................................................................
Function name:ReplaceList
    Function definition:Takes a value(E) and puts it in a certain node
    Arguments:(ListEntry data type,int ,The List address)
    Return Type:void
    Pre: The list is initialized and not full and there is a space in memory
    Post:The element E has been stored in a certain position in the list; and E does not change
...................................................................................................*/
void ReplaceList(ListEntry *Ps,int pos,List*Pl)
{
    ListNode*temp= Pl->head;
    for(int i=0;i<pos;i++)
        temp=temp->next;
    Assign(Ps,temp);
}
/*...................................................................................................
Function name:Assign
    Function definition:Assigns the values of a struct to another struct
    Arguments:( address of data type ListEntry ,address of data type ListNode)
    Return Type:void
    Pre: The list is initialized and not full and there is a space in memory
    Post:none
...................................................................................................*/

void Assign(ListEntry*Ps,ListNode*P)
{
    P->entry.Gender=Ps->Gender;
    P->entry.Grade=Ps->Grade;
    P->entry.ID=Ps->ID;
    for(int i=0;i<13;i++)
        P->entry.PhoneNum[i]=Ps->PhoneNum[i];
    for(int i=0;i<50;i++)
        P->entry.StudentName[i]=Ps->StudentName[i];
    P->entry.Birthday.Day=Ps->Birthday.Day;
    P->entry.Birthday.Month=Ps->Birthday.Month;
    P->entry.Birthday.Year=Ps->Birthday.Year;
}
/*...................................................................................................
Function name:Extract
    Function definition:Extracts the values of a struct and put them in another struct
    Arguments:( address of data type Student ,address of data type ListNode)
    Return Type:void
    Pre: The list is initialized and not full and there is a space in memory
    Post:none
...................................................................................................*/

void Extract(ListEntry*Ps,ListNode*P)
{
    Ps->Gender=P->entry.Gender;
    Ps->Grade=P->entry.Grade;
    Ps->ID=P->entry.ID;
    for(int i=0;i<13;i++)
        Ps->PhoneNum[i]=P->entry.PhoneNum[i];
    for(int i=0;i<50;i++)
        Ps->StudentName[i]=P->entry.StudentName[i];
    Ps->Birthday.Day=P->entry.Birthday.Day;
    Ps->Birthday.Month=P->entry.Birthday.Month;
    Ps->Birthday.Year=P->entry.Birthday.Year;
}
/*...................................................................................................
Function name:Sort
    Function definition:this function sorts the list of students
                        alphabetically ascending or according to their grades.
    Arguments:(address of data type List,char (1:to sort alphabetically,2:to sort by grade))
    Return Type:void
    Pre: The list is initialized and not full and there is a space in memory
    Post:The list is ordered alphabetically ascending or according to grades.
...................................................................................................*/
void Sort(List*Pl,char c)
{
    ListNode*temp=Pl->head;//temp pointer to loop all over the list
    ListNode*node=(ListNode*)malloc(sizeof(ListNode));//temp node to store the data
    switch(c)
    {
        case 1:
                for(int i=0;i<(Pl->size-1);i++)//External loop is used for resorting the list (size-1) times to ensure all elements are in order
            {
                while(temp->next)//internal loop is used for walking through all elements
            {
                if(strcmp(&temp->entry.StudentName[0],&temp->next->entry.StudentName[0])>0)//comparing with the first character of an element and the next one
                {
                    Assign(&temp->entry,node);
                    Assign(&temp->next->entry,temp);
                    Assign(&node->entry,temp->next);
                    temp=temp->next;
                }
                else
                    temp=temp->next;

            }
            }
            break;
        case 2:
            for(int i=0;i<(Pl->size-1);i++)//External loop is used for resorting the list (size-1) times to ensure all elements are in order
            {
                while(temp->next)//internal loop is used for walking through all elements
            {
                if(temp->entry.Grade < temp->next->entry.Grade)//comparing with the first character of an element and the next one
                {
                    Assign(&temp->entry,node);
                    Assign(&temp->next->entry,temp);
                    Assign(&node->entry,temp->next);
                    temp=temp->next;
                }
                else
                    temp=temp->next;
            }
            }
            break;
    }
}
//******************************************************************************************************************************************
//End of Linked List functions
//*******************************************************************************************************************************************
