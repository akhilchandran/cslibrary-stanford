#include <stdio.h>
#include <stdlib.h>
struct Node {
	int value;
	struct Node *next;
};

int main()
{
	printf("Version 1:\n");
	version1();
	printf("Version 2:\n");
	version2();
	return 0;
}

int version1()
{
	struct Node *x;
	struct Node a, b, c;
	a.value = 1;
	a.next = &b;
	b.value = 2;
	b.next = &c;
	c.value = 3;
	c.next = &a;
	x = &a;
	printf("x point to Fist Node which has value :%d\n", x->value);
	printf("First Node point to Second Node which has value:%d\n", (x->next)->value);
	printf("Second Node point to Third Node which has value:%d\n", ((x->next)->next)->value);
	printf("Third Node point to Fist Node which has value: %d\n",(((x->next)->next)->next)->value);
	return 0;
}

int version2()
{
	struct Node *x;

	x = malloc(sizeof(struct Node));
	x->value = 1;
	x->next = malloc(sizeof(struct Node));
	(x->next)->value = 2;
	(x->next)->next = malloc(sizeof(struct Node));
	((x->next)->next)->value = 3;
	((x->next)->next)->next = x;

        printf("x point to Fist Node which has value :%d\n", x->value);
        printf("First Node point to Second Node which has value:%d\n", (x->next)->value);
        printf("Second Node point to Third Node which has value:%d\n", ((x->next)->next)->value);
        printf("Third Node point to Fist Node which has value: %d\n",(((x->next)->next)->next)->value);
        return 0;
}
