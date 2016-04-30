/*
Q:	 take an ordered binary tree and rearrange the internal pointers to make a
	circular doubly linked list out of itn.
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

struct node **BSTToL(struct node *treehead, struct node **listheadRef)
{
	if(treehead == NULL){
		*listheadRef = NULL;
		return listheadRef;
	}
	if(treehead->left != NULL){
		listheadRef = BSTToL(treehead->left, listheadRef);
	}
	*listheadRef = treehead;
	listheadRef = &(treehead->right);
	if (treehead->right != NULL){
		listheadRef = BSTToL(treehead->right, listheadRef);
	}
	return listheadRef;
}
void LToCDL(struct node *listhead)
{
	if(listhead == NULL)
		return;
	struct node *temphead = listhead;
	while(temphead->right != NULL){
		temphead->right->left = temphead;
		temphead = temphead->right;
	}
	temphead->right = listhead;
	listhead->left = temphead;
}
void BSTToCDL(struct node *treehead, struct node **listheadRef)
{
	BSTToL(treehead, listheadRef);
	LToCDL(*listheadRef);
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
void printNNodesOfList(struct node *list, int N)
{
	while(N > 0){
		printf(" %d", list->data);
		list = list->right;
		N--;
	}
	printf("....\n");
}
void printNNodesROfList(struct node *list, int N)
{
	while(N > 0){
		printf(" %d", list->data);
		list = list->left;
		N--;
	}
	printf("....\n");
}
main()
{
	struct node *list = NULL;
	BSTToCDL(builda(), &list);
	printf("In order Circular Doubly Linked list of binary tree case 'a' is \n\t\t:");
	printNNodesOfList(list , 10);
	printf("In order Circular Doubly Linked list in reverse of binary tree case 'a' is \n\t\t:");
	printNNodesROfList(list ,10);
	BSTToCDL(buildb(), &list);
	printf("In order Circular Doubly Linked list of binary tree case 'b' is \n\t\t:");
	printNNodesOfList(list , 10);
	printf("In order Circular Doubly Linked list in reverse of binary tree case 'b' is \n\t\t:");
	printNNodesROfList(list ,10);
	BSTToCDL(buildc(), &list);
	printf("In order Circular Doubly Linked list of binary tree case 'c' is \n\t\t:");
	printNNodesOfList(list , 10);
	printf("In order Circular Doubly Linked list in reverse of binary tree case 'c' is \n\t\t:");
	printNNodesROfList(list ,10);
	BSTToCDL(buildd(), &list);
	printf("In order Circular Doubly Linked list of binary tree case 'd' is \n\t\t:");
	printNNodesOfList(list , 10);
	printf("In order Circular Doubly Linked list in reverse of binary tree case 'd' is \n\t\t:");
	printNNodesROfList(list ,10);
}