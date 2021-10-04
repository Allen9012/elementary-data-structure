#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
//
// 静态的
//#define N 10;
//struct SeqList
//{
//	int a[N];
//	int size;
//};

//动态的
typedef int  SeqDataType;
//typedef ContactInfo SeqDataType;
typedef struct SeqList
{
	SeqDataType* a;//顺序表数组
	int size;//有效数据
	int capacity;//容量
} SeqList,SEQ;

//内存中管理数据结构的增删查改
void SeqListInit(SeqList* pq);
void SeqListDestroy(SeqList* pq);
void SeqListPrint(SeqList* pq);
//头插尾插，头删尾删
void SeqCheckCapacity(SeqList* pq);
void SeqListPushBack(SeqList* pq, SeqDataType x);//一般stl用push来表示insert
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPopFront(SeqList* pq);