#include <stdio.h>
int mystrlen(char* str)
{
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

//stavlja preokrenuti prvi na kraj drugog 
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


char* reverse(char* str1, char* str2)
{   
    char temp[100];
    int n=mystrlen(str1);

    for (int i=0; i<n; i++) //petlja za preokrenuti string
        temp[i]=str1[n-1-i]; 
    //printf("temp je %s\n", temp); //za provjeru

    str1=temp;
    str1[n]='\0';

    //printf("STR1 JE %s STR 2 JE %s\n", str1, str2);
    
    mystrcat(str2, str1);
    return str2;
}


int main()
{
    char str1[100];
    char str2[100];

    //str1    
    printf("Unesi prvi string:\n");
    scanf("%s", str1);
    printf("Prvi string je %s\n\n", str1);
    
    //str2
    printf("Unesi drugi string:\n");
    scanf("%s", str2);
    printf("Drugi string je %s\n\n", str2);

    reverse(str1,str2);

    printf("Novi drugi string je %s\n", str2);
    //printf("duljina novog str je %d\n", mystrlen(str2));

    return 0;
}




//stavlja preokrenuti prvi preko drugog
/*
char *mystrcpy(char* str1, char* str2)
{
    int n;
    n=mystrlen(str2);
    str1[0]=0; //brisem sadrzaj str1 za slucaje ako je veci od str2
    for (int i=0;i<n;i++)
    {
        str1[i]=str2[i];
    }
    return str1;
}

char* reverse(char* str1, char* str2)
{   
    char temp[100];
    int n=mystrlen(str1);

    for (int i=0; i<n; i++) //petlja za preokrenuti string
    {
        temp[i]=str1[n-1-i]; 
    }
    //printf("%s", temp); //za provjeru

    str1=temp;
    str1[n]='\0';

    mystrcpy(str2,str1); 
    return str2;
}


int main()
{
    char str1[100];
    char str2[100];

    //str1    
    printf("Unesi prvi string:\n");
    scanf("%s", str1);
    printf("Prvi string je %s\n\n", str1);
    
    //str2
    printf("Unesi drugi string:\n");
    scanf("%s", str2);
    printf("Drugi string je %s\n\n", str2);

    reverse(str1,str2);

    printf("Novi drugi string je %s", str2);

    return 0;
}

*/

