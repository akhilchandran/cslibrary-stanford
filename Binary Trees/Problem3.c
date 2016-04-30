#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
}; 

int maxDepth(struct node *binaryTree)
{
        if(binaryTree == NULL){
                return 0;
        }
        int leftDepth = maxDepth(binaryTree->left);
	int rightDepth = maxDepth(binaryTree->right);
	
	if(leftDepth > rightDepth)
		return leftDepth + 1;
	else
		return rightDepth + 1;
}

struct node *NewNode(int data) {
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

struct node *insert(struct node *node, int data)
{
	if(node == NULL){
		return(NewNode(data));
	}else{
		if(data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
	}
}

struct node *build123456()
{
	struct node *root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	return root;
}

main()
{
	struct node *root = build123456();
        printf("%d\n", maxDepth(root));
}
	
