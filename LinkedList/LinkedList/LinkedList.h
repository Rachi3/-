#pragma once

typedef struct __linkedList {
	int data;
	struct __linkedList* nextNode;
}LINKEDLIST;

void printList(LINKEDLIST* head);
//시작
LINKEDLIST* Linit();

// 삽입
void AppendFirst(LINKEDLIST* Head, int data);//처음에 삽입
void AppendLast(LINKEDLIST* Head, int data);//마지막 자리에 삽입
void Append(LINKEDLIST* Head, int data, int NodeCnt);//NodeCnt번째 자리에 삽입 1 2 3 4 5 가 있고 NodeCnt가 2에 7삽입이면 1 7 2 3 4 5 로 나오게


// 삭제

int removeNode(LINKEDLIST* L, int data);
int removeFirst(LINKEDLIST* L);
int removeLast(LINKEDLIST* L);

//탐색

int returnNodeCnt(LINKEDLIST* Head);
int search(LINKEDLIST* L, int data);