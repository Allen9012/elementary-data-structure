#define _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"
void PrevOrder(BTNode* root)
{
	//���ֿ���
	//�ݹ�Ҫ��������ͽ�������
	//��->������->������
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
// //˼·1
//void TreeSize(BTNode* root,int* psize)
//{ 
//	if (root == NULL)
//	{
//		return ;
//	}
//	//int size = 0;//ȫ�ֱ������У���һ�κ͵ڶ��������һ�������߳�Ҳ����
//	//static int size = 0;//Ҳ����
//	++(*psize);
//	TreeSize(root->left,psize);
//	TreeSize(root->right,psize);
//	//������һ�´�����������++ �����ǲ��У���Ϊ����ȥ��֮���ǿ���
//}

//˼·2
//�ݹ飬��������⣬һ����������Ҳ������
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
int TreeKLevelSize(BTNode* root, int k)//��k��ڵ�ĸ���
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
	//��ߵĽ��������Ҫ��Ҫ���ұ�ȥ��
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
//���ú�������
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
	//ע���ڶ��е÷Žڵ�����õ����Ӻ��Һ���
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
		if (front == NULL){//������һ���յ�ʱ��break
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q)){
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)//ֻҪ��һ���ǿվ�return false
			return false;
	}
	QueueDestroy(&q);
	return true;
}