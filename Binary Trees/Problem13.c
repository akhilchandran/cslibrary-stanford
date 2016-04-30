/*
Q:	Suppose you have helper functions minValue() and maxValue() that 
	return the min or max int value from a non-empty tree. Write an
	isBST() function that returns true if a tree is a binary search
	tree and false otherwise
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

int recursivemin(struct node *binaryTree)
{
	int min = binaryTree->data, min1, min2;
	if(binaryTree == NULL)
		assert(0);
	if(binaryTree->left != NULL){
		min1 = recursivemin(binaryTree->left);
		if(min1 < min)
			min = min1;
	}
	if(binaryTree->right != NULL){
		min2 = recursivemin(binaryTree->right);
		if(min2 < min)
			min = min2;
	}
	return min;
}
int recursivemax(struct node *binaryTree)
{
	int max = binaryTree->data, max1, max2;
	if(binaryTree == NULL)
		assert(0);
	if(binaryTree->left != NULL){
		max1 = recursivemax(binaryTree->left);
		if(max1 > max)
			max = max1;
	}
	if(binaryTree->right != NULL){
		max2 = recursivemax(binaryTree->right);
		if(max2 > max)
			max = max2;
	}
	return max;
}

int isBST(struct node *binaryTree)
{
	if(binaryTree == NULL)
		return true;	
	if(binaryTree->left != NULL){
		if (binaryTree->data < recursivemax(binaryTree->left))
			return false;
	}
	if(binaryTree->right != NULL){
		if (binaryTree->data >= recursivemin(binaryTree->right))
			return false;
	}
	return (isBST(binaryTree->left) && isBST(binaryTree->right));
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