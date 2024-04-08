#include "CircularLinkedList.h"
#include <stdlib.h>
#include<stdio.h>

void printList(LINKEDLIST* Head)
{
    LINKEDLIST* tmp = Head->nextNode;
    while (tmp != NULL)
    {
        printf("���� ��ġ : %p ���� ������ %d ���� ��� %p\n", tmp, tmp->data, tmp->nextNode);
        tmp = tmp->nextNode;
    }
}

LINKEDLIST* Linit()
{
    LINKEDLIST* Head = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));

    if (Head != NULL)
        Head->nextNode = Head;//���� �����̱⿡ �ڱ� �ڽ� ����Ű��
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

int removeNode(LINKEDLIST* Head, int data)
{
    LINKEDLIST* tmp = Head->nextNode, * t = NULL;

    while (tmp != NULL)
    {
        if (tmp->nextNode->data == data)
        {
            t = tmp->nextNode;

            tmp->nextNode = t->nextNode; //�����Ϸ��� ��� ����
            free(t);
            return data;
        }
        tmp = tmp->nextNode;
    }

    printf("�����Ͻ÷��� Data�� �������� �ʽ��ϴ�.\n"); //���� ��� �˻��� �ش� data�� �������� ������ ��°� -1 ����
    return -1;
}

int removeFirst(LINKEDLIST* Head)
{
    if (Head == NULL)
        return -1;// �� ����Ʈ�� ������ȯ

    LINKEDLIST* tmp = Head->nextNode;
    int returnData = tmp->data;

    Head->nextNode = tmp->nextNode;

    free(tmp);
    return returnData;
}

int removeLast(LINKEDLIST* Head)
{
    if (Head->nextNode == NULL)
        return -1;//��尡 ��������� ����

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
    return -1;//��ã���� ����
}
