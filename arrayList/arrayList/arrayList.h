#pragma once

#include<stdio.h>

#define False 0
#define True 1

#define arrSize 100


// 리스트 정의
typedef struct __arraylist {
	int data[arrSize];//데이터를 저장할 배열
	int dataSize; // 현재 데이터의 개수
}ArrayList;

// 리스트 함수들
//init() - 리스트 생성

void Linit(ArrayList* L);

//size() - 리스트의 크기, 즉 원소수 반환
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


