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
void MoveNode(struct node **fromRef, struct node **toRef);
void Push(struct node** headRef, int data);
void printlinkedlist(struct node *head);

struct node *Reverse(struct node *head)
{
	struct node *newhead = NULL;
	while(head != NULL){
		MoveNode(&head, &newhead);
	}
	return newhead;
}

void MoveNode(struct node **fromRef, struct node **toRef)
{
	struct node *temp;
	if(*fromRef != NULL){
		temp = (*fromRef)->next;
		(*fromRef)->next = *toRef;
		*toRef = *fromRef;
		*fromRef = temp;
	}
}

void printlinkedlist(struct node *head);

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
	printlinkedlist(Reverse(listA));
	printf("\n");
	printf("List B is :");
	printlinkedlist(listB);
	printf("And reverse of list B is :");
	printlinkedlist(Reverse(listB));
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
