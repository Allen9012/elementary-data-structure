#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int removeDublicate(int *nums,int numsize)
{
	int src =0;
	int dst = 0;
	if (numsize == 0)
	{
		return 0;
	}
	while (src < numsize)
	{
		if (nums[src] == nums[dst])
		{
			src++;
		}
		else
		{
			dst++;
			nums[dst] = nums[src];
			src++;
		}
	}
	return dst + 1;
}