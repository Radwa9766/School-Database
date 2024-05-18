#include <stdio.h>
#include <stdlib.h>
#include "school.h"

int string_comparenotsens(char*str1,char*str2)
{
    int i;
    for (i=0; str1[i]||str2[i]; i++)
    {
        if ( str1[i]!=str2[i]-'A'+'a' && str1[i]!=str2[i]-'a' + 'A' && str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1;
}
int string_len(char*str)
{
    int i;
    for(i=0; str[i]; i++);
    return i;
}
int string_compare(char*s1,char*s2)
{
    int i;
    if(string_len(s1)!=string_len(s2))
    {
        return 0;
    }
    int l=string_len(s1);
    for(i=0; s1[i]; i++)
    {
        if(s1[i]!=s2[i])
        {
            return 0;
        }
    }
    return 1;
}
void scan_name(char*str,int maxsize)
{
    int i;
    int flag=0;
    while (flag==0)
    {
        i=0;
        fflush(stdin);
        scanf("%c",&str[i]);
        for(; str[i]!='\n'&&i<maxsize-1;)
        {
            i++;
            scanf("%c",&str[i]);
        }
        str[i]=0;
        for(i=0; str[i]; i++)
        {
            if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || str[i]==' ')
            {
                flag=1;

            }
            else
            {
                printf("\033[31m\tThe Name isn't Correct, please Enter a Correct Name-->");
                printf("\033[32m");
                flag=0;
                break;
            }
        }
    }
    printf("\033[0m");

}
void scan_phone(char*str,int maxsize)
{
    int flag=0;
    while (flag==0)
    {
        int i=0;
        fflush(stdin);
        scanf("%c",&str[i]);
        for(; str[i]!='\n'&&i<maxsize-1;)
        {
            i++;
            scanf("%c",&str[i]);
        }
        str[i]=0;
        for(i=0; str[i]; i++)
        {
            if(str[i]<'0' || str[i]>'9')
            {
                printf("\033[31m\tThe Number isn't Correct, please Enter a Correct Number-->");
                printf("\033[32m");
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
    }
    printf("\033[0m");
}
void string_print(char arr[])//int arr[]
{
    int i;
    for(i=0; arr[i]!=0 ; i++)
    {
        printf("%c",arr[i]);
    }
    printf("\t");
}

void string_copy(char *str_original, char *str_copy, int counter)
{
    int c;
    for( c= 0;c<counter && str_original[c]; c++)
    {
        str_copy[c] = str_original[c];
    }
    str_copy[c-1]=0;
}

void convert_char_TO_int(char*str,int*num,int digits)
{
    *num=0;
    for(int c=0; c<digits && (str[c] >= '0' && str[c] <= '9');c++)
    {
        *num=*num *10 + (str[c]-'0');
    }
}
