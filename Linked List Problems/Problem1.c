/*
Q:	Write a Count() function that counts the number of times a given
	int occurs in a list
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

int count(struct node *head, int searchFor)
{	int count = 0;
	while(head != NULL){
		if (head->data == searchFor)
			count++;
		head = head->next;
	}
	return count;
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node* BuildListOfLength(int len);

int main()
{
	int i;
	struct node *list = BuildListOfLength(4);
	list->data = 3;
	list->next->data = 3;
	printf("linked list: ");
	printlinkedlist(list);
	printf("has %d threes.\n",count(list, 3));
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
