#include "LinkedList.h"
#include <stdlib.h>
#include<stdio.h>

void printList(LINKEDLIST* head)
{
    LINKEDLIST* tmp = head->nextNode;
    while (tmp!= NULL)
    {
        printf("현재 위치 : %p 현재 데이터 %d 다음 노드 %p\n", tmp, tmp->data, tmp->nextNode);
        tmp = tmp->nextNode;
    }
}

LINKEDLIST* Linit()
{
    LINKEDLIST* L = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));

    if (L != NULL)
        L->nextNode = NULL;
    return L;
}

void AppendFirst(LINKEDLIST* Head, int data)
{
    LINKEDLIST* first = Linit();

    first->data = data;
    first->nextNode = Head->nextNode;
    Head->nextNode = first;

}

void AppendLast(LINKEDLIST* Head, int data)
{
    LINKEDLIST*tmp=Head,* next = Linit();

    while (tmp->nextNode != NULL)
        tmp = tmp->nextNode; //tmp를 마지막 노드로 만들기

    next->data = data;
    tmp->nextNode = next;
}

void Append(LINKEDLIST* Head, int data, int NodeCnt)
{
    if (returnNodeCnt(Head) < NodeCnt)//삽입할 자리가 존재하는 노드 밖에 있다면 오류
    {
        printf("ERROR:노드의 개수가 부족합니다.");
        return;
    }

    LINKEDLIST* tmp = Head->nextNode, * newNode = Linit();
    int n = 1;
    newNode->data = data;

    while (++n < NodeCnt)
        tmp = tmp->nextNode;//원하는 위치까지 밀기
    
    newNode->nextNode = tmp->nextNode;
    tmp->nextNode = newNode;
}

int returnNodeCnt(LINKEDLIST* Head)
{
    LINKEDLIST* tmp = Head->nextNode;
    int cnt = 0;
    while (tmp != NULL)
    {
        tmp = tmp->nextNode;
        cnt++;
    }

    return cnt;
}
