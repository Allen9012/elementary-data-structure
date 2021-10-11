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
	printf("1��β������  2��ͷ������\n");
	printf("3��βɾ����  4��ͷɾ����\n");
	printf("5����������  6����ӡ����\n");
	printf("0���˳�\n");
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
						printf("���������ݣ���-1����:");
						while (1)
						{
							scanf("%d", &x);
							if (x == -1)
								break;
		
							SeqListPushBack(&s, x);
						}
						break;
					case 2:
						printf("���������ݣ���-1����:");
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
						printf("��������Ҫ�ҵ����֣�\n");
					
							scanf("%d", &x);
							ret = SeqListFind(&s, x);
							if (ret != -1)
							{
								printf("we find the designated number in the Seqlist\n");
								printf("��Ԫ���ڵ�%dλ\n", ret+1);
								break;
							}
							else
							{
								printf("û�ҵ���Ԫ��\n");
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