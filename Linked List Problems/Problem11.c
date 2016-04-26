/*
Q:	This is a variant on Push(). Instead of creating a new node
	and pushing it onto the given list, MoveNode() takes two lists,
	removes the front node from the second list and pushes it onto
	the front of the first.	
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

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
void Push(struct node** headRef, int data);
struct node *BuildListOfLength(int len);
int main()
{
	struct node* a = BuildListOfLength(6);
	struct node* b = BuildListOfLength(3);
        printf("Node of list ");
	printlinkedlist(a);
	printf(" moved to ");
	printlinkedlist(b);
	MoveNode(&a, &b);
	printf("Then First list is ");
	printlinkedlist(b);
	printf(", And second list is ");
	printlinkedlist(a);
        printf("\n");
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
	printf("}");
}
