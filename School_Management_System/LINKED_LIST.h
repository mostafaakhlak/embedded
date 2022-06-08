#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

//libraries definitions.....................
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//macros definitions and data types........................
typedef struct date{
    int Day;
    int Month;
    int Year;
}Date;

typedef struct student{
    char StudentName[50];
    int ID,Grade;
    char Gender;
    Date Birthday;
    char PhoneNum[13];
}Student;

#define  ListEntry Student

typedef struct listnode{
    ListEntry entry;
    struct listnode *next;
}ListNode;

typedef struct list{
    ListNode*head;
    int size;
}List;


//functions prototypes......................
void CreatList (List *);
char ListEmpty (List*);
char ListFull (List *);
int ListSize (List*);
void DestroyList (List*);
char InsertList (ListEntry*,int,List*);
void DeleteList(int,List*);
void RetrieveList(ListEntry*,int,List*);
void ReplaceList(ListEntry*,int,List*);
void Assign(ListEntry*,ListNode*);
void Extract(ListEntry*,ListNode*);
void Sort(List*,char);

#endif // LINKED_LIST_H_INCLUDED
