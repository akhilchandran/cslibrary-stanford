/*
Q:	Write an InsertSort() function which given a list, rearranges its nodes
	so they are sorted in increasing order. It should use SortedInsert().
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
        int data;
        struct node *next;
};
void SortedInsert(struct node **headRef, struct node *newNode);
void InsertSort(struct node **headRef)
{
	struct node *newhead = NULL;
	struct node *nextnode;
	while(*headRef != NULL){
		nextnode = (*headRef)->next;
		SortedInsert(&newhead, *headRef);
		*headRef = nextnode;
	}
	*headRef = newhead;
}
void SortedInsert(struct node **headRef, struct node *newNode)
{
	struct node **lastNodeRef = headRef;
	struct node *nextNode;
	int newData = newNode->data;
	while(*lastNodeRef != NULL && ((*lastNodeRef)->data < newData)){
		lastNodeRef = &((*lastNodeRef)->next);
	}
	nextNode = *lastNodeRef;
	*lastNodeRef = newNode;
	(*lastNodeRef)->next = nextNode;
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);

int main()
{
	struct node *list = NULL;
	
	Push(&list, 10);
	Push(&list, 3);
	Push(&list, 76);
	Push(&list, 3);
	Push(&list, 2);
	Push(&list, 65);
	printf("List is: ");
	printlinkedlist(list);
	InsertSort(&list);
	printf("Sorted list is:");
	printlinkedlist(list);
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
	printf("}\n");
}
