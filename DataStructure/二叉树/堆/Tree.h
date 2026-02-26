#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BTDataType;

//二叉链
typedef struct BinaryTreeNode
{
	BTDataType Data;              //数据域
	struct BinaryTreeNode* left;  //指向当前左孩子节点
	struct BinaryTreeNode* right; //指向当前右孩子节点
}BTNode;

//返回节点的地址，方便创建二叉树的节点
BTNode* BuyNode(int x);

//返回第一个节点的地址，创建其他子树的节点
BTNode* CreatBinaryTree();

//前序遍历   根节点、左子树、右子树
void prevorder(BTNode* root);

//中序遍历   左子树、根节点、右子树
void inorder(BTNode* root);

//后序遍历   左子树、右子树、根节点
void tailorder(BTNode* root);

//查找二叉树节点
int TreeSize(BTNode* root);

//查找二叉树叶子节点
int TreeLeafSize(BTNode* root);

//查找二叉树高度
int TreeHeight(BTNode* root);

//查找第K层的节点个数
int TreeLeveKSize(BTNode* root, int k);

//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x);

//二叉树的销毁
void TreeDestory(BTNode* root);

//层序遍历(广度优先遍历)
void TreeLevelOrder(BTNode* root);