#include <stdio.h>

int mystrlen(char* str)
{
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

char* mystrcat(char* str1, char* str2)
{
    int n=mystrlen(str1);
    //printf("n=%d\n", n);
    int m=mystrlen(str2);
    //printf("m=%d\n",m);
    int br=0;

    for (int i=n;i<n+m;i++)
    {
        str1[i]=str2[br];
        br++;
    }
    str1[n+m]='\0';
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

    mystrcat(str1,str2);
    printf("Novi string je %s", str1);
    return 0;

}