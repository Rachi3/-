#include "LinkedList.h"
#include <stdlib.h>
#include<stdio.h>

void printList(LINKEDLIST* head)
{
    LINKEDLIST* tmp = head->nextNode;
    while (tmp!= NULL)
    {
        printf("���� ��ġ : %p ���� ������ %d ���� ��� %p\n", tmp, tmp->data, tmp->nextNode);
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
        tmp = tmp->nextNode; //tmp�� ������ ���� �����

    next->data = data;
    tmp->nextNode = next;
}

void Append(LINKEDLIST* Head, int data, int NodeCnt)
{
    if (returnNodeCnt(Head) < NodeCnt)//������ �ڸ��� �����ϴ� ��� �ۿ� �ִٸ� ����
    {
        printf("ERROR:����� ������ �����մϴ�.");
        return;
    }

    LINKEDLIST* tmp = Head->nextNode, * newNode = Linit();
    int n = 1;
    newNode->data = data;

    while (++n < NodeCnt)
        tmp = tmp->nextNode;//���ϴ� ��ġ���� �б�
    
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
