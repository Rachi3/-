#include "CircularLinkedList.h"
#include <stdlib.h>
#include<stdio.h>

void printList(LINKEDLIST* Head)
{
    LINKEDLIST* tmp = Head->nextNode;
    while (tmp != NULL)
    {
        printf("현재 위치 : %p 현재 데이터 %d 다음 노드 %p\n", tmp, tmp->data, tmp->nextNode);
        tmp = tmp->nextNode;
    }
}

LINKEDLIST* Linit()
{
    LINKEDLIST* Head = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));

    if (Head != NULL)
        Head->nextNode = Head;//원형 연결이기에 자기 자신 가리키게
    return Head;
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
    LINKEDLIST* tmp = Head, * next = Linit();

    while (tmp->nextNode != Head)
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

int removeNode(LINKEDLIST* Head, int data)
{
    LINKEDLIST* tmp = Head->nextNode, * t = NULL;

    while (tmp != NULL)
    {
        if (tmp->nextNode->data == data)
        {
            t = tmp->nextNode;

            tmp->nextNode = t->nextNode; //삭제하려는 노드 제거
            free(t);
            return data;
        }
        tmp = tmp->nextNode;
    }

    printf("삭제하시려는 Data가 존재하지 않습니다.\n"); //만약 노드 검색시 해당 data가 존재하지 않으면 출력과 -1 리턴
    return -1;
}

int removeFirst(LINKEDLIST* Head)
{
    if (Head == NULL)
        return -1;// 빈 리스트면 오류반환

    LINKEDLIST* tmp = Head->nextNode;
    int returnData = tmp->data;

    Head->nextNode = tmp->nextNode;

    free(tmp);
    return returnData;
}

int removeLast(LINKEDLIST* Head)
{
    if (Head->nextNode == NULL)
        return -1;//노드가 비어있으면 오류

    LINKEDLIST* tmp = Head;
    int returnData = 0;

    while (tmp->nextNode->nextNode != NULL)
        tmp = tmp->nextNode;

    returnData = tmp->nextNode->data;
    free(tmp->nextNode);

    tmp->nextNode = NULL;

    return returnData;
}


int returnNodeCnt(LINKEDLIST* Head)
{
    LINKEDLIST* tmp = Head->nextNode;
    int cnt = 0;
    while (tmp != Head)
    {
        tmp = tmp->nextNode;
        cnt++;
    }

    return cnt;
}

int search(LINKEDLIST* L, int data)
{
    int Cnt = 0;
    LINKEDLIST* tmp = L;

    while (tmp != NULL)
    {
        if (tmp->data == data)
            return Cnt;
        Cnt++;
        tmp = tmp->nextNode;
    }
    return -1;//못찾으면 오류
}
