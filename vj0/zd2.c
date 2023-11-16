#include <stdio.h>

int mystrlen(char* str)
{
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

char *mystrcpy(char* str1, char* str2)
{
    int n=mystrlen(str2);
    
    for (int i=0;i<n;i++)
        str1[i]=str2[i];
    str1[n]='\0'; //n=duljina stringa koji se kopira

    return str1;
}

int main()
{
    char str1[100];
    char str2[100];

    //str1    
    printf("Unesi prvi string:\n");
    scanf("%s", str1);
    //printf("Prvi string je %s\n", str1);
    
    //str2
    printf("Unesi drugi string:\n");
    scanf("%s", str2);
    //printf("Drugi string je %s\n", str2); 
    
    mystrcpy(str1, str2);
    printf("Novi str1 je %s\n", str1);
    printf("str2 je %s", str2);
    return 0;
}