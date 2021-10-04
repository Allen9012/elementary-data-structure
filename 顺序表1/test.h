#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
//
// ��̬��
//#define N 10;
//struct SeqList
//{
//	int a[N];
//	int size;
//};

//��̬��
typedef int  SeqDataType;
//typedef ContactInfo SeqDataType;
typedef struct SeqList
{
	SeqDataType* a;//˳�������
	int size;//��Ч����
	int capacity;//����
} SeqList,SEQ;

//�ڴ��й������ݽṹ����ɾ���
void SeqListInit(SeqList* pq);
void SeqListDestroy(SeqList* pq);
void SeqListPrint(SeqList* pq);
//ͷ��β�壬ͷɾβɾ
void SeqCheckCapacity(SeqList* pq);
void SeqListPushBack(SeqList* pq, SeqDataType x);//һ��stl��push����ʾinsert
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPopFront(SeqList* pq);