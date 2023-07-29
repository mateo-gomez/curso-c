#include <stdio.h>

void swap(int *low, int *high)
{
	int temp = *low;
	*low = *high;
	*high = temp;
}
void imprimir(int arreglo[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", arreglo[i], n - 1 == i ? '\n' : ',');
	}
}

void selectionSort(int arreglo[], int n)
{
	int desorderedIdx;

	for (int i = 0; i < n; i++)
	{
		desorderedIdx = i;
		for (int j = i+1; j < n; j++)
		{
			if (arreglo[desorderedIdx] > arreglo[j])
			{
				desorderedIdx = j;
			}
		}

		swap(&arreglo[i], &arreglo[desorderedIdx]);
		imprimir(arreglo, n);
	}
}


int main(int argc, char const *argv[])
{
	int arreglo[] = {20, 94, 86, 82, 90, 10, 87, 36, 61, 8};
	int n = sizeof(arreglo) / sizeof(arreglo[0]);

	selectionSort(arreglo, n);
	imprimir(arreglo, n);

	return 0;
}