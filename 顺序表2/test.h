#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>


//动态的
typedef int  SeqDataType;
//typedef ContactInfo SeqDataType;
typedef struct SeqList
{
	SeqDataType* a;//顺序表数组
	int size;//有效数据
	int capacity;//容量
} SeqList, SEQ;

//内存中管理数据结构的增删查改

// 头插尾插，头删尾删
void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);
void SeqListPrint(SeqList* pq);

//void SeqListPushBack(SEQ seq, SeqDataType x);
void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPopFront(SeqList* pq);
int SeqListFind(SeqList* pq, SeqDataType x);
void SeqListInsert(SeqList* pq, int pos, SeqDataType x);//中间插入
void SeqListErase(SeqList* pq, int pos);//中间删除
void SeqListModify(SeqList* pq, int pos, SeqDataType x);//中间改内容
