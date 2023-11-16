#include <stdio.h>
#include <stdlib.h>

int* filtriraj(int* niz, int n, int th, int *nth)
{
    *nth=0;
    for (int i=0; i<n;i++) //broji koliko elemenata u nizu je manje od th
    {
        if (niz[i]<th)
            *nth+=1;
    }

    int *novi_niz=(int*)malloc(*nth*sizeof(int)); //novi niz
    if (novi_niz==NULL)
        printf("greska u alociranju memorije\n");

    int brojac=0; //za unos novih elemenata

    for (int i=0;i<=n;i++)
    {
        if (niz[i]<th)
        {
            novi_niz[brojac]=niz[i];
            brojac++;
        }
    }

    return novi_niz;
}

int main()
{
    int niz[]={2, 5, 4, 8, 13, 17, 32, 1, 44, 12};
    int n=sizeof(niz)/sizeof(niz[0]);

    int th; //th je najveci broj koji ce se nalaziti u nizu

    printf("Unesite novi najveci broj niza:\n");
    scanf("%d", &th);
    int nth=0; //nth je velicina novog niza

    int *arr=filtriraj(niz, n, th, &nth);

    printf("Novi niz je: ");
    for (int i=0;i<nth;i++) //ispis za provjeru
        printf("%d ", arr[i]);

    printf("\nDuljina novog niza je: %d\n", nth);

    free(arr);
    return 0;
}