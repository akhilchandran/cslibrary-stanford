/*
Q:	For each node in a binary search tree, create a new duplicate node,
	and insert the duplicate as the left child of the original node. The
	resulting tree should still be a binary search tree. 
 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *NewNode(int data);
void doubleTree(struct node *binaryTree)
{
        if(binaryTree == NULL){
		return;
	}
	doubleTree(binaryTree->left);
	doubleTree(binaryTree->right);
	struct node *newleftnode =  NewNode(binaryTree->data);
	newleftnode->left = binaryTree->left;
	binaryTree->left = newleftnode;
	return;
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

struct node *build20_5_156()
{
	struct node *root = NULL;
	root = insert(root, 2);
	root = insert(root, 0);
	root = insert(root, 1);
	root = insert(root, -5);
	root = insert(root, -1);
	root = insert(root, 5);
	root = insert(root, 6);
	return root;
}

main()
{
	struct node *root = build20_5_156();
	doubleTree(root);
}