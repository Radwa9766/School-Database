#include <stdio.h>
#include <stdlib.h>
#include "school.h"

int main()
{

    for(int i=0;i<1000000000;i++)
    {

    }
    int flag=1;
    int num=0;
    int r;
    read_data();
    while(flag==1)
    {
        intduction();
        scanf("%d",&num);
        if(num==1)
        {
            add_student();
            //save_Data();
            printf("\033[35m\n\n\tTo go Back Enter 1 ,to Exit Enter 0\n");
            fflush(stdin);
            scanf("%d",&flag);
            printf("\033[0m");

        }
        else if(num==2)
        {
            if(Edit_student()==1)
            {
                printf("\033[35m\tEdit is Done\n");
                printf("\033[0m");
                save_Data();
                printf("\033[35m\n\n\tTo go Back Enter 1 ,to Exit Enter 0\n");
                fflush(stdin);
                scanf("%d",&flag);
                printf("\033[0m");
            }


        }
        else if(num==3)
        {
            Remove_student();
            save_Data();
            printf("\033[35m\n\n\tTo go Back Enter 1 ,to Exit Enter 0\n");
            fflush(stdin);
            scanf("%d",&flag);
            printf("\033[0m");

        }
        else if(num==4)
        {
            Call_father();
            printf("\033[35m\n\n\tTo go Back Enter 1 ,to Exit Enter 0\n");
            fflush(stdin);
            scanf("%d",&flag);
            printf("\033[0m");
        }
        else if(num==5)
        {
            school_print();
            printf("\033[35m\n\n\tTo go Back enter 1 ,to Exit enter 0\n");
            fflush(stdin);
            scanf("%d",&flag);
            printf("\033[0m");

        }
        else if(num==6)
        {
            return;
        }
        else
        {
            printf("\033[31m\tInvalid Input,Please Choose from 1:5\n");
            fflush(stdin);
            scanf("%c",&r);
            flag=1;
        }

    }
    return 0;
}



