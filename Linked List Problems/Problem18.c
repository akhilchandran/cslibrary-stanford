/*
Q:	Write an iterative Reverse() function that reverses a list by
        rearranging all the next pointers and the head pointer.Ideally,
        Reverse() should only need to make one pass of the list
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
        int data;
        struct node *next;
};
void Push(struct node** headRef, int data);
void printlinkedlist(struct node *head);

void RecursiveReverse(struct node **headRef)
{
	if((*headRef)->next==NULL)
		return;
	struct node *headnode = NULL;
	struct node *result = NULL;
	headnode = *headRef;
	result = headnode->next;
	RecursiveReverse(&result);
	headnode->next->next = headnode;
	headnode->next = NULL;
	*headRef = result;
}

int main()
{
	struct node *listA = NULL;
	Push(&listA, 765);
	Push(&listA, 97);
	Push(&listA, 83);
	Push(&listA, 76);
	Push(&listA, 7);
	Push(&listA, 2);
        struct node *listB = NULL;
        Push(&listB, 900);
        Push(&listB, 560);
        Push(&listB, 100);
        Push(&listB, 97);
        Push(&listB, 82);
        Push(&listB, 68);
	Push(&listB, 7);
	Push(&listB, 5);
	printf("List A is :");
	printlinkedlist(listA);
	printf("And reverse of list A is :");
	RecursiveReverse(&listA);
	printlinkedlist(listA);
	printf("\n");
	printf("List B is :");
	printlinkedlist(listB);
	printf("And reverse of list B is :");
	RecursiveReverse(&listB);
	printlinkedlist(listB);
	printf("\n");
}

void Push(struct node** headRef, int data)
{
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = *headRef;
        *headRef = newNode;
}

void printlinkedlist(struct node *head)
{
	printf("{");
	while (head != NULL) {
		printf(" %d", head->data);
		head = head->next;
	}
	printf("}");
}
