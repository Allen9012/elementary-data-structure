#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
// 单值树
bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	if (root->left && root->left->val != root->val)//保证左值不空和左儿子不等于父亲
	{
		return false;
	}
	if (root->right && root->right->val != root->val)
	{
		return false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}


//相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}
//对称的树
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right) {
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
	{
		return false;
	}
	if (left->val != right->val)
	{
		return false;
	}
	return _isSymmetric(left->left, right->right)
		&& _isSymmetric(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	return _isSymmetric(root->left, root->right);
}
//翻转二叉树
struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL)
	{
		return NULL;
	}
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
	//遍历这一棵树的每一个节点
	if (root == NULL)
	{
		return false;
	}
	if (isSameTree(root, subRoot))
	{
		return true;
	}
	return isSubtree(root->left, subRoot) ||
		isSubtree(root->right, subRoot);//一棵子树相等就ok了

}