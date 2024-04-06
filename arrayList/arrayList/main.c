#pragma warning(disable:4996)
#include"arrayList.h"


int main()
{
	ArrayList L;

	Linit(&L);

	addFirst(&L, 7);
	addLast(&L, 8);

	printList(&L);
	remove(&L, 1);

	printList(&L);

	addFirst(&L,15);
	addFirst(&L,70);
	printList(&L);

	add(&L, 1, 3);
	
	printList(&L);

	removeFirst(&L);
	printList(&L);

	return 0;
}