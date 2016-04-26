/*
Q:	Given a list, split it into two sublists — one for the front half, and one for
	the back half. If the number of elements is odd, the extra element should go in
	the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield
	the two lists {2, 3, 5} and {7, 11}.
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
