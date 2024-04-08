#pragma once

typedef struct __linkedList {
	int data;
	struct __linkedList* nextNode;
}LINKEDLIST;

void printList(LINKEDLIST* Head);
//����
LINKEDLIST* Linit();

// ����
void AppendFirst(LINKEDLIST* Head, int data);//ó���� ����
void AppendLast(LINKEDLIST* Head, int data);//������ �ڸ��� ����
void Append(LINKEDLIST* Head, int data, int NodeCnt);//NodeCnt��° �ڸ��� ���� 1 2 3 4 5 �� �ְ� NodeCnt�� 2�� 7�����̸� 1 7 2 3 4 5 �� ������


// ����

int removeNode(LINKEDLIST* Head, int data);
int removeFirst(LINKEDLIST* Head);
int removeLast(LINKEDLIST* Head);

//Ž��

int returnNodeCnt(LINKEDLIST* Head);
int search(LINKEDLIST* L, int data);