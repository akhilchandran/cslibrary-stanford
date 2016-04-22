#include <stdio.h>
#include <stdlib.h> /* for malloc */
int main()
{
	int *x;	/* x is a pointer to int*/
	int *y; /* y is a pointer to int*/

	x = malloc(sizeof(int)); /* Allocate a integer sized memory
					and set x to point it */
	y = malloc(sizeof(int));/* Allocate a integer sized memory
                                        and set y to point it */
	*x = 1;/* Dereferance x to to it's pointee and set it to 1*/
	*y = 2;/* Dereferance y to to it's pointee and set it to 2*/
	x = y; /* Set x to point pointee of y*/
	/* Now first alocted pointee has no pointer hence will be a
		a cause to memory leak */
	printf("x has a pointee value: %d, y has a pointee value: %d\n", *x, *y);
}
