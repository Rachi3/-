#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[], int low, int high, int Target);
void printArr(int arr[], int arrLen);
void serArrRandom(int arr[], int arrLen);
void sortArr(int arr[], int arrLen);

int main()
{	
    int random_number;

    // srand() 함수를 사용하여 난수 발생기를 초기화
    srand(time(NULL)); // seed 값을 현재 시간으로 설정

 
    int arr[10] = { 0 }, N = 10, target = 0;

    serArrRandom(arr, N);
    sortArr(arr, N);
    printArr(arr, N);
    // 1~100까지의 난수로 배열 무작위로 채우기

    printf("당신이 찾는 값은 무엇인가요? : ");
    scanf("%d",&target);

    target=BinarySearch(arr,0, N, target);
	
    if (target == -1)
        printf("당신이 찾던 값은 현재 배열에 존재하지 않습니다.\n");
    else
        printf("당신이 찾던 값은 배열 인덱스 %d에 저장되어 있습니다.",target);

    return 0;
}

int BinarySearch(int arr[], int low,int high ,int Target)
{
 

    while (low<=high)
    {
        int mid = (low + (high - low) / 2);

        if (arr[mid] == Target)
            return mid;
        else if (arr[mid] > Target)
            high = mid - 1;
        else
            low = mid + 1;//어차피 값이 복사되어 오는것이기 때문에 그냥 바로 사용함
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
