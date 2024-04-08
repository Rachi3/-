#pragma warning(disable:4996)

#include<stdio.h>
#include"LinkedList.h"


int main()
{
	LINKEDLIST* Head = Linit();//시작시 더미노드 만들어 Head에 연결하기
	int idx = 0, N = 0;
	AppendFirst(Head, 15);

	for (int i = 0; i < 5; i++)
		AppendFirst(Head, i);

	for (int i = 0; i < 5; i++)
		AppendLast(Head, i);

	
	Append(Head, 77, 4);
	printList(Head);
	printf("%d\n", returnNodeCnt(Head));

	removeLast(Head);
	printf("삭제후\n");
	printList(Head);
	printf("%d\n", returnNodeCnt(Head));

	printf("찾으시는 데이터 있으신가요? ");
	scanf("%d", &N);
	
	idx = search(Head, N);
	if (idx==-1)
		printf("찾으시는 data는 존재하지 않습니다.\n");
	else
		printf("찾으시는 data인 %d는 %d 번째 node에 존재합니다.\n",N,idx);
	return 0;
}
