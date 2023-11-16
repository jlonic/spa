#include <stdio.h>

int mystrlen(char* str)
{
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

int mystrcmp(char* str1, char* str2)
{
    int brojac=0;

    int n=mystrlen(str1);
    //printf("n=%d\n", n);

    int m=mystrlen(str2);
    //printf("m=%d\n",m);

    int najduzi_string=m;
    if (n>m)
        najduzi_string=n;

    //printf("najduzi_string=%d\n", najduzi_string);

    for (int i=0;i<najduzi_string;i++)
    {
        if(str2[i]>str1[i])
        {
            //printf("str1 je manji od str2\n");
            return -1;
        }
        else if(str2[i]<str1[i])
        {
            //printf("str1 je veci od str2\n");
            return 1;
        }
    }
    return 0; //vraca 0 ako su jednaki
}

int main()
{
    char str1[100];
    char str2[100];

    //str1    
    printf("Unesi prvi string:\n");
    scanf("%s", str1);
    printf("Prvi string je %s\n", str1);
    
    //str2
    printf("Unesi drugi string:\n");
    scanf("%s", str2);
    printf("Drugi string je %s\n", str2);

    printf("%d", mystrcmp(str1, str2));
    return 0;
}