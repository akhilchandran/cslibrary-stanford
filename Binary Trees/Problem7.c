/*
Q:	Given a binary tree and a sum, return true if the tree has a root-to-leaf path such that adding up all the
	values along the path equals the given sum. Return false if no such path can be found

 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int hasPathsum(struct node *binaryTree, int sum)
{
	sum = sum - binaryTree->data;
        if(binaryTree->left == NULL && binaryTree->right == NULL){
                return (sum == 0);
	}
	if(binaryTree->left != NULL && binaryTree->right != NULL){
		return (hasPathsum(binaryTree->left, sum) || hasPathsum(binaryTree->right, sum));
	}
	if(binaryTree->right != NULL){
		return hasPathsum(binaryTree->right, sum);
	}
	if(binaryTree->left != NULL){
		return hasPathsum(binaryTree->left, sum);
	}
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
	root = insert(root, -5);
	root = insert(root, -1);
	root = insert(root, 5);
	root = insert(root, 6);
	return root;
}

main()
{
	struct node *root = build20_5_156();
	printf("%s -4\n", hasPathsum(root, -4)? "has Pathsum:": "don't have Pathsum :");
	printf("%s 3\n", hasPathsum(root, 3)? "has Pathsum:": "don't have Pathsum :");
}
	