#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
}; 

int size(struct node *binaryTree)
{
        if(binaryTree == NULL){
                return 0;
        }
        return size(binaryTree->left) + size(binaryTree->right) + 1;
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
	root = insert(root, 0);
	root = insert(root, 6);
	return root;
}

main()
{
	struct node *root = build123456();
        printf("%d\n", size(root));
}
	
