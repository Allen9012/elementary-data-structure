#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 

