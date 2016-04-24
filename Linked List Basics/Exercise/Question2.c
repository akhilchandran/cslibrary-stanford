/*
Q:	What if we said head = NULL; at the end of Length() — would that mess up the
	myList variable in the caller?

A:	No; In length function 'head' is local which refers to the linked list changing
	the head would not make any change in the 'linkedlist' in the calling function
	which has seperate pointer of the 'linkedlist'.

	Bellow program prove the explantion in it head assigned to NULL in leanth function
	but it won't change anything of the linked list in the main. The 'printlinkedlist'
	print the same linked list after length function assign NULL to it's own coppy.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printlinkedlist(struct node *head);

struct node *BuildOneTwoThree()
{
	struct node *head = malloc(sizeof(struct node));

	head->data = 1;
	head->next = malloc(sizeof(struct node));
	(head->next)->data = 2;
	(head->next)->next = malloc(sizeof(struct node));
	((head->next)->next)->data = 3;
	((head->next)->next)->next = NULL;
	return head;	
}

int length(struct node *head)
{
	struct node *current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}
	head = NULL;
	return count;
}

int main()
{
	struct node *linkedlist = BuildOneTwoThree();
	int len = length(linkedlist);
	printf("length of list: %d\n", len);
	printlinkedlist(linkedlist);
}

void printlinkedlist(struct node *head)
{
	printf("list is :{");
	while (head != NULL) {
		printf(" %d", head->data);
		head = head->next;
	}
	printf("}\n");
}
