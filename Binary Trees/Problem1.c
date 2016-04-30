#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
}; 

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
struct node *build123_1()
{
	struct node *root = NewNode(2);
	struct node *leftChild = NewNode(1);
	struct node *rightChild = NewNode(3);

	root->left = leftChild;
	root->right = rightChild;
	return root;
}

struct node *build123_2()
{
	struct node *root = NewNode(2);
	root->left = NewNode(1);
	root->right = NewNode(3);
	return root;
}

struct node *build123_3()
{
	struct node *root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	return root;
}

main()
{
	struct node *root = build123_1();
	printf("%d\n",root->data);
	printf("%d\n",root->left->data);
	printf("%d\n\n",root->right->data);

	root = build123_2();
        printf("%d\n",root->data);
        printf("%d\n",root->left->data);
        printf("%d\n\n",root->right->data);

	root = build123_3();
        printf("%d\n",root->data);
        printf("%d\n",root->left->data);
        printf("%d\n\n",root->right->data);
}
	
