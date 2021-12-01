#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include <stdio.h>

//��ƽ����
 // Definition for a binary tree node.
  struct TreeNode {
     int val;
     struct TreeNode *left;
      struct TreeNode *right;
 };
 
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	//ǰ�򣬵�ǰ���Ͳ��ǣ������жϺ��������
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return (abs(leftDepth - rightDepth) < 2)
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}
bool _isBalanced(struct TreeNode* root, int* ph) {
	if (root == NULL)
	{
		*ph = 0;
		return true;
	}
	//�������ж����������ж�������
	int leftHeight = 0;
	if (_isBalanced(root->left, &leftHeight) == false)
	{
		return false;
	}
	int rightHeight = 0;
	if (_isBalanced(root->right, &rightHeight) == false)
	{
		return false;
	}
	//ͬʱ�ٰѵ�ǰ���ĸ߶ȴ�����һ��
	*ph = fmax(leftHeight, rightHeight) + 1;
	return abs(leftHeight - rightHeight) < 2;
}

bool isBalanced(struct TreeNode* root) {
	int height = 0;
	return _isBalanced(root, &height);
}


//�������Ĺ��������
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
	struct Treenode* left;
	struct Treenode* right;
	char val;
}TreeNode;

TreeNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}

	//����#��������
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = str[*pi];
	++(*pi);
	//�ݹ鹹��������
	root->left = CreateTree(str, pi);
	//�ݹ鹹��������
	root->right = CreateTree(str, pi);
	return root;
}
void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}
int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	TreeNode* root = CreateTree(str, &i);
	InOrder(root);
	printf("\n");
	return 0;
}

//�������������
int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void _postorder(struct TreeNode* root, int* arr, int* pi)
{
	if (root == NULL)
		return;

	_postorder(root->left, arr, pi);
	_postorder(root->right, arr, pi);
	arr[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(sizeof(int) * (*returnSize));
	int i = 0;
	_postorder(root, arr, &i);
	return arr;

}