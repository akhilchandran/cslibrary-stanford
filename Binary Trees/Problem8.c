/*
Q:	Given a binary tree, print out all of its root-to-leaf paths, one per line. 
 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct listnode {
	int data;
	struct listnode *next;
};
void PushOnList(struct listnode** headRef, int data)
{
        struct listnode* newNode = malloc(sizeof(struct listnode));
        newNode->data = data;
        newNode->next = *headRef;
        *headRef = newNode;
}
void printlinkedlist(struct listnode *head)
{
	if(head == NULL){
		return;
	}
	printlinkedlist(head->next);
	printf(" %d", head->data);
	return;
}

int printPaths(struct node *binaryTree, struct listnode *listhead)
{
	if(binaryTree == NULL){
		printf("empty tree\n");
		return;
	}
	PushOnList(&listhead, binaryTree->data);
        if(binaryTree->left == NULL && binaryTree->right == NULL){
		printf("path :");
                printlinkedlist(listhead);
		printf("\n");
		return;
	}
	if(binaryTree->left != NULL){
		printPaths(binaryTree->left, listhead);
	}
	if(binaryTree->right != NULL){
		printPaths(binaryTree->right, listhead);
	}
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
	printPaths(root, NULL);
	//printf("%s -4\n", hasPathsum(root, -4)? "has Pathsum:": "don't have Pathsum :");
	//printf("%s 3\n", hasPathsum(root, 3)? "has Pathsum:": "don't have Pathsum :");
}
	