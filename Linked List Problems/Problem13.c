/*
Q:	Given two lists, merge their nodes together to make one list,
	taking nodes alternately between the two lists. So ShuffleMerge()
	with {1, 2, 3} and {7, 13, 1} should yield {1, 7,2, 13, 3, 1}.
	If either list runs out, all the nodes should be taken from the
	other list.
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

struct node *ShuffleMerge(struct node *odd, struct node *even)
{
	struct node **tempRef;
	struct node **resultRef;
	tempRef = resultRef;
	while(odd != NULL && even != NULL){
		*tempRef = odd;
		odd = odd->next;
		tempRef = &((*tempRef)->next);
		*tempRef = even;
		even = even->next;
		tempRef = &((*tempRef)->next);
	}
	if(odd != NULL)
		*tempRef = odd;
	return *resultRef;
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
	struct node *a = BuildListOfLength(9);
	struct node *b = BuildListOfLength(4);
	printf("list ");
	printlinkedlist(a);
	printf("list");
        printlinkedlist(b);
        printf("are shuffle merged\n");
	struct node *c = ShuffleMerge(b, a);
	printf("And the result is ");
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
