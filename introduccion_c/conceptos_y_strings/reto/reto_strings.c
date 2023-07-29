#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

	int i;
	int max_length = 0;
	char *longest_str;

	for (i = 0; i < argc; i++)
	{
		int str_length = strlen(argv[i]);

		if (str_length > max_length)
		{
			max_length = str_length;
			longest_str = argv[i];
		}
	}

	printf("La cadena más larga es %s\n", longest_str);

	return 0;
}