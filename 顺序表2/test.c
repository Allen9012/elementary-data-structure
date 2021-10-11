#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
//void TestSeqList1()
//{
//	SeqList s;
//	SeqListInit(&s);
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPushBack(&s, 3);
//	SeqListPushBack(&s, 4);
//	SeqListPushBack(&s, 5);
//	SeqListPushFront(&s, 0);
//	SeqListPushFront(&s, 0);
//	SeqListPushFront(&s, 0);
//	SeqListPushFront(&s, 0);
//	SeqListPrint(&s);
//
//	SeqListPopBack(&s);
//	SeqListPrint(&s);
//	SeqListPopBack(&s);
//	SeqListPrint(&s);
//
//	SeqListPopFront(&s);
//	SeqListPrint(&s);
//	SeqListPopFront(&s);
//	SeqListPrint(&s);
//
//	SeqListDestroy(&s);
//}
void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListInsert(&s, 2, 30);
	SeqListPrint(&s);
	SeqListErase(&s, 2);
	SeqListPrint(&s);
	SeqListInsert(&s, 0, 30);
	SeqListPrint(&s);
	SeqListErase(&s, 0);
	SeqListPrint(&s);
	SeqListModify(&s, 2, 5);
	SeqListPrint(&s);

	SeqListDestroy(&s);
}

void menu()
{
	printf("******************************************\n");
	printf("1、尾插数据  2、头插数据\n");
	printf("3、尾删数据  4、头删数据\n");
	printf("5、查找数据  6、打印数据\n");
	printf("0、退出\n");
	printf("******************************************\n");
}

int main()
{
	//TestSeqList1();
	
	int option = 0;
	SeqList s;
	SeqListInit(&s);
	//TestSeqList2();
	do {
		menu();
		scanf("%d", &option);
		int x;
		int ret = 0;
		switch (option)
		{
		case 1:
						printf("请输入数据，以-1结束:");
						while (1)
						{
							scanf("%d", &x);
							if (x == -1)
								break;
		
							SeqListPushBack(&s, x);
						}
						break;
					case 2:
						printf("请输入数据，以-1结束:");
						while (1)
						{
							scanf("%d", &x);
							if (x == -1)
								break;

							SeqListPushFront(&s, x);
						}
						break;
					case 3:
						SeqListPopBack(&s);
						break;
					case 4:
						SeqListPopFront(&s);
						break;
					case 5:
						printf("请输入你要找的数字：\n");
					
							scanf("%d", &x);
							ret = SeqListFind(&s, x);
							if (ret != -1)
							{
								printf("we find the designated number in the Seqlist\n");
								printf("该元素在第%d位\n", ret+1);
								break;
							}
							else
							{
								printf("没找到该元素\n");
							}
						break;
					case 6:
						SeqListPrint(&s);
						break;
					default:
						break;
				
		}
	} while (option != 0);
	
	return 0;
} 