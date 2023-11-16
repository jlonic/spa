#include <stdio.h>
#include <stdlib.h>

typedef struct Tocka
{
    float x;
    float y;
}Tocka;

typedef struct Poligon 
{
    int n; //broj vrhova
    Tocka *vrh;

}Poligon;

Tocka** pozitivni(Poligon *p, int *np) 
{
    int br_poz=0;
    for (int i=0;i<p->n;i++)
    {
        if ((p->vrh[i].x > 0) && (p->vrh[i].y > 0))
            br_poz++;
    }
    //printf("broj pozitivnih parova = %d\n", br_poz);
    Tocka** poz=(Tocka**)malloc(br_poz*sizeof(Tocka));

    int br=0;
    for (int i=0;i<p->n;i++)
    {
        if ((p->vrh[i].x > 0) && (p->vrh[i].y > 0))
        {
            poz[br]=&p->vrh[i];
            *np+=1; 
            br++; //za upis elemenata 
        }
    }

    return poz;
}

Poligon* novi_poligon(float *niz_x, float *niz_y, int n)
{
    Poligon *novi=(Poligon*)malloc(sizeof(Poligon));
    
    if(novi==NULL)
        printf("greska u alociranju (novi)\n");
    novi->vrh=(Tocka*)malloc(n*sizeof(Tocka));
    if(novi->vrh==NULL)
        printf("greska u alociranju (tocka)\n");
    
    for (int i=0;i<n;i++)
        novi->vrh[i].x=niz_x[i];

    for (int i=0;i<n;i++)
        novi->vrh[i].y=niz_y[i];

    novi->n=n;

    return novi;
};

void ispis(Poligon *p, int n)
{
    for(int i=0;i<n;i++)
        printf("koord %d. vrha su: %f x, %f y\n", i+1, p->vrh[i].x,p->vrh[i].y);
}

int main()
{
    float niz_x[]={3.2, 4.5, -2.23, -4.21, 3.33};
    float niz_y[]={-4.24, 1.32, 5.66, -3.1, 4.44};

    int n=sizeof(niz_x)/sizeof(niz_x[0]); //koristim niz_x jer bi niz_y trebao imati jednako elemenata jer su koordinate par
    Poligon* p=(Poligon*)malloc(sizeof(Poligon));
    if(p==NULL)
        printf("greska u alociranju (p)\n");

    p=novi_poligon(niz_x,niz_y,n);

    //ispis za provjeru
    printf("novi poligon ima %d vrhova\n", p->n);
    ispis(p, p->n); 

    int np=0;
    Tocka** t=pozitivni(p, &np);
    for (int i=0;i<np;i++)
        printf("pozitivni parovi su %f %f\n", t[i]->x, t[i]->y);

    printf("np je %d\n", np); 


    free(p);
    free(t);
    return 0;
}