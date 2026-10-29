// WAP to implement Insertion Sort using Array.

#include <stdio.h>

int main(void)
{
	int a[100], n, i, j, key;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

	printf("Sorted array: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
	return 0;
}

