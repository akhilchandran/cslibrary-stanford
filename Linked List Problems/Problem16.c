/*
Q:	Given two lists sorted in increasing order, create and return a new list
	representing theintersection of the two lists. The new list should be 
	made with its own memory — the original lists should not be changed. In other
	words, this should be Push() list building, not MoveNode(). Ideally, each
	list should only be traversed once.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
        int data;
        struct node *next;
};
void MoveNode(struct node **fromRef, struct node **toRef);
void Push(struct node** headRef, int data);
void printlinkedlist(struct node *head);

struct node *SortedIntersect(struct node *headA, struct node *headB)
{
	struct node *head = NULL;
	struct node **tempHead = &head;
	while(headA != NULL && headB != NULL){
		if(headA->data == headB->data){
			Push(tempHead, headA->data);
			tempHead = &((*tempHead)->next);
			headA = headA->next;
			headB = headB->next;
		}else if(headA->data < headB->data)
			headA = headA->next;
		else
			headB = headB->next;		
	}
	return head;
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

int main()
{
	struct node *listA = NULL;
	Push(&listA, 765);
	Push(&listA, 97);
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
	printf(" is sorted intersect with sorted list B :");
	printlinkedlist(listB);
	printf("\nThen result is");
	printlinkedlist(SortedIntersect(listA,listB));
	printf("\n");
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
	printf("}");
}
