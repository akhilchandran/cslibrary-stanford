/*
	LinkedListBasics.pdf page No: 10
Q:	What if the passed in list contains no elements, does Length() handle that case
	properly?
A:	Yes. In length function count fist intialized to 0. If list has no ellement head will be 
	NULL,So is current,So at fist ittration of while it self while fail and count is retuned 
	with a value 0. 
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printlinkedlist(struct node *head);

int length(struct node *head)
{
	struct node *current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

int main()
{
	struct node *linkedlist = NULL;
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
