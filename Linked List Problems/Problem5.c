/*
Q:	A more difficult problem is to write a function InsertNth()
	which can insert a new node at any index within a list.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
        int data;
        struct node *next;
};

int InsertNth(struct node **headRef, int index, int data)
{
	struct node **lastNodeRef = headRef;
	struct node *nextNode;
	while(index > 0 && *lastNodeRef != NULL){
		lastNodeRef = &((*lastNodeRef)->next);
		index--;
	}
	if(index == 0){
		nextNode = *lastNodeRef;
		*lastNodeRef = malloc(sizeof(struct node));
		(*lastNodeRef)->data = data;
		(*lastNodeRef)->next = nextNode;
		return 1;
	}
	assert(0);
}

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
	return 1;
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node* BuildListOfLength(int len);

int main()
{
	int i;
	struct node *list = NULL;
	printf("List is: ");
	printlinkedlist(list);
	InsertNth(&list, 0, 10);
	printf("After inserting 10 at index 0 the list is: ");
	printlinkedlist(list);
	InsertNth(&list, 1, 4);
	printf("After inserting 4 at index 1 the list is: ");
        printlinkedlist(list);
	InsertNth(&list, 1, 7);
        printf("After inserting 7 at index 1 the list is: ");
        printlinkedlist(list);
	 printf("Try inserting at a larger index which can't complete\n");
        InsertNth(&list, 4, 14444);
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
	printf("{");
	while (head != NULL) {
		printf(" %d", head->data);
		head = head->next;
	}
	printf("}\n");
}
