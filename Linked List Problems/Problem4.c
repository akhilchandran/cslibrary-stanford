/*
Q:	Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty
	list, deletes the head node, and returns the head node's data.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

int Pop(struct node **headRef)
{
	struct node *temp;
	int data;
	if(*headRef != NULL){
		temp = *headRef;
		*headRef = (*headRef)->next;
		data = (*headRef)->data;
		free(temp);
		return data;
	}
	assert(0);
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
