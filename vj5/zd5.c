#include <stdio.h>
#include <stdlib.h>
#include "zd5.h"

Queue* create()
{
	Queue* q=(Queue*)malloc(sizeof(Queue));

	q->arr=(Element*)malloc(10000*sizeof(Element));
	q->n=0;

	return q;
}

void enqueue(Queue* q, int k) 
{
	if (k<=0)
		return;

	int rod=(k-1)/2;

	if (q->arr[rod].prio<q->arr[k].prio) //ako je roditelj veci od trenutnog elementa ih zamjeni
	{
		Element temp;
		temp=q->arr[rod];
		q->arr[rod]=q->arr[k];
		q->arr[k]=temp;

		k=rod;

        enqueue(q, k);
	}

}

void dodaj(Queue* q, int pr)
{
	Element novi;
	int k; 

	novi.data=NULL;
	novi.prio=pr;

	q->arr[q->n]=novi;
	k=q->n;
	q->n++;

	enqueue(q, k);
}

void dequeue(Queue* q, int k)
{
	if (k>=q->n)
		return;

	int l=(k*2)+1; //left
	int r=(k*2)+2; //right
	int t; //temp(za zamjenu sa vecim elementom)
	
	if (l>q->n)
		return;
	else if (r>q->n)
		t=l;
	else 
		t=r;

	if(q->arr[t].prio>q->arr[k].prio) //zamjena
	{
		Element temp;
		temp=q->arr[k];
		q->arr[k]=q->arr[t];
		q->arr[t]=temp;

		k=t; 
		dequeue(q, k);
	}
}

void delete_najveci(Queue* q)
{
	int najveci=0;

	q->arr[najveci]=q->arr[q->n-1]; //zadnji elem na prvo mjesto
	q->n--;

	dequeue(q, najveci);
}

void print(Queue* q)
{
	int i=0;
	while (i<q->n)
	{
		printf("%d ", q->arr[i].prio);
		i++;
	}
    printf("\n");
}
