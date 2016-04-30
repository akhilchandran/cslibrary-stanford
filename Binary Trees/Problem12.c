/*
Q:	Suppose you are building an N node binary search tree with the values 1..N.
	How many structurally different  binary search trees are there that store
	those values?. 
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

int countTree(int N)
{
	/*
	 * each value from 1-N could be the root;
	 * 
	 * 
	 * for each root value i
	 *	left tree have 1 to i-1 values, that is i-1 nodes
	 *	right tree have values from i+1 to N, that is (N-i) nodes
	 *	the product of number of threes that can for at each half
	 * 	is the number of threes that can for with that root. 
	 */
	int i;
	if(N == 1 || N == 0){
		return 1;
	}
	int count = 0;
	for (i = 1; i <= N; i++){
		int leftHalfCount = countTree(i-1);
		int rightHalfCount = countTree(N-i);
		int totalCountFori = leftHalfCount * rightHalfCount;
		count += totalCountFori;
	}
	return count;
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
	printf("number of tree that can form with 4 un-equal nodes are %d\n",countTree(4));
	printf("number of tree that can form with 7 un-equal nodes are %d\n",countTree(7));
}