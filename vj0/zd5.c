#include <stdio.h>

int mystrlen(char* str)
{
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

char* mystrstr(char *str1, char* str2)
{
    int n=mystrlen(str1);
    //printf("n=%d\n", n);

    int m=mystrlen(str2);
    //printf("m=%d\n",m);

    if (m>n)
    {
        printf("podstring nemoze biti dulji od stringa u kojem ga trazimo\n");
        return NULL;
    }
    int br=0;
    char *p;
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<(m+i);j++) 
        {                        
            if (str1[j]==str2[br])
                br++;
        }
        if (br==m) //ako je br jednak duljini podstringa to znaci da se podstring nalazi u stringu
        {
            p=&str1[i];
            return p;
        }
        br=0;
    }  

    printf("u stringu se ne nalazi podstring\n");
    return NULL;
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

    printf("%p", mystrstr(str1, str2));
    return 0;
}