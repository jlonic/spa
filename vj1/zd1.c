#include <stdio.h>
#include <stdlib.h>


int* podniz(int* niz, int start, int stop)
{

    if (stop<start) //start nemoze biti veci od stopa
    {
        printf("pogresan unos - stop mora biti veci od starta\n");
        return 0;
    }

    int *podniz=(int*)malloc((stop-start)*sizeof(int)); //novi niz
    if (podniz==NULL)
        printf("greska u alociranju memorije\n");
        
    int brojac=0; //za stavljanje elemenata u novi niz
    for (int i=start; i<=stop;i++) //petlja za umetanje novih elemenata
    {
        podniz[brojac]=niz[i];
        brojac++; 
    }
    
    return podniz;
}

int main()
{
    int arr[]={5, 3, 1, 8, 15, 2, 9, 23, 48, 31};

    int start;
    printf("Unesite start\n");
    scanf("%d", &start);

    while(start<0)
    {
        printf("greska u unosu: start ne smije biti manji od 0\n");
        printf("\nUnesite start\n");
        scanf("%d", &start);
    }

    int stop;
    printf("Unesite stop\n");
    scanf("%d", &stop);

    int *niz=(int*)malloc((stop-start)*sizeof(int));
    if (niz==NULL)
        printf("greska u alociranju memorije\n");

    niz=podniz(arr, start, stop);
    
    printf("novi niz je:\n");
    for (int i=0;i<=stop-start;i++) //ispis za provjeru
        printf("%d ", niz[i]);

    free(niz);
    return 0;
}