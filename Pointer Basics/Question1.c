#include <stdio.h> /* Standared input output header for printf*/
#include <stdlib.h> /* Header for malloc */
int main()
{
	int *x; /* x is a pointer to a int */
	int *y; /* y is a pointer to a int */
	
	x = malloc(sizeof(int)); /* allocate a integer 
					sized memory as pointee of x */
	*x = 42; /* Dereferance x to store 42 in its pointee
			which we just have allocated */
	/* *y = 13; whould CRASH since it don't have a pointee */
	y = x; /* Sets y to point x's pointee */
	*y = 13; /* Dereferance y to store 13 its pointee which
			also pointee of x */
	printf("x's pointee has a value: %d\n", *x); /* will print 13
			since y and x share same pointee */
}
	

