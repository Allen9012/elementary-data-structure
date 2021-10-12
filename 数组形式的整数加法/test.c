#define _CRT_SECURE_NO_WARNINGS 1
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。
//
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/add-to-array-form-of-integer
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<stdio.h>
int* addToArrayForm(int* A, int ASize, int k, int* returnSize) {
	//先算ksize
	int kSize = 0;
	int num = k;

	while (num)
	{
		++kSize;
		num /= 10;
	}
	int len = kSize > ASize ? kSize + 1 : ASize + 1;
	int *retArr = (int*)malloc(sizeof(int)*len);
	//取位
	int Ai = ASize - 1;
	int Ki = 0;
	int next = 0;//进位
	int reti=0;
	//要求Ai 和Ki都走完结束
	while (Ai >= 0 || Ki <kSize)
	{
		int aval = 0;
		if (Ai >= 0)//判断防止数组越界
		{
			aval = A[Ai];
		}
		int kval = k % 10;//0%10还是0可以直接赋值
		k /= 10;
		Ai--;
		++Ki;
		int ret = aval + kval+next;
		//处理进位
		if (ret >= 10)
		{
			next = 1;
			ret -= 10;
		}
		else 
		{
			next = 0;
		}
		retArr[reti++] = ret;
	}
	if (next == 1)
	{
		retArr[reti++] = 1;
	}
	//数组倒置
	int begin = 0, end = reti - 1;
	while (begin < end)
	{
		int tmp = retArr[begin];
		retArr[begin] = retArr[end];
		retArr[end] = tmp;
		++begin;
		--end;
	}
	*returnSize = reti;
	return retArr;

}