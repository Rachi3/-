#pragma warning(disable:4996)

#include<stdio.h>
#include"LinkedList.h"


int main()
{
	LINKEDLIST* Head = Linit();//���۽� ���̳�� ����� Head�� �����ϱ�
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
	printf("������\n");
	printList(Head);
	printf("%d\n", returnNodeCnt(Head));

	printf("ã���ô� ������ �����Ű���? ");
	scanf("%d", &N);
	
	idx = search(Head, N);
	if (idx==-1)
		printf("ã���ô� data�� �������� �ʽ��ϴ�.\n");
	else
		printf("ã���ô� data�� %d�� %d ��° node�� �����մϴ�.\n",N,idx);
	return 0;
}
