#pragma warning(disable:4996)

#include<stdio.h>
#include"LinkedList.h"


int main()
{
	LINKEDLIST* Head = Linit();//시작시 더미노드 만들어 Head에 연결하기

	AppendFirst(Head, 15);

	for (int i = 0; i < 5; i++)
		AppendFirst(Head, i);

	for (int i = 0; i < 5; i++)
		AppendLast(Head, i);

	
	Append(Head, 77, 4);
	printList(Head);
	printf("%d\n", returnNodeCnt(Head));
	return 0;
}
