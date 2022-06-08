#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


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

void MAIN_MENU(void);
void NEW_STUDENT(ListEntry*,List*);
char DELETE_STUDENT(int ,List*);
void STUDENT_LIST(List*);
char STUDENT_EDIT(int,ListEntry*,List*);
void RANK_STUDENT(List*);
void STUDENT_SCORE(List*);

#endif // HEADER_H_INCLUDED
