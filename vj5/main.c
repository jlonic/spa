#include <stdio.h>
#include <stdlib.h>
#include "zd5.h"

int main()
{
	Queue* q=create();

	dodaj(q, 6);
	dodaj(q, 2);
	dodaj(q, 7);
	dodaj(q, 1);
	dodaj(q, 5);
	dodaj(q, 3);
	dodaj(q, 4);

	print(q);

	delete_najveci(q);

	print(q);	
}