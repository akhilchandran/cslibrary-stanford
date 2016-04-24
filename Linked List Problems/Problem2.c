/*
Q:	Write a GetNth() function that takes a linked list and an integer
	index and returns the data value stored in the node at that index
	position. GetNth() uses the C numbering convention that the first
	node is index 0, the second is index 1, ... and so on. So for the
	list {42, 13, 666} GetNth() with index 1 should return 13. The
	index should be in the range [0..length-1]. If it is not, GetNth()
	should assert() fail (or you could implement some other error case
	strategy).
Note:	return -1 when out of index.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

int getnth(struct node *head, int n)
{
	int count = 0;
	while(head != NULL){
		if(count == n){
			return head->data;
		}
		count++;
		head = head->next;
	}
	return -1;
}

void printlinkedlist(struct node *head);
void Push(struct node** headRef, int data);
struct node* BuildListOfLength(int len);

int main()
{
	int i;
	struct node *list = BuildListOfLength(4);
	printf("linked ");
	printlinkedlist(list);
	printf("has data %d at index 2.\n",getnth(list, 2));
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
