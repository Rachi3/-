#pragma once

typedef struct __linkedList {
	int data;
	struct __linkedList* nextNode;
}LINKEDLIST;

//����
LINKEDLIST* Linit();
// ����

void AppendFirst(LINKEDLIST* L, int data);
void AppendLast(LINKEDLIST* L, int data);
void Append(LINKEDLIST* L, int data, int NodeCnt);


// ����

int remove(LINKEDLIST* L, int data);
int removeFirst(LINKEDLIST* L);
int removeLast(LINKEDLIST* L);

//Ž��

int search(LINKEDLIST* L, int data);