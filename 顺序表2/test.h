#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>


//��̬��
typedef int  SeqDataType;
//typedef ContactInfo SeqDataType;
typedef struct SeqList
{
	SeqDataType* a;//˳�������
	int size;//��Ч����
	int capacity;//����
} SeqList, SEQ;

//�ڴ��й������ݽṹ����ɾ���

// ͷ��β�壬ͷɾβɾ
void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);
void SeqListPrint(SeqList* pq);

//void SeqListPushBack(SEQ seq, SeqDataType x);
void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPopFront(SeqList* pq);
int SeqListFind(SeqList* pq, SeqDataType x);
void SeqListInsert(SeqList* pq, int pos, SeqDataType x);//�м����
void SeqListErase(SeqList* pq, int pos);//�м�ɾ��
void SeqListModify(SeqList* pq, int pos, SeqDataType x);//�м������
