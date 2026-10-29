// WAP to implement Merge Sort using Array. 

#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int middle, int right)
{
	int i = left, j = middle + 1, k = 0;
	int *temporary = malloc((right - left + 1) * sizeof(*temporary));
	if (temporary == NULL)
		return;

	while (i <= middle && j <= right) {
		if (array[i] <= array[j])
			temporary[k++] = array[i++];
		else
			temporary[k++] = array[j++];
	}

	while (i <= middle)
		temporary[k++] = array[i++];
	while (j <= right)
		temporary[k++] = array[j++];

	for (i = left, k = 0; i <= right; i++, k++)
		array[i] = temporary[k];

	free(temporary);
}

void mergeSort(int array[], int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

int main(void)
{
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	int array[n];
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);

	mergeSort(array, 0, n - 1);

	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}


