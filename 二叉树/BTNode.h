#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#pragma once
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;


void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
BTNode* CreatTreeNode(BTDataType x);
//void TreeSize(BTNode* root,int *psize);
int TreeSize(BTNode* root);
int TreeLeafSize(BTNode* root);
int TreeKLevelSize(BTNode* root, int k);
BTNode* TreeFind(BTNode* root, BTDataType x);
//void TreeDestroy(BTNode**pproot);
void TreeDestroy(BTNode* root);
void TreeLevelOrder(BTNode* root);
bool BinaryTreeComplete(BTNode* root);

