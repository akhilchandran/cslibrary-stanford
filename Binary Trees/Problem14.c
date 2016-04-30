/*
Q:	Write an isBST() function that returns true if a tree is a binary
	search tree and false otherwise using recursion.
 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define false 0
#define true 1

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int isBSTRec(struct node *treehead, int *min, int *max)
{
	int leftstate = true;
	int rightstate = true;
	if(min != NULL){
		if(treehead->data < *min)
			return false;
	}
	if(max != NULL){
		if(treehead->data > *max)
			return false;
	}
	if(treehead->left != NULL)
		leftstate = isBSTRec(treehead->left, min, &treehead->data);
	if(treehead->right != NULL)
		rightstate = isBSTRec(treehead->right, &treehead->data, max);
	return leftstate && rightstate;
	
}
int isBST(struct node *binaryTree)
{
	return isBSTRec(binaryTree, NULL, NULL);
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

struct node *build201_5_156()
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
struct node *builda()
{
	struct node *left = NewNode(2);
	struct node *right = NewNode(7);
	struct node *root = NewNode(5);
	root->left = left;
	root->right = right;
	return root;
}
struct node *buildb()
{
	struct node *left = NewNode(6);
	struct node *right = NewNode(7);
	struct node *root = NewNode(5);
	root->left = left;
	root->right = right;
	return root;
}
struct node *buildc()
{
	struct node *left = NewNode(1);
	struct node *root = NewNode(2);
	root->left = left;
	left = root;
	struct node *right = NewNode(7);
	root = NewNode(5);
	root->left = left;
	root->right = right;
	return root;
}

struct node *buildd()
{
	struct node *left = NewNode(1);
	struct node *right = NewNode(6);
	struct node *root = NewNode(2);
	root->left = left;
	root->right = right;
	left = root;
	right = NewNode(7);
	root = NewNode(5);
	root->left = left;
	root->right = right;
	return root;
}

main()
{
	printf("The Binary Tree case 'a' is %s\n",isBST(builda())? "a BST":"not a BSD");
	printf("The Binary Tree case 'b' is %s\n",isBST(buildb())? "a BST":"not a BSD");
	printf("The Binary Tree case 'c' is %s\n",isBST(buildc())? "a BST":"not a BSD");
	printf("The Binary Tree case 'd' is %s\n",isBST(buildd())? "a BST":"not a BSD");
}