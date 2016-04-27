/*
Q:	MergeSort(): take a unsorted list and return a sorted.
        A diffrent a approch! :)
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
        int data;
        struct node *next;
};
struct sunode {
	struct node *a;
	struct node *b;
	struct sunode *next;
};

struct node *SortedMerge(struct node *headA, struct node *headB);
void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
void DeleteList(struct sunode **headRef);

struct sunode *makesulist(struct node *list)
{
	struct sunode *resultHead;
	struct sunode **resultRef = &resultHead;
	struct node *tempHead;
	
	while(list != NULL){
		*resultRef = malloc(sizeof(struct sunode));
		(*resultRef)->a = list;
		tempHead = list->next;
		list->next = NULL;
		if(tempHead != NULL){
			(*resultRef)->b = tempHead;
			list = tempHead->next;
			tempHead->next = NULL;
		}else{
			(*resultRef)->b = NULL;
		}
		resultRef = &((*resultRef)->next);
	}
	*resultRef = NULL;
	return resultHead;
}

void MergeSort(struct sunode *sulist)
{
	struct sunode *fast = sulist;
	struct sunode **slow = &sulist;
	struct sunode *temp = NULL;
	int i = 2;
	while(fast != NULL && i > 0){
		(*slow)->a = SortedMerge(fast->a,fast->b);
		fast = fast->next;
		if(fast != NULL){
			(*slow)->b = SortedMerge(fast->a,fast->b);
			fast = fast->next;
		}else{
		        (*slow)->b = NULL;
		}
		slow = &((*slow)->next);
	        i--;	
	}
	
	DeleteList(slow);
	if(sulist->b != NULL)
		MergeSort(sulist);
	return;
}

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

int main()
{
	struct node *listA = NULL;
	Push(&listA, 200);
	Push(&listA, 700);
	Push(&listA, 80);
	Push(&listA, 97);
	Push(&listA, 2);
	Push(&listA, 7);
	struct sunode *c; 
	c = makesulist(listA);
	MergeSort(c);
	printlinkedlist(c->a);

        struct node *listB = NULL;
        Push(&listB, 467);
        Push(&listB, 560);
        Push(&listB, 16);
        Push(&listB, 234);
        Push(&listB, 82);
        Push(&listB, 99);
	Push(&listB, 7);
	Push(&listB, 5);
        struct sunode *d;
	d = makesulist(listB);
	MergeSort(d);
        printlinkedlist(d->a);
}

void Push(struct node** headRef, int data)
{
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = *headRef;
        *headRef = newNode;
}

void DeleteList(struct sunode **headRef)
{
        struct sunode *temp;
        while(*headRef != NULL){
                temp = *headRef;
                *headRef = (*headRef)->next;
                free(temp);
        }
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
