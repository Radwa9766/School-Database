#include <stdio.h>
#include <stdlib.h>
#include "school.h"
void scan_studentName(char*name,int size)
{
    printf("\033[36m\tEnter Student Name-->");
    printf("\033[0m");
    printf("\033[32m");
    scan_name(name,size);
    printf("\033[0m");
}
void scan_studentPhone(char*phone,int size)
{
    printf("\033[36m\tEnter Student phone-->");
    printf("\033[0m");
    printf("\033[32m");
    scan_phone(phone,size);
    printf("\033[0m");
}
void scan_FatherName(char*name,int size)
{
    printf("\033[36m\tEnter father name-->");
    printf("\033[0m");
    printf("\033[32m");
    scan_name(name,size);
    printf("\033[0m");
}
void scan_FatherPhone(char*phone,int size)
{
    printf("\033[36m\tEnter father phone-->");
    printf("\033[0m");
    printf("\033[32m");
    scan_phone(phone,size);
    printf("\033[0m");
}
void scan_MotherName(char*name,int size)
{
    printf("\033[36m\tEnter mother name-->");
    printf("\033[0m");
    printf("\033[32m");
    scan_name(name,size);
    printf("\033[0m");
}
void scan_MotherPhone(char*phone,int size)
{
    printf("\033[36m\tEnter mother phone-->");
    printf("\033[0m");
    printf("\033[32m");
    scan_phone(phone,size);
    printf("\033[0m");
}
void scan_StudentGrade(int*pGrade)
{
    int flag=0;
    printf("\033[36m\tEdit Student Grade from 1:100-->");
    printf("\033[0m");

    while (flag==0)
    {
        printf("\033[32m");
        fflush(stdin);
        scanf("%d",pGrade);
        printf("\033[0m");
        if(*pGrade>100 || *pGrade<1)
        {
            printf("\033[31m\tWrong Input Please Enter a Grade 1:100\n");
            printf("\033[0m");
        }
        else
        {
            flag++;
        }
    }
}
