/*
Q:	Given two binary trees, return true if they are structurally identical
	-- they are made of nodes with the same values arranged in the same way. 
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

int isSameTree(struct node *binaryTree1, struct node *binaryTree2)
{
	if (binaryTree1 == NULL){
		return(binaryTree2 == NULL);
	}
        if(binaryTree1->data == binaryTree2->data){
		return(isSameTree(binaryTree1->left,binaryTree2->left) && isSameTree(binaryTree1->right, binaryTree2->right));
	}else{
		return 0;
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

main()
{
	struct node *root = build201_5_156();
	struct node *root2 = build201_5_156();
	printf("test trees are %s\n",isSameTree(root, root2)?"same" : "not same");
}