/*
Q:	Write an Append() function that takes two lists, 'a' and 'b',
        appends 'b' onto the end of 'a',and then sets 'b' to NULL 
        (since it is now trailing off the end of 'a').
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

void Append(struct node **frontRef, struct node **backRef)
{
	while(*frontRef != NULL){
		frontRef = &((*frontRef)->next);
	}
	*frontRef = *backRef;
	*backRef = NULL;
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node *BuildListOfLength(int len);
int main()
{
	struct node* b = BuildListOfLength(3);
	struct node* a = BuildListOfLength(5);
	printf("A list ");
	printlinkedlist(a);
	printf(" is appended by ");
	printlinkedlist(b);
        Append(&a, &b);
        printf("\nThen first list is ");
        printlinkedlist(a);
        printf(",And second list is ");
        printlinkedlist(b);
        printf("\n");
        a = NULL;
        b = BuildListOfLength(5);
        printf("A list ");
	printlinkedlist(a);
	printf(" is appended by ");
	printlinkedlist(b);
        Append(&a, &b);
        printf("\nThen first list is ");
        printlinkedlist(a);
        printf(",And second list is ");
        printlinkedlist(b);
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
