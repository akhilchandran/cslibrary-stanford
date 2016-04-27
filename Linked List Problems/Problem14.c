/*
Q:	Write SortedMerge() function that takes two lists, each of which is sorted
	in increasing order, and merges the two together into one list which is in
	increasing order.SortedMerge() should return the new list. The new list
	should be made by splicing together the nodes of the first two lists
	(use MoveNode()).
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
        int data;
        struct node *next;
};
void MoveNode(struct node **fromRef, struct node **toRef);
struct node *SortedMerge(struct node *headA, struct node *headB)
{
	struct node *result = NULL;
	struct node **tempRef = &result;
	while(headA != NULL && headB != NULL){
		if(headA->data <= headB->data){
			*tempRef = headA;
			headA = headA->next;
		}
		else{
			*tempRef = headB;
                        headB = headB->next;
		}
		tempRef = &((*tempRef)->next);
	}
	if(headA != NULL)
		*tempRef = headA;
	else if(headB != NULL)
		*tempRef = headB;
	return result;
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

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);

int main()
{
	struct node *listA = NULL;
	Push(&listA, 765);
	Push(&listA, 92);
	Push(&listA, 83);
	Push(&listA, 76);
	Push(&listA, 7);
	Push(&listA, 2);
        struct node *listB = NULL;
        Push(&listB, 900);
        Push(&listB, 560);
        Push(&listB, 100);
        Push(&listB, 97);
        Push(&listB, 82);
        Push(&listB, 68);
	Push(&listB, 7);
	Push(&listB, 5);
	printf("Sorted list A :");
	printlinkedlist(listA);
	printf(" is sorted merged with sorted list B :");
	printlinkedlist(listB);
	printf("\nThen result is");
	printlinkedlist(SortedMerge(listA,listB));
}

void Push(struct node** headRef, int data)
{
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = *headRef;
        *headRef = newNode;
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
