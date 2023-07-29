#include <stdio.h>

void swap(int *low, int *high)
{
	int temp = *low;
	*low = *high;
	*high = temp;
}

int partition(int arreglo[], int low, int high)
{
	int i = low - 1;
	int pivot = arreglo[high];

	for (int j = low; j <= high - 1; j++)
	{
		if (arreglo[j] <= pivot)
		{
			i = i + 1;
			swap(&arreglo[i], &arreglo[j]);
		}
	}

	swap(&arreglo[i + 1], &arreglo[high]);

	return (i + 1);
}

void quickSort(int arreglo[], int low, int high)
{
	int partitionIdx;

	if (low < high)
	{
		partitionIdx = partition(arreglo, low, high);

		quickSort(arreglo, low, partitionIdx - 1);
		quickSort(arreglo, partitionIdx + 1, high);
	}
}

void imprimir(int arreglo[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", arreglo[i], n - 1 == i ? '\n' : ',');
	}
}

int main(int argc, char const *argv[])
{
	int arreglo[] = {3, 94, 86, 82, 90, 10, 87, 36, 61, 8, 17, 15, 22, 10, 23, 78, 25, 2, 30, 45, 98, 43, 98, 59, 53, 57, 2, 64, 1, 41, 32, 58, 19, 99, 60, 74, 48, 80, 44, 25, 68, 1, 89, 77, 60, 25, 99, 30, 76, 32, 57, 82, 52, 44, 72, 87, 34, 87, 65, 30, 54, 6, 31, 33, 44, 44, 42, 82, 90, 17, 9, 98, 28, 86, 69, 3, 17, 8, 45, 98, 12, 47, 95, 43, 72, 39, 41, 82, 74, 56, 65, 79, 50, 26, 67, 100, 24, 67, 38, 57};
	int n = sizeof(arreglo) / sizeof(arreglo[0]);

	quickSort(arreglo, 0, n - 1);
	imprimir(arreglo, n);

	return 0;
}
