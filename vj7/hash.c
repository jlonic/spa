#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokaziva�a)
	HashTable *ht=(HashTable*)malloc(sizeof(HashTable));
	ht->table=(Bin**)calloc(size, sizeof(Bin*));
	ht->size=size;
	ht->load=0;
	
	return ht;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	int key=hash(word)%ht->size;
	
	Bin* b=(Bin*)malloc(sizeof(Bin));
	b->word=word;
	b->next=NULL;

	if(ht->table[key]==NULL)
	{
		ht->table[key]=b;
		ht->load++;
		return;
	}

	while(ht->table[key]->next!=NULL)
		ht->table[key]->next=ht->table[key]->next->next;

	ht->table[key]->next=b;
	ht->load++;
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	int key=hash(word)%ht->size;
	Bin* b=ht->table[key];

	while(b!=NULL)
	{
		if (strcmp(word, b->word)==0)
			return 1;
			
		b=b->next;
	}
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	for(int i=0;i<ht->size;i++)
	{
		if(ht->table[i]!=NULL)
		{
			while(ht->table[i]->next!=NULL)
			{
				Bin *b=ht->table[i];
				ht->table[i]=ht->table[i]->next;
				free(b->word);
				free(b);
			}
		}
	}

	free(ht);
}