#define _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"
void PrevOrder(BTNode* root)
{
	//区分空树
	//递归要有子问题和结束条件
	//根->左子树->右子树
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
BTNode* CreatTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//int size = 0;
// //思路1
//void TreeSize(BTNode* root,int* psize)
//{ 
//	if (root == NULL)
//	{
//		return ;
//	}
//	//int size = 0;//全局变量不行，第一次和第二次输出不一样，多线程也不行
//	//static int size = 0;//也不行
//	++(*psize);
//	TreeSize(root->left,psize);
//	TreeSize(root->right,psize);
//	//于是试一下传个参数进来++ ，还是不行，因为传过去了之后还是拷贝
//}

//思路2
//递归，拆解子问题，一个个向左和右拆解问题
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : 
		TreeSize(root->left)
		+TreeSize(root->right)
		+1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	}
	
}
//k>0
int TreeKLevelSize(BTNode* root, int k)//第k层节点的个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL){
		return NULL;
	}
	if (root->data == x){
		return root;
	}
	//左边的结果决定我要不要到右边去找
	BTNode* lret=TreeFind(root->left,x);
	if (lret){
		return lret;
	}
	BTNode* rret = TreeFind(root->right, x);
	if (rret){
		return rret;
	}
	return NULL;
}
//利用后序销毁
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}
//void TreeDestroy(BTNode**pproot)
//{
//	if (*pproot == NULL)
//	{
//		return;
//	}
//	TreeDestroy(&(*pproot)->left);
//	TreeDestroy(&(*pproot)->right);
//	free(*pproot);
//	*pproot = NULL;
//}

void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//注意在队列得放节点才能拿到左孩子和右孩子
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	} 
	QueueDestroy(&q);
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root){
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q)){
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL){//遇到第一个空的时候break
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q)){
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)//只要由一个非空就return false
			return false;
	}
	QueueDestroy(&q);
	return true;
}