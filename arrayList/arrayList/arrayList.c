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
