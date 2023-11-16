#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w))
{
	Dictionary sljedeci=indict->next;
	Dictionary trenutni=indict;
	Dictionary temp; //za oslobadanje elemenata koji ne prolaze filter

	while (sljedeci!=NULL)
	{
		if (filter(sljedeci)==0) //rijec ne prolazi filter
		{
			temp=sljedeci;
			sljedeci=sljedeci->next; 
			trenutni->next=sljedeci;
			free(temp->word);
			free(temp);
		}
		else //rijec prolazi filter
		{
			trenutni=sljedeci;
			sljedeci=sljedeci->next;
		}
	}
	return indict;
}


int filter(Word *w)
{
	if (w->count<10 && w->count>5 && strlen(w->word)>3) 
		return 1;

	return 0;
}

void destroy(Dictionary dict)
{
	Dictionary t=dict;
	dict=dict->next;
	free(t->word);
	free(t);

	while (dict!=NULL) 
	{
		free(dict->word);
		t=dict;
		dict=dict->next;
		free(t);
	}
	printf("\nRJECNIK IZBRISAN\n");
}

void print(Dictionary rjecnik) //ispis
{
	while (rjecnik->next!=NULL) 
	{
		printf("%s se ponavlja %d puta\n", rjecnik->word, rjecnik->count);
		rjecnik=rjecnik->next;
	}
}

void add(Dictionary dict, char *str)
{
	Word* rijec=(Word*)malloc(sizeof(Word)); //provjera
	char* temp=(char*)malloc(strlen(str)*sizeof(char)); //provjera
	strcpy(temp, str);
	rijec->word=temp;

	Word* sljedeci=dict->next; 
	while (sljedeci!=NULL) 
	{	
		if (strcmp(sljedeci->word, rijec->word)==0) 
		{
			sljedeci->count++; 
			return; 
		}
		else if (strcmp(sljedeci->word, rijec->word)>0) //ako se rijec treba nalaziti prije iduce(brojac->word) u rjecniku
		{
			rijec->next=sljedeci;
			rijec->count=1;
			dict->next=rijec; 
			return; 
		}

		sljedeci=sljedeci->next;
		dict=dict->next;
	}
	//ako je zadnja u rjecniku dodaje se na kraj
	rijec->next=NULL;
	rijec->count=1;
	dict->next=rijec;
	
}

Dictionary create()
{
	Dictionary rjecnik;
	rjecnik=(Word*)malloc(sizeof(Word));

	if (rjecnik==NULL) 
		printf("greska u alociranju memorije(create)\n");

	rjecnik->word=NULL;
	rjecnik->next=NULL;
	return rjecnik;
}