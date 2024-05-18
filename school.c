#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "school.h"

static FILE *data = NULLPTR;
static st_d school[CAPACITY]= {0};
static int current_size=0;
static sp=0;


void intduction (void)
{
    system("cls");
    printf("\n\n\n");
    printf("\033[36m\t\t\t\t\t\tHello in Embedded school\n\n\n");
    printf("\033[0m");
    printf("\033[33m\tPlease choose from The Following\n");
    usleep(1000000);
    printf("\033[0m");
    printf("\033[32m\t1-Add Student\n");
    usleep(1000000);
    printf("\033[32m\t2-Edit Student\n");
    usleep(1000000);
    printf("\033[32m\t3-Remove Student\n");
    usleep(1000000);
    printf("\033[32m\t4-Call father\n");
    usleep(1000000);
    printf("\033[32m\t5-Print All students in the school\n");
    printf("\033[0m");
    usleep(1000000);
    printf("\033[32m\t6-Exit\n");
    printf("\033[0m");
}

void add_student(void)
{
    int enter;
    system("cls");
    printf("\033[33m\n\n\n\t\t\t\t\t\tSTUDENT DATA\n\n");
    printf("\033[0m");
    if(current_size==CAPACITY)
    {
        printf("S\n");
        printf("\033[31m\tSorry,This Student Can't be added,The School is full\n");
        printf("\033[0m");
        fflush(stdin);
        scanf("%C",&enter);
        return;
    }
    else if(current_size<CAPACITY)
    {
        scan_studentName(school[sp].name,20);
        scan_studentPhone(school[sp].phone,11);
        school[sp].id=sp+1;
        scan_FatherName(school[sp].father.name,20);
        scan_FatherPhone(school[sp].father.phone,11);
        scan_MotherName(school[sp].mother.name,20);
        scan_MotherPhone(school[sp].mother.phone,11);
        printf("\033[36m\tThe Student ID is ",school[sp].id);
        printf("\033[0m");
        printf("\033[33m%d\n",school[sp].id);
        current_size++;
        sp++;
    }

}
int Edit_student(void)
{
    int choose,flag1=0,flag2=0,student=0,index=-1,edit=0,i=0,enter;
    if(sp==0)
    {
        system("cls");
        printf("\033[31m\n\n\n\n\t\t\t\tThere is no Students in The School to Edit\n");
        return;
    }

    while(flag1==0)
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[33m\t\t\t\t\t\ Edit student\n");
        printf("\tchoose from the following\n");
        printf("\033[32m\t1-Edit by Student Name\n");
        printf("\033[32m\t2-Edit by Student ID\n");
        fflush(stdin);
        scanf("%d",&choose);
        if(choose==1)
        {
            char name[20];
            system("cls");
            printf("\033[35m\n\n\tEnter student Name\n");
            printf("\033[0m");
            printf("\033[32m");
            scan_name(name,20);
            for(i=0; i<sp; i++)
            {
                if(string_comparenotsens(name,school[i].name)==1)
                {
                    student=1;
                    index=i;
                    flag1=1;
                }
            }
            if(student==0)
            {
                printf("\033[31m\tThis Name does not exist \n");
                printf("\033[31m\t Enter 0 to try again or Enter 1 to go back \n");
                fflush(stdin);
                scanf("%d",&flag1);
            }
        }
        else if(choose==2)
        {
            int id=-1;
            system("cls");
            printf("\033[35m\n\n\tEnter student ID\n");
            printf("\033[0m");
            printf("\033[32m");
            fflush(stdin);
            scanf("%d",&id);
            for(i=0; i<sp; i++)
            {
                if(id==school[id-1].id)
                {
                    student=1;
                    index=id-1;
                    flag1=1;
                }
            }
            if(student==0)
            {
                printf("\033[31m\tThis number does not exist \n");
                printf("\033[31m\t Enter 0 to try again or Enter 1 to go back \n");
                fflush(stdin);
                scanf("%d",&flag1);
            }
        }
        else
        {
            printf("\033[31m\tInvalid Input\n");
            printf("\tTo Try again Enter 0,To go Back Enter 1\n");
            fflush(stdin);
            scanf("%d",&flag1);
        }
    }

    if((student==1) && (index!=-1) )
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[34m\t\t\t\t\t\tEdit student\n");
        printf("\033[33m\tchoose from the following\n");
        printf("\033[32m\t1-Edit Student Name\n");
        printf("\033[32m\t2-Edit Student's phone Number\n");
        printf("\033[32m\t3-Edit Student Grade\n");
        printf("\033[32m\t4-Edit father Name\n");
        printf("\033[32m\t5-Edit father phone Number\n");
        printf("\033[32m\t6-Edit Mother Name\n");
        printf("\033[32m\t7-Edit Mother phone Number\n");
        printf("\033[32m\t8-Edit All data\n");
        flag2=0;
        while(flag2==0)
        {
            fflush(stdin);
            scanf("%d",&edit);
            if(edit==1)
            {
                scan_studentName(school[index].name,20);
                flag2=1;
            }
            else if(edit==2)
            {
                scan_studentPhone(school[index].phone,11);
                flag2=1;
            }
            else if(edit==3)
            {
                scan_StudentGrade(&school[index].grade);
                flag2=1;
            }
            else if(edit==4)
            {
                scan_FatherName(school[index].father.name,20);
                flag2=1;
            }
            else if(edit==5)
            {
                scan_FatherPhone(school[index].father.phone,11);

                flag2=1;
            }
            else if(edit==6)
            {
                scan_MotherName(school[index].mother.name,20);
                flag2=1;
            }
            else if(edit==7)
            {
                scan_MotherPhone(school[index].mother.phone,11);
                flag2=1;
            }
            else if(edit==8)
            {
                scan_studentName(school[index].name,20);
                scan_studentPhone(school[index].phone,11);
                scan_StudentGrade(&school[index].grade);
                scan_FatherName(school[index].father.name,20);
                scan_FatherPhone(school[index].father.phone,11);
                scan_MotherName(school[index].mother.name,20);
                scan_MotherPhone(school[index].mother.phone,11);
                flag2=1;
            }
            else
            {
                printf("\033[31m\tInvalid Input,Please Try again\n");
                flag2=0;
            }
        }
    }
    return 1;
}

