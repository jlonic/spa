#include <stdio.h>

int mystrlen(char* str)
{
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

int main()
{
    char str[100];

    printf("Unesi string:\n");
    scanf("%s", str);
    //printf("Uneseni string je %s", str);

    printf("%d", mystrlen(str));
    return 0;
}