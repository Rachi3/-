#include "arrayList.h"

void Linit(ArrayList* L)
{
	(L->dataSize) = 0; // ���� �� ����Ʈ��� ���� ������ �� 0���� ����
}

int Lsize(ArrayList* L)
{
	return L->dataSize;
}

int isEmpty(ArrayList* L)
{
	return (L->dataSize) == 0 ? 1 : -1;
}

int isFull(ArrayList* L)
{
	return (L->dataSize)==(arrSize-1)?1:-1;//����Ʈ�� ��á�ٸ� 1 ��ȯ �׷��� ������ -1��ȯ
}


int get(ArrayList* L, int r)
{
	return (L->data[r]);
}

void replace(ArrayList* L, int r, int e)
{
	(L->data[r]) = e;
}

int add(ArrayList* L, int r, int e)
{
	// ��á���� Ȯ��
	// ��á�ٸ� �� ���������� ������ ��ĭ�� �� ����
	// ��ĭ�� �ְ� ���� �ϳ� �÷��ֱ�

	if (isFull(L) == 1)
		return e - 1;//�����߻� ����Ұ�

	for (int i = L->dataSize; i > r; i--)
		L->data[i] = L->data[i - 1];

	L->data[r] = e;

	L->dataSize++;
	return e;
}

int addFirst(ArrayList* L,  int e)
{
	if (isFull(L)==1)
		return e - 1;
	
	for (int i = L->dataSize; i > 0; i--)
		L->data[i] = L->data[i - 1];

	L->data[0] = e;

	L->dataSize++;
	return e;
}

int addLast(ArrayList* L, int e)
{
	if (isFull(L) == 1)
		return e - 1;
	L->data[L->dataSize] = e;

	L->dataSize++;

	return 0;
}

int remove(ArrayList* L, int r)
{
	int k = L->data[r];
	if (isEmpty(L) == 1)
		return;

	for (int i = r; i < L->dataSize; i++)
		L->data[i] = L->data[i + 1];

	L->data[L->dataSize] = 0;
	L->dataSize--;
	return k;
}

int removeFirst(ArrayList* L)
{
	int k = L->data[0];
	if (isEmpty(L) == 1)
		return;

	for (int i = 0; i < L->dataSize; i++)
		L->data[i] = L->data[i + 1];

	L->data[L->dataSize] = 0;
	L->dataSize--;
	return k;
}

int removeLast(ArrayList* L)
{
	int k = L->data[L->dataSize];

	L->data[L->dataSize] = 0;

	L->dataSize--;


	return k;
}

void printList(ArrayList* L)
{
	for (int i = 0; i < L->dataSize; i++)
		printf("%d ", L->data[i]);

	printf("\n");
}