void Remove_student(void)
{
    int choose,flag=0,student=0,index=-1,edit=0,i=0,enter;
    if(sp==0)
    {
        system("cls");
        printf("\033[31m\n\n\n\n\t\t\t\tThere is no Students in The School to Remove\n");
        return;
    }
    while(flag==0)
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[33m\t\t\t\t\t\ Remove student\n");
        printf("\tChoose from the following\n");
        printf("\033[32m\t1-Remove by Student Name\n");
        printf("\033[32m\t2-Remove by Student ID\n");
        fflush(stdin);
        scanf("%d",&choose);
        if(choose==1)
        {
            char name[20];
            system("cls");
            printf("\033[35m\n\n\tEnter student Name\n");
            printf("\033[0m");
            printf("\033[32m");
            scan_name(name,20);
            for(i=0; i<sp; i++)
            {
                if(string_comparenotsens(name,school[i].name)==1)
                {
                    student=1;
                    index=i;
                    flag=1;
                }
            }
            if(student==0)
            {
                printf("\033[31m\tThis Name does not exist \n");
                printf("\033[31m\t Enter 0 to try again or Enter 1 to go back \n");
                fflush(stdin);
                scanf("%d",&flag);
            }
        }
        else if(choose==2)
        {
            int id=-1;
            system("cls");
            printf("\033[35m\n\n\tEnter student ID\n");
            printf("\033[0m");
            printf("\033[32m");
            fflush(stdin);
            scanf("%d",&id);
            for(i=0; i<sp; i++)
            {
                if(id==school[id-1].id)
                {
                    student=1;
                    index=id-1;
                    flag=1;
                }
            }
            if(student==0)
            {
                printf("\033[31m\tThis number does not exist \n");
                printf("\033[31m\t Enter 0 to try again or Enter 1 to go back \n");
                fflush(stdin);
                scanf("%d",&flag);
            }
        }
        else
        {
            printf("\033[31m\tInvalid Input\n");
            printf("\tTo Try again Enter 0,To go Back Enter 1\n");
            fflush(stdin);
            scanf("%d",&flag);
        }
    }
    if((student==1) && (index!=-1) )
    {
        int i;
        school[index].id=0;
        school[index].grade=0;
        for(i=index; i<sp; i++)
        {
            school[i]=school[i+1];
            school[i].id--;
        }
        sp--;
        current_size--;

        system("cls");
        usleep(1000000);
        printf("\033[34m\n\n\n\t\t\tRemoving Student is Done\n");
        printf("\033[0m");
    }
}
void CallingBar(void)
{
    // 0 - black background,
    // A - Green Foreground
    //system("color 0A");
    printf("\033[32m");
    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;

    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t\tCalling Father");

        for (int i = 0; i < 15; i++)
    {
        printf(".");


        Sleep(500);
    }
    printf("\033[0m");
}
void Call_father(void)
{
    int choose,flag=0,student=0,index=-1,edit=0,i=0,enter;
    if(sp==0)
    {
        system("cls");
        printf("\033[31m\n\n\n\n\t\t\t\tThere is no Students in The School\n");
        return;
    }
    while(flag==0)
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[33m\t\t\t\t\t\ Call Father\n");
        printf("\tChoose from the following\n");
        printf("\033[32m\t1-Enter Student Name\n");
        printf("\033[32m\t2-Enter Student ID\n");
        fflush(stdin);
        scanf("%d",&choose);
        if(choose==1)
        {
            char name[20];
            system("cls");
            printf("\033[35m\n\n\tEnter student Name\n");
            printf("\033[0m");
            printf("\033[32m");
            scan_name(name,20);
            for(i=0; i<sp; i++)
            {
                if(string_comparenotsens(name,school[i].name)==1)
                {
                    student=1;
                    index=i;
                    flag=1;
                }
            }
            if(student==0)
            {
                printf("\033[31m\tThis Name does not exist \n");
                printf("\033[31m\t Enter 0 to try again or Enter 1 to go back \n");
                fflush(stdin);
                scanf("%d",&flag);
            }
        }
        else if(choose==2)
        {
            int id=-1;
            system("cls");
            printf("\033[35m\n\n\tEnter student ID\n");
            printf("\033[0m");
            printf("\033[32m");
            fflush(stdin);
            scanf("%d",&id);
            for(i=0; i<sp; i++)
            {
                if(id==school[id-1].id)
                {
                    student=1;
                    index=id-1;
                    flag=1;
                }
            }
            if(student==0)
            {
                printf("\033[31m\tThis number does not exist \n");
                printf("\033[31m\t Enter 0 to try again or Enter 1 to go back \n");
                fflush(stdin);
                scanf("%d",&flag);
            }
        }
        else
        {
            printf("\033[31m\tInvalid Input\n");
            printf("\tTo Try again Enter 0,To go Back Enter 1\n");
            fflush(stdin);
            scanf("%d",&flag);
        }
    }
    if((student==1) && (index!=-1) )
    {
        system("cls");
        CallingBar();
        printf("\033[34m\n\n\n\t\t\t\t\t\tThe Call is Done\n");
        printf("\033[0m");
    }

}
int save_Data(void)
{

    data= fopen("data.txt","w");
    fprintf(data,"Total number of students = %d\n", current_size);
    fprintf(data,"sp = %d\n", sp);
    fprintf(data, "*--------------------------------------------------------------------------------------------------------------------* \n");
    fprintf(data, "Item|Student Name        |Number     |ID  |Grade |Father Name         |Father Number|Mother Name         |Mother Number\n");
    for(int i = 0; i < current_size; i++)
    {
        fprintf(data, "|-----------------------------------------------------------------------------------------------------------------|\n");
        fprintf(data, "%-4d|%-20s|%-11s|%-4d|%-6d|%-20s|%-13s|%-20s|%-13s\n",
                i+1,school[i].name,school[i].phone,school[i].id,school[i].grade,
                school[i].father.name,school[i].father.phone,school[i].mother.name,school[i].mother.phone);
    }
    fprintf(data, "*--------------------------------------------------------------------------------------------------------------------* \n");
    fclose(data);

    return 0;
}
void read_data(void)
{
    data = fopen("data.txt","r");
    if(data!=NULLPTR )
    {
        int i;
        char read[145] = {0};
        fgets(read,145,data);
        convert_char_TO_int(&read[27],&current_size,2);
        fgets(read,145,data);
        convert_char_TO_int(&read[5],&sp,2);
        fgets(read,145,data);
        fgets(read,145,data);
        for(int counter = 0; counter < current_size; counter++)
        {
            fgets(read,145,data);
            fgets(read, 145,data);
            string_copy(&read[5], school[counter].name, 20);
            string_copy(&read[26], school[counter].phone, 11);
            convert_char_TO_int(&read[38], &school[counter].id, 2);
            convert_char_TO_int(&read[43],&school[counter].grade, 3);
            string_copy(&read[50], school[counter].father.name, 20);
            string_copy(&read[71], school[counter].father.phone, 11);
            string_copy(&read[85],school[counter].mother.name, 20);
            string_copy(&read[106], school[counter].mother.phone, 11);
        }
    }
    fclose(data);
}
void school_print(void)
{

    int i;
    system("cls");
    printf("\033[36m\nItem|Student Name        |Number     |ID  |Grade |Father Name         |Father Number|Mother Name         |Mother Number\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("\033[0m");
    for(i=0; i<current_size; i++)
    {
        printf("\033[33m%-4d|%-20s|%-11s|%-4d|%-6d|%-20s|%-13s|%-20s|%-13s\n",i+1,school[i].name,school[i].phone,school[i].id,school[i].grade,school[i].father.name,school[i].father.phone,school[i].mother.name,school[i].mother.phone);
    }

    printf("\033[0m");
}
