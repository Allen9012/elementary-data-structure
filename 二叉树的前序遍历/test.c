#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _preorder(struct TreeNode* root, int* arr, int* pi)
{
	if (root == NULL)
		return;
	arr[(*pi)++] = root->val;
	_preorder(root->left, arr, pi);
	_preorder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(sizeof(int) * (*returnSize));
	int i = 0;
	_preorder(root, arr, &i);
	return arr;
}