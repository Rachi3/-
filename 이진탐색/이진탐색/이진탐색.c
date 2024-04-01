#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[], int arrLen,int Target);
void printArr(int arr[], int arrLen);
void serArrRandom(int arr[], int arrLen);
void sortArr(int arr[], int arrLen);

int main()
{	
    int random_number;

    // srand() �Լ��� ����Ͽ� ���� �߻��⸦ �ʱ�ȭ
    //srand(time(NULL)); // seed ���� ���� �ð����� ����

 
    int arr[10] = { 0 }, N = 10, target = 0;

    serArrRandom(arr, N);
    sortArr(arr, N);
    printArr(arr, N);
    // 1~100������ ������ �迭 �������� ä���

    printf("����� ã�� ���� �����ΰ���? : ");
    scanf("%d",&target);

    target=BinarySearch(arr, N, target);
	
    if (target == -1)
        printf("����� ã�� ���� ���� �迭�� �������� �ʽ��ϴ�.\n");
    else
        printf("����� ã�� ���� �迭 �ε��� %d�� ����Ǿ� �ֽ��ϴ�.",target);

    return 0;
}

int BinarySearch(int arr[], int arrLen,int Target)
{
    int idx = arrLen / 2;

    while (idx > 0 && idx < arrLen)
    {
        if (arr[idx] == Target)
            return idx;
        else if (arr[idx] > Target)
            idx = idx / 2;
        else
            idx = (arrLen + idx) / 2;
    }
    return -1;
}

void printArr(int arr[], int arrLen)
{
    for(int i=0;i<arrLen;i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

void serArrRandom(int arr[], int arrLen)
{
    for(int i=0;i<arrLen;i++)
        arr[i] = rand() % 100 + 1;
}

void sortArr(int arr[], int arrLen)
{
    int tmp = 0;

    for(int i=0;i<arrLen-1;i++)
        for (int j = 0; j < arrLen - 1 - i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
}
