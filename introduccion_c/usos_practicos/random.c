#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	printf("%d \n", rand());
	return 0;
}
