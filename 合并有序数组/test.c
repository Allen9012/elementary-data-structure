#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//�Ӻ���ǰ��һ�����ȴ�С����
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])//1��
		{
			nums1[end--] = nums1[end1--];
		}
		else//2��
		{
			nums1[end--] = nums2[end2--];
		}
	}
	//����һ�������num1�����ˣ�num2û��

	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}

}