#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printmenu()
{
    printf("=========Menu========\n");
    printf("1.PrintString\n");
    printf("2.Search \n");
    printf("3.Modify \n");
    printf("4.Exit\n");
    printf("=====================\n");
    printf("Input Number: ");
}

char* findStr(char *str1, char *str2);
char* mod_Str(char *str1, char *str2, char *str3);
char* selection(int num, char *str);


int main()
{
    char str[2000];
    int num;
    char x;

    FILE* fp=fopen("string_1.txt","r");
    fgets(str,sizeof(str),fp);

    while (1)
    {
        printmenu();
        scanf("%d", &num);
        x=selection(num,str);
        if (x==NULL)
        {
            break;
        }
    }
    return 0;
}

char* selection(int num, char *str)
{
    int count=0;
    if (num==1) //print
    {
        printf("%s\n",str);
    }
    else if (num==2) //find
    {
        char in_text[100];
        printf("Input Word: ");
        scanf("%s",&in_text);
        count=findStr(str,in_text);
        //printf("%s\n",str);
        printf("Occurrence: %d\n",count);
    }
    else if (num==3) //modify
    {
        char prior[100], after[100];
        printf("Input Prior Word: ");
        scanf("%s",&prior);
        printf("Input After Word: ");
        scanf("%s",&after);
        mod_Str(str,prior,after);
    }
    else if (num==4) //exit
    {
        return NULL;
    }
    else{
        printf("Enter number between 1~4\n");
    }
    printf("\n");
}

char* findStr(char *str1, char *str2)
{
    //finding str2 in str1
    int count=0, i=0,j=0, index[100]={0,};
    char sub[2000];
    char original[1000];
    char *first=str1;
    while (*str1 != '\0') //search until string ends
    {
        char *pch_str1=str1;
        char *pch_str2=str2;
        int len=0;
        while((abs(*pch_str2 - *pch_str1)==32 || abs(*pch_str2 - *pch_str1)==0)  && *pch_str1 !='\0' && *pch_str2 != '\0'
            )
        {
            pch_str1++;
            pch_str2++;
            len++;
        }
        if (len == strlen(str2)) //same word finished
        {
            int x = pch_str1-first-len ; //total length that has to be included first = end - length
            index[count]=x;
            //printf("x is %d\n",x);
            count++;
        }
        str1++;
    }
    strncpy(sub, first, sizeof(sub)-1);
    sub[sizeof(sub)-1]='\0';
    //printf("first: %s\n",sub);
    for (i=0;index[i]!=0;i++)
    {
        char temp[1000];
        //printf("index: %d\n",index[i]);
        strncpy(temp,sub,index[i]+(i)*(6));
        //puts(temp);
        //printf("pre-sub:%s\n",temp);
        temp[index[i]+(i)*(6)] = '\0';
        strcat(temp, "[[[");
        //puts(temp);
        strcat(temp, str2);
        strcat(temp, "]]]");
        //puts(temp);
        //printf("before adding : %s\n",temp);
        strcat(temp, first + index[i]+strlen(str2));  //) index[i]+(i)*(6+strlen(str2))
        //puts(temp);
        //printf("'sub' loop: %s\n\n",temp);
        strncpy(sub,temp,sizeof(sub)-1);
        sub[sizeof(sub)-1]='\n';
    }
    printf("%s\n",sub);
    return count;
}

char* mod_Str(char *str1, char *str2, char *str3)
{
    //finding str2 in str1 and switch to str3
    int count=0, i=0,j=0, index[100]={0,};
    char sub[2000];
    char *first=str1;
    while (*str1 != '\0') //search until string ends
    {
        char *pch_str1=str1;
        char *pch_str2=str2;
        int len=0;
        while( (*pch_str1==*pch_str2 || *pch_str1==*pch_str2 ) && *pch_str1 !='\0' && *pch_str2 != '\0')
        {
            //(*pch_str1==*pch_str2 || *pch_str1==*pch_str2 ) && *pch_str1 !='\0' && *pch_str2 != '\0')
            //65to90 97 122, 32 differs
            pch_str1++;
            pch_str2++;
            len++;
        }
        if (len == strlen(str2)) //same word finished
        {
            int x = pch_str1-first-len ; //total length that has to be included first = end - length
            index[count]=x;
            //printf("x is %d\n",x);
            count++;
            //str1=pch_str1;
            //continue;
            //printf("position: %d\n",pch_str1-len);
        }
        str1++;
    }

    strncpy(sub, first, sizeof(sub)-1);
    sub[sizeof(sub)-1]='\0';
    //printf("first: %s\n",sub);
    for (i=0;index[i]!=0;i++)
    {
        char temp[1000];
        //printf("index: %d\n",index[i]);
        strncpy(temp,sub,index[i]);
        //puts(temp);
        //strncpy(temp,sub,index[i]+(i)*(6));
        //printf("pre-sub:%s\n",temp);
        temp[index[i]] = '\0';
        //temp[index[i]+(i)*(6)] = '\0';
        //strcat(temp, "[[[");
        strcat(temp, str3);
        //strcat(temp, "]]]");
        //printf("before adding : %s\n",temp);
        strcat(temp, first + index[i]+strlen(str2));  //) index[i]+(i)*(6+strlen(str2))
        //printf("'sub' loop: %s\n\n",temp);
        strncpy(sub,temp,sizeof(sub)-1);
        sub[sizeof(sub)-1]='\n';
    }
    printf("%s\n", sub);
    return sub;
}
