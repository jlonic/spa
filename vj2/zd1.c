#include <stdio.h>
#include <stdlib.h>
#include "zd1.h"

Objekt3D* upis_u_strukturu()
{
    Objekt3D* objekt=(Objekt3D*)malloc(sizeof(Objekt3D));
    FILE *dat=fopen("primjerbin.stl","rb");
    fseek(dat,80,SEEK_SET); //header

    unsigned int broj_trokuta=0;
    fread(&broj_trokuta,4,1,dat);
    Trokut* t=(Trokut*)malloc(broj_trokuta*sizeof(Trokut));

    int i;
    for (i=0;i<broj_trokuta;i++)
        fread(&(t[i]),50,1,dat);

    objekt->trokuti=t;
    objekt->br_trokuta=broj_trokuta;

    fclose(dat);
    return objekt;
}

void upisi_objekt_txt(Objekt3D* objekt)
{
    FILE *dat=fopen("text.stl","w");

    int i;
    fprintf(dat, "solid IME_OBJEKTA\n");
    for(i=0;i<objekt->br_trokuta;i++)
    {
        fprintf(dat,"  facet normal %f %f %f\n",objekt->trokuti[i].normala.x,objekt->trokuti[i].normala.y,objekt->trokuti[i].normala.z);
        fprintf(dat,"    outer loop\n");
        fprintf(dat,"      vertex %f %f %f\n",objekt->trokuti[i].v1.x, objekt->trokuti[i].v1.y, objekt->trokuti[i].v1.z);
        fprintf(dat,"      vertex  %f %f %f\n",objekt->trokuti[i].v2.x, objekt->trokuti[i].v2.y, objekt->trokuti[i].v2.z);
        fprintf(dat,"      vertex  %f %f %f\n",objekt->trokuti[i].v3.x, objekt->trokuti[i].v3.y, objekt->trokuti[i].v3.z);
        fprintf(dat,"    endloop\n");
        fprintf(dat,"  endfacet\n");
    }
    fprintf(dat, "endsolid IME_OBJEKTA");
}

void upisi_objekt_bin(Objekt3D* objekt)
{
    FILE *dat=fopen("bin.stl", "wb");
    char header[]={0};
    fwrite(header,1,80,dat);

    fwrite(&objekt->br_trokuta,4,1,dat);

    int i;
    for(i=0;i<objekt->br_trokuta;i++)
        fwrite(&(objekt->trokuti[i]),50,1,dat);

    fclose(dat);
}

void delete_objekt(Objekt3D* objekt)
{
    free(objekt->trokuti);
    free(objekt);
}