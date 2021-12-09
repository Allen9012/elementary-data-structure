#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "Stack.h"
void InsertSort(int* a, int sz);
void ShellSort(int* a, int sz);
void PrintArray(int* a, int sz);
void SelectSort(int *a,int sz);
void AdjustDown(int* a, int sz, int root);
void HeapSort(int* a, int sz);
void Swap(int* p1, int* p2);
void BubbleSort(int* a, int sz);
void QuickSort(int* a, int begin,int end);
int PartSort1(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int GetMidIndex(int* a, int left, int right);
int PartSort3(int* a, int left, int right);
void QuickSortNonR(int* a, int begin, int end);
void MergeSort(int* a, int sz);
void _MergeSort(int* a, int left, int right, int* tmp );
void MergeSortNonR(int* a, int sz);
void CountSort(int *a,int sz);
