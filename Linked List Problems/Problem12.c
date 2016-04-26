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
void MoveNode(struct node **fromRef, struct node **toRef);
void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node *BuildListOfLength(int len);

void AlternatingSplit(struct node *source, struct node **oddRef, struct node **evenRef)
{
	while(source != NULL){
		MoveNode(&source, oddRef);
		MoveNode(&source, evenRef);
	}
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

int main()
{
	printf("a");
	struct node *a = BuildListOfLength(9);
	printf("b");
	struct node *b = NULL;
	struct node *c = NULL;
        printf("Node of list ");
	printlinkedlist(a);
	AlternatingSplit(a, &b, &c);
	printf(" Alternating splited into ");
	printlinkedlist(b);
	printf(" and ");
	printlinkedlist(c);
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
