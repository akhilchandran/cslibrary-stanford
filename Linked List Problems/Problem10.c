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

void RemoveDuplicate(struct node *sortedList)
{
	if(!sortedList)
		return;
	while((sortedList->next) != NULL){
		if(sortedList->data == sortedList->next->data){
			free(sortedList->next);
		        sortedList->next  = sortedList->next->next;
		}else{
		        sortedList = sortedList->next;
		}
	}
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node *BuildListOfLength(int len);
int main()
{
	struct node* a = NULL;
        Push(&a, 78);
        Push(&a, 78);
        Push(&a, 44);
        Push(&a, 37);
        Push(&a, 37);
        Push(&a, 37);
        Push(&a, 37);
        Push(&a, 36);
        Push(&a, 36);
        Push(&a, 20);
        Push(&a, 19);
        Push(&a, 18);
        Push(&a, 8);
        Push(&a, 7);
        Push(&a, 7);
        Push(&a, 7);
        Push(&a, 0);
        printf("A sorted list is ");
	printlinkedlist(a);
	printf("\n");
	RemoveDuplicate(a);
        printf("List after removing duplicates is ");
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
