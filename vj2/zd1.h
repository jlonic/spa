#ifndef ZD1_H
#define ZD1_H

typedef struct
{
    float x,y,z;
}Vrh;

typedef struct
{
    Vrh normala;
    Vrh v1,v2,v3;
    unsigned short n;
}Trokut;

typedef struct
{
    Trokut* trokuti;
    int br_trokuta;
}Objekt3D;

Objekt3D* upis_u_strukturu();
void upisi_objekt_txt(Objekt3D* objekt);
void upisi_objekt_bin(Objekt3D* objekt);
void delete_objekt(Objekt3D* objekt);

#endif
