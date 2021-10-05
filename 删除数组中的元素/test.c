#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val) {
	/*int *dst = &nums[0];
	int *src = &nums[0];
	int i = 0;
	for (; i < numsSize; i++)
	{
		if (nums[i] == val)
		{
			src++;
		}
		else
		{
			*dst == *src;
			dst++;
			src++;
		}
	}
	return *dst;*/
	int src = 0, dst = 0;
	while (src < numsSize)
	{
		if (nums[src] == val)
		{
			++src;
		}
		else
		{
			nums[dst] = nums[src];
			++src;
			++dst;
		}
	}
	return dst;
}