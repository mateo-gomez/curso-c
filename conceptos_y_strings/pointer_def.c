#include "stdio.h"

int main()
{
	int number = 91919;
	int *pointToNumber = &number;

	printf("%p, %d\n", pointToNumber, *pointToNumber);

	return 0;
}