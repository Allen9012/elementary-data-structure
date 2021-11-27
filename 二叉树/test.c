#define _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"


int main()
{
	//手动构建
	BTNode* A = CreatTreeNode('A');
	BTNode* B = CreatTreeNode('B');
	BTNode* C = CreatTreeNode('C');
	BTNode* D = CreatTreeNode('D');
	BTNode* E = CreatTreeNode('E');
	BTNode* F = CreatTreeNode('F');
	A->left = B;  
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;
	//PrevOrder(A);
	//printf("\n");

	//InOrder(A);
	//printf("\n");

	//PostOrder(A);
	//printf("\n");
	/*int size = 0;
	TreeSize(A, &size);
	printf("TreeSize:%d\n",size);*/
	//int ret=TreeSize(A);
	//printf("TreeSize:%d \n", ret);
	//printf("TreeLeafSize:%d\n", TreeLeafSize(A)); 
	/*printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(A, 3));
	printf("TreeFind:%p\n", TreeFind(A, 'E'));
	printf("TreeFind:%p\n", TreeFind(A, 'X'));*/
	TreeLevelOrder(A);
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A));
	TreeDestroy(A);
	A = NULL;
	return 0;
}