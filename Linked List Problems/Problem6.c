/*
Q:	Write a SortedInsert() function which given a list that	is sorted in
	increasing order, and a single node, inserts the node into the correct
	sorted position in the list
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
        int data;
        struct node *next;
};

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

int main()
{
	int i;
	struct node *list = NULL;
	printf("List is: ");
	printlinkedlist(list);
	
	struct node *newnode;
	newnode  = malloc(sizeof(struct node));
	newnode->data = 10;
	newnode->next = NULL;

	SortedInsert(&list, newnode);
	printf("Inserted a node with data 10 as sorted,then list is: ");
	printlinkedlist(list);

        newnode  = malloc(sizeof(struct node));
        newnode->data = 5;
        newnode->next = NULL;

        SortedInsert(&list, newnode);
        printf("Inserted node with data 5 as sorted, then list is: ");
        printlinkedlist(list);


        newnode  = malloc(sizeof(struct node));
        newnode->data = 15;
        newnode->next = NULL;

        SortedInsert(&list, newnode);
        printf("Inserted a node with data 15 as sorted, then list is: ");
        printlinkedlist(list);


        newnode  = malloc(sizeof(struct node));
    	newnode->data = 7;
        newnode->next = NULL;

        SortedInsert(&list, newnode);
        printf("Inserted a node with data 7 as  sorted, then list is: ");
        printlinkedlist(list);
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
