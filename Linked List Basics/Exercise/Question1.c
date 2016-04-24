/*
	LinkedListBasics.pdf page No: 6
Q:	Write the code with the smallest number of assignments (=) which will build the
	above memory structure. A: It requires 3 calls to malloc(). 3 int assignments (=) to setup
	the ints. 4 pointer assignments to setup head and the 3 next fields. With a little cleverness
	and knowledge of the C language, this can all be done with 7 assignment operations (=).
A:
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

int main()
{
	struct node *linkedlist = BuildOneTwoThree();
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
