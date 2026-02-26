#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

//返回节点的地址，方便创建二叉树的节点
BTNode* BuyNode(int x)
{
	//给节点申请空间
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->Data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	//返回节点地址
	return newnode;
}

//返回第一个节点的地址，创建其他子树的节点
BTNode* CreatBinaryTree()
{
	//创建每个节点、并赋值
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	//形成一棵树
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->right = node5;
	node4->left = node6;
	node5->right = node7;

	//返回首节点为
	return node1;
}

//前序遍历   根节点、左子树、右子树
void prevorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->Data);
	prevorder(root->left);
	prevorder(root->right);
}

//中序遍历   左子树、根节点、右子树
void inorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	prevorder(root->left);
	printf("%d ", root->Data);
	prevorder(root->right);
}

//后序遍历   左子树、右子树、根节点
void tailorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	prevorder(root->left);
	prevorder(root->right);
	printf("%d ", root->Data);
}

//查找二叉树节点
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//查找二叉树叶子节点
int TreeLeafSize(BTNode* root)
{
	//树为空
	if (root == NULL)
		return 0;
	
	//叶子节点，返回1
	if (root->left == NULL && root->right == NULL)
		return 1;

	//找不到，遍历二叉树
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//查找二叉树高度
int TreeHeight(BTNode* root)
{
	//树为空，高度为1
	if (root == NULL)
		return 1;

	//递归遍历，记录树两边的高度
	int leftcount = TreeHeight(root->left);
	int rightcount = TreeHeight(root->right);
	
	//比较两边高度(三目运算符)
	return 1 + (leftcount > rightcount ? leftcount : rightcount);
}

//查找第K层的节点个数
int TreeLeveKSize(BTNode* root, int k)
{
	//树为空
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	//子问题
	return TreeLeveKSize(root->left, k - 1) + TreeLeveKSize(root->right, k - 1);
}

//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	//树为空/子树左孩子为空
	if (root == NULL)
		return NULL;

	//找到节点
	if (root->Data == x)
		return root;

	//没找到，往左子树找
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	//左子树没找到，往右子树找
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	//都没找到返回NULL
	return NULL;
}

//二叉树的销毁
void TreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	//递归销毁
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
}

#include"Queue.h"
//层序遍历(广度优先遍历)
void TreeLevelOrder(BTNode* root)
{
	//定义一个队列
	Queue q;
	QueueInit(&q);

	//如果树不等于空，就把树放进去
	if (root)
		QueuePush(&q, root);

	//如果队列不等于空就继续
	//当等于空时，树的节点走完
	while (!QueueEmpty(&q))
	{
		//保存树节点的指针
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//取出来就要拿出来

		printf("%d ", front->Data);

		//然后把两个子树放进去
		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);
	}

	//用完则销毁队列
	QueueDestroy(&q);
}