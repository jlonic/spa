#include <stdio.h>
#include <stdlib.h>
#include "zd1.h"

void main()
{
    Objekt3D* objekt=upis_u_strukturu();
    //printf("%d", objekt->br_trokuta); //provjera

    upisi_objekt_txt(objekt);
    upisi_objekt_bin(objekt);

    delete_objekt(objekt);
}