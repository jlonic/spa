#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ispis(int* arr, int n)
{
    for (int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// generirati niz od N razlicitih brojeva
int* generiraj(int n) 
{
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) 
    {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}


void shuffle(int *niz, int n) 
{
	for (int i = 0; i < n; i++) 
    {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* presjek(int* skupA, int* skupB, int n, int* presjek_velicina)
{
    int *niz=(int*)malloc(n*sizeof(int));
    *presjek_velicina=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (skupB[j]==skupA[i])
            {
                niz[*presjek_velicina]=skupA[i];
                *presjek_velicina+=1;
            }
        }
    }

    niz=(int*)realloc(niz, *presjek_velicina*sizeof(int));
    return niz;
}

int provjera(const void * a, const void * b)
{

	int va = *((int*)a);
	int vb = *((int*)b);
	return va - vb;
}

int* presjek_jedan_sortiran(int* skupA, int* skupB, int n, int* presjek_velicina)
{
    int *a;
    *presjek_velicina=0;

    int *niz=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        a=(int*)bsearch(&skupA[i], skupB, n, sizeof(int), provjera);
        if (a!=NULL)
        {
            niz[*presjek_velicina]=skupA[i];
            *presjek_velicina+=1;
        }
    }

    niz=(int*)realloc(niz, *presjek_velicina*sizeof(int));
    return niz;
}


int main()
{
    srand(time(NULL));
    
	clock_t start, stop;
	double ukupno;
    printf("OBA NIZA NESORTIRANA\n");
    for (int i=5000;i<=50000;i+=5000) //OBA NIZA NESORTIRANA
    {
        int *skupA=generiraj(i);
        shuffle(skupA, i);
        int *skupB=generiraj(i);
        shuffle(skupA, i);

        int presjek_velicina=0;
        start=clock();
		int* arr=presjek(skupA, skupB, i, &presjek_velicina);
		stop=clock();

        ukupno=(double)(stop-start)/CLOCKS_PER_SEC;
		printf("oba nesortirana: %f\n", ukupno);

		free(arr);
    } 
    printf("\nSKUPB SORTIRAN SA QSORT, PRESJEK()\n");
    for (int i=5000;i<=50000;i+=5000) //skupB SORTIRAN SA QSORT, funkcija presjek()
    {
        int *skupA=generiraj(i);
        shuffle(skupA, i);
        int *skupB=generiraj(i);
        shuffle(skupA, i);

        int presjek_velicina=0;
        start=clock();
        qsort(skupB, i, sizeof(int), provjera);
		int* arr=presjek(skupA, skupB, i, &presjek_velicina);
		stop=clock();

        ukupno=(double)(stop-start)/CLOCKS_PER_SEC;
		printf("oba nesortirana: %f\n", ukupno);

		free(arr);
    } 

    printf("\nSKUPB SORTIRAN SA QSORT, SA BSEARCH\n");
    for (int i=5000;i<=50000;i+=5000) //skupB SORTIRAN SA QSORT, funkcija presjek_jedan_sortiran() (KORISTI BSEARCH)
    {
        int *skupA=generiraj(i);
        shuffle(skupA, i);
        int *skupB=generiraj(i);
        shuffle(skupA, i);

        int presjek_velicina=0;
        start=clock();
        qsort(skupB, i, sizeof(int), provjera);
		int* arr=presjek_jedan_sortiran(skupA, skupB, i, &presjek_velicina);
		stop=clock();

        ukupno=(double)(stop-start)/CLOCKS_PER_SEC;
		printf("oba nesortirana: %f\n", ukupno);

		free(arr);
    }

    printf("\nOBA NIZA SORTIRANA\n");
    for (int i=5000;i<=50000;i+=5000) //OBA NIZA SORTIRANA
    {
        int *skupA=generiraj(i);
        //shuffle(skupA, i);
        int *skupB=generiraj(i);
        //shuffle(skupA, i);

        int presjek_velicina=0;
        start=clock();
		int* arr=presjek(skupA, skupB, i, &presjek_velicina);
		stop=clock();

        ukupno=(double)(stop-start)/CLOCKS_PER_SEC;
		printf("oba nesortirana: %f\n", ukupno);

		free(arr);
    } 
    
}

