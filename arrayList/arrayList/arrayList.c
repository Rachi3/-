#include "arrayList.h"

void Linit(ArrayList* L)
{
	(L->dataSize) = 0; // 만약 빈 리스트라면 현재 데이터 값 0으로 설정
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
	return (L->dataSize)==(arrSize-1)?1:-1;//리스트가 꽉찼다면 1 반환 그렇지 않으면 -1반환
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
	// 꽉찼는지 확인
	// 안찼다면 맨 마지막부터 앞으로 한칸씩 쭉 땡김
	// 빈칸에 넣고 개수 하나 늘려주기

	if (isFull(L) == 1)
		return e - 1;//문제발생 실행불가

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
