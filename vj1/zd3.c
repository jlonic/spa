#include <stdio.h>
#include <stdlib.h>


int** podijeli(int *niz, int n)
{   
    int m=n/2;
    if (n%2!=0) //ako je niz neparne velicine 
        m++;
    
    int *prvi=(int*)malloc(m*sizeof(int));
    int *drugi=(int*)malloc((n/2)*sizeof(int));

    for (int i=0;i<m;i++)
        prvi[i]=niz[i];

    int br=0;
    for (int i=m;i<n;i++)
    {
        drugi[br]=niz[i];
        br++;
    }

    printf("\nPrvi dio je: ");
    for (int i=0;i<m;i++) //ispis prvog dijela
        printf("%d ", prvi[i]);


    printf("\nDrugi dio je: ");
    for (int i=0;i<n/2;i++) //ispis drugog dijela
        printf("%d ", drugi[i]);
    printf("\n");
    
    
    int **novi=(int**)malloc(2*sizeof(int)); //sadrzi samo 2 elementa, pocetak na prvi dio i pocetak na drugi dio
    if(novi==NULL)
        printf("greska u alociranju\n");

    novi[0]=&prvi[0];
    novi[1]=&drugi[0];

    return novi;    
}

int main()
{
    int niz[]={3, 5, 6, 4, 7, 2};
    int n=sizeof(niz)/sizeof(niz[0]);


    printf("\nPocetni niz je: ");
    for (int i=0;i<n;i++)
        printf("%d ", niz[i]);

    int **nnovi=podijeli(niz,n);

    for (int i=0;i<2;i++)
        printf("Adresa %d dijela je: %p\n", i+1, nnovi[i]);

    free(nnovi);
    return 0;
}