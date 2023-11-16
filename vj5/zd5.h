#include <stdio.h>
#include <stdlib.h>

typedef struct Element 
{
	int prio;
	void* data;
}Element;

typedef struct Queue 
{
	int n;
	Element* arr;
}Queue;


Queue* create();
void print(Queue* q);
void enqueue(Queue* q, int k);
void dodaj(Queue* q, int pr);
void dequeue(Queue* q, int k);
void delete_najveci(Queue* q);
