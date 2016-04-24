/*
	LinkListBasics.pdf Page:24
Q: 	Write a CopyList2() which uses Push() to take care of
	allocating and inserting the new nodes, and so avoids
	repeating that code
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

void Push(struct node** headRef, int data);
struct node *BuildOneTwoThree();
void printlinkedlist(struct node *head);

struct node* CopyList2(struct node *head)
{
        struct node *newlist = NULL;
        struct node **tailRef;

        tailRef = &newlist;
        while(head != NULL){
                Push(tailRef, head->data);
                head = head->next;
                tailRef = &((*tailRef)->next);
        }
        return newlist;
}

void Push(struct node** headRef, int data) {
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = *headRef;
        *headRef = newNode;
}


struct node *BuildOneTwoThree()
{
        struct node *head = malloc(sizeof(struct node));

        head->data = 1;
        head->next = malloc(sizeof(struct node));
        (head->next)->data = 2;
        (head->next)->next = malloc(sizeof(struct node));
        ((head->next)->next)->data = 3;
        ((head->next)->next)->next = NULL;
        return head;
}

int main()
{
	struct node *linkedlist = BuildOneTwoThree();
	printlinkedlist(linkedlist);
	struct node *copy = CopyList2(linkedlist);
	printlinkedlist(copy);
	linkedlist->data = 10;
	printlinkedlist(linkedlist);
	printlinkedlist(copy);
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

