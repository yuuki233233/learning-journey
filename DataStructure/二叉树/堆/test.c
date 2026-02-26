#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

int main()
{
	BTNode* root = CreatBinaryTree();
	/*prevorder(root);
	printf("\n");
	printf("TreeSize = %d\n", TreeSize(root));
	printf("TreeLeafSize = %d\n", TreeLeafSize(root));
	printf("treeHeight = %d\n", TreeHeight(root));
	printf("\n");*/

	TreeLevelOrder(root);
	printf("\n");

	TreeDestory(root);
	root = NULL;

	return 0;
}