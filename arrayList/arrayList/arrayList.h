#pragma once

#include<stdio.h>

#define False 0
#define True 1

#define arrSize 100


// ����Ʈ ����
typedef struct __arraylist {
	int data[arrSize];//�����͸� ������ �迭
	int dataSize; // ���� �������� ����
}ArrayList;

// ����Ʈ �Լ���
//init() - ����Ʈ ����

void Linit(ArrayList* L);

//size() - ����Ʈ�� ũ��, �� ���Ҽ� ��ȯ
int Lsize(ArrayList* L);

int isEmpty(ArrayList* L);
int isFull(ArrayList* L);

int get(ArrayList* L, int r);
void replace(ArrayList* L, int r, int e);

int add(ArrayList* L, int r, int e);
int addFirst(ArrayList* L, int r, int e);
int addLast(ArrayList* L, int r, int e);

int remove(ArrayList* L, int r);
int removeFirst(ArrayList* L);
int removeLast(ArrayList* L);


