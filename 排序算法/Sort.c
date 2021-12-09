#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void InsertSort(int *a,int sz)
{
	for (int i = 0; i < sz - 1; ++i)
	{
		//��tmp���뵽�����[0��end]����������
		int end=i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		//ѭ����������end==-1
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int sz)
{ 
	//gap>1��ʱ��Ԥ����
	//gap==1��ʱ��ֱ�Ӳ�������
	int gap=sz;
	while (gap > 1)
	{
		gap = (gap / 3+1);//��֤���һ����1
		for (int i = 0; i < sz - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
} 
 
void SelectSort(int* a, int sz)
{
	int left = 0, right = sz - 1;
	while (left<right)
	{
		//�ҳ�=���ĺ���С��
		int minIndex = left, maxIndex = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
		}
		Swap(&a[left], &a[minIndex]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);
		++left;
		--right;
	}
}

void AdjustDown(int* a, int sz,int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < sz)
	{
		if (child + 1 < sz && a[child + 1] > a[child])//�ȼ���ٷ���
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//�Ѿ�С�˾�ֱ������ѭ��  
		}
	}
}

void HeapSort(int *a,int sz)
{
	for (int i = (sz - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, sz, i);//���µ�����һ�����
	}
	int end = sz - 1;//ͷ�ŵ���󣬴δ�ķŵ������ڶ�������
	while(end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void BubbleSort(int* a, int sz)
{
	for (int j = 0; j < sz; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i], &a[i - 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}

//Hoare��
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);//���ⲽleft���ֵ����ʹͷ��β���м�ֵ
	int keyi = left;
	while (left < right)
	{
		//�Ҵ�
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		//��С
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);//��󽻻�һ��key��ֵ��������ֵ
	return left;
}

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	while (left < right)
	{//��С
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//�ŵ���ߵĿ��У��ұ��γ��µĿ�
		a[left] = a[right];
		//�Ҵ�
		while (left < right && a[left] <= key)
		{
			++left;
		}
		//�ŵ��ұߵĿ��У�����γ��µĿ�
		a[right] = a[left];
	}
	a[left] = key;
	return left; 
}

int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);//���ⲽleft���ֵ����ʹͷ��β���м�ֵ
	int prev = left;
	int cur = left+1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi]&&++prev!=cur)
		{
			Swap(&a[left], &a[right]);
		}
		++cur;//�������߽���֮��Ҫ������
	}
	Swap(&a[keyi], &a[prev]);
	return prev;//���طָ���ֵ 
}

//�Ż�Hoare��ǰ��ָ���ṩ����ȡ�з�
int GetMidIndex(int* a, int left, int right)
{//�ҳ�ͷβ���м��Ǹ����������е��м���
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = PartSort1(a, begin, end);//��keyֵ
	//��[begin,meeti-1] ��[meeti+1,end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

//С�����Ż�
//void QuickSort(int* a, int begin, int end)
//{
//
//
//	if (begin >= end)
//	{
//		return;
//	}
//	//1.���������������ݶ࣬����ѡkey���ˣ��ָ�������
//	//2.���������������̫С����ȥ�ݹ鲻���ʣ�������
//	if (end - begin > 10)
//	{
//		int keyi = PartSort3(a, begin, end);
//		//��[begin,meeti-1] ��[meeti+1,end]
//		QuickSort(a, begin, keyi - 1);
//		QuickSort(a, keyi + 1, end);
//	}
//	else
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//}


void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int left, right;
		right = StackTop(&st);
		StackPop(&st);

		left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, left, right);
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}

	StackDestroy(&st);
}

void _MergeSort(int* a, int left,int right,int *tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	//[left,mid] [mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	
	//��������������鲢tmp����������ȥ
	int begin1 = left,end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1<=end1&&begin2<=end2){
		if (a[begin1] < a[begin2]){
			tmp[i++] = a[begin1++];
		}else{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1){
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2){
		tmp[i++] = a[begin2++];
	}
	//�鲢��֮�󣬿���ԭ����
	for (int j = left; j <= right; ++j)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int* a, int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, sz - 1,tmp);
	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (tmp == NULL){
		printf("malloc fail\n");
		exit(-1);
	}
	int left;
	int right;
	int gap = 1;
	while (gap < sz){
		for (int i = 0; i < sz; i += (2 * gap)){
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//�ڶ������䲻���ھͲ���Ҫ�鲢�ˣ�����ѭ��
			if (begin2>=sz){
				break;
			}
			//�ڶ���С������ڣ����ǵڶ���С���䲻��gap��������λ��Խ�磬��Ҫ����
			if (end2 >= sz){
				end2 = sz - 1;
			}
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			left = begin1;
			right = end2;
			int index = begin1;
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] < a[begin2]) {
					tmp[index++] = a[begin1++];
				}
				else {
					tmp[index++] = a[begin2++];
				}
			}
			//�ߵ�����һ����һ��û������
			while (begin1 <= end1) {
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2) {
				tmp[index++] = a[begin2++];
			}
			//�鲢��֮�󣬿���ԭ����
			for (int j = left; j <=right; ++j)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}
void CountSort(int* a, int sz)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < sz; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* count = (int *)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < sz; i++)
	{
		count[a[i] - min]++;
	}
	int i = 0;
	for (int j = 0; j < range; ++j)
	{
		while (count[j]--)
		{
			a[i++] = j+min;
		}
	}
}
void PrintArray(int* a, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}