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
