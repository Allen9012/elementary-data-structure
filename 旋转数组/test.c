#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void rotate(int* nums, int numsSize, int k) {
	int tmp = 0;
	while (k >= numsSize)
	{
		k %= numsSize;
	}
	for (int i = 0; i < k; i++)
	{
		tmp = nums[numsSize - 1];
		for (int j = 0; j < numsSize - 1; j++)
		{
			nums[numsSize - 1-j] = nums[numsSize - 2-j];
		}
		nums[0] = tmp;
	}
}
void reverse(int* num, int left, int right)
{
	while (left < right)
	{
		int tmp = num[left];
		num[left] = num[right];
		num[right] = tmp;
		++left; 
		--right;
	}

}
void rotate3(int* nums, int numsSize, int k)
{
	while (k >= numsSize)
	{
		k %= numsSize;
	}
	reverse(nums, 0, numsSize - k - 1);//前k个数
	reverse(nums, numsSize-k, numsSize-1);//后k个数
	reverse(nums, 0, numsSize- 1);//整个数组
}
void rotate2(int *nums, int numsSize,int  k)
{
	int newArr[numsSize];
	for (int i = 0; i < numsSize; i++)
	{ 
		newArr[(i + k) % numsSize] = nums[i];
	}
	for (int i = 0; i < numsSize; i++)
	{
		nums[i] = newArr[i];
	}
}
int main()
{
	int nums[] = { -1,-100,3,99 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = 2;
	/*rotate(nums, numsSize, k);*/
	/* rotate3(nums,numsSize,k);*/
	rotate2(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}