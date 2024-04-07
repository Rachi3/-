#pragma once

typedef struct __linkedList {
	int data;
	struct __linkedList* nextNode;
}LINKEDLIST;

//Ω√¿€
LINKEDLIST* Linit();
// ª¿‘

void AppendFirst(LINKEDLIST* L, int data);
void AppendLast(LINKEDLIST* L, int data);
void Append(LINKEDLIST* L, int data, int NodeCnt);


// ªË¡¶

int remove(LINKEDLIST* L, int data);
int removeFirst(LINKEDLIST* L);
int removeLast(LINKEDLIST* L);

//≈Ωªˆ

int search(LINKEDLIST* L, int data);