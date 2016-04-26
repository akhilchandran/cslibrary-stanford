/*
Q:	Given a list, split it into two sublists — one for the front half, and one for
	the back half. If the number of elements is odd, the extra element should go in
	the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield
	the two lists {2, 3, 5} and {7, 11}.

A:	Using Hint:
	There is a trick technique that uses two pointers to traverse the list. A "slow"
	pointer advances one nodes at a time, while the "fast" pointer goes two nodes at
	a time. When the fast pointer reaches the end, the slow pointer will be about
	halfway.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

void FrontBackSplit(struct node *source, struct node **frontRef, struct node **backRef)
{
	*frontRef = source;
	struct node **temp = &source;
	while((*frontRef) != NULL){
		temp = &((*temp)->next);
		frontRef = &((*frontRef)->next);
		if((*frontRef) != NULL)
			frontRef = &((*frontRef)->next);
	}
	*backRef = *temp;
	*temp = NULL;
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node *BuildListOfLength(int len);
int main()
{
	struct node* b =NULL;
	struct node* a = BuildListOfLength(5);
	printf("list ");
	printlinkedlist(a);
	FrontBackSplit(a, &a, &b);
	printf("splited to ");
	printlinkedlist(a);
	printf(",");
	printlinkedlist(b);
	printf("\n");

	a = BuildListOfLength(4);
        printf("list ");
        printlinkedlist(a);
        FrontBackSplit(a, &a, &b);
        printf("splited to ");
        printlinkedlist(a);
        printf(",");
        printlinkedlist(b);
        printf("\n");

	a = BuildListOfLength(3);
        printf("list ");
        printlinkedlist(a);
        FrontBackSplit(a, &a, &b);
        printf("splited to ");
        printlinkedlist(a);
        printf(",");
        printlinkedlist(b);
        printf("\n");

	a = BuildListOfLength(2);
        printf("list ");
        printlinkedlist(a);
        FrontBackSplit(a, &a, &b);
        printf("splited to ");
        printlinkedlist(a);
        printf(",");
        printlinkedlist(b);
        printf("\n");

        a = BuildListOfLength(1);
        printf("list ");
        printlinkedlist(a);
        FrontBackSplit(a, &a, &b);
        printf("splited to ");
        printlinkedlist(a);
        printf(",");
        printlinkedlist(b);
        printf("\n");

        a = NULL;
        printf("list ");
        printlinkedlist(a);
        FrontBackSplit(a, &a, &b);
        printf("splited to ");
        printlinkedlist(a);
        printf(",");
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
	printf("list is :{");
	while (head != NULL) {
		printf(" %d", head->data);
		head = head->next;
	}
	printf("}\n");
}
