#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//从后往前走一个个比大小放入
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])//1大
		{
			nums1[end--] = nums1[end1--];
		}
		else//2大
		{
			nums1[end--] = nums2[end2--];
		}
	}
	//还有一种情况是num1走完了，num2没有

	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}

}