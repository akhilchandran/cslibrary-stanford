/*
Q:	Write a function DeleteList() that takes a list, deallocates all
	of its memory and sets its head pointer to NULL (the empty list).
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

void DeleteList(struct node **headRef)
{
	struct node *temp;
	while(*headRef != NULL){
		temp = *headRef;
		*headRef = (*headRef)->next;
		free(temp);
	}
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node* BuildListOfLength(int len);

int main()
{
	int i;
	struct node *list = BuildListOfLength(4);
	printf("linked ");
	printlinkedlist(list);
	DeleteList(&list);
	if(list == NULL)
		printf("list deleted.\n");
}

void Push(struct node** headRef, int data)
{
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = *headRef;
        *headRef = newNode;
}

struct node* BuildListOfLength(int len)
{
	struct node* head = NULL;
	struct node** lastPtrRef= &head;
	int i;
	for (i=1; i<=len; i++) {
		Push(lastPtrRef, i);
		lastPtrRef= &((*lastPtrRef)->next);
	}
	return(head);
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
