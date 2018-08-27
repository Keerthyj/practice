#include <stdio.h>

/* Copy function comment */
void copy(int a[100],int b[100],int begin,int end)
{
	int i, j;

	printf("Copying from %d to %d\n", begin, end);
	for (i = 0, j = begin; j <= end; i++, j++)
		b[i] = a[j];
	printf("copy count is %d\n", end - begin);
}

void merge(int b[100], int c[100], int a[100], int bc, int cc)
{
	int i = 0, j = 0, k = 0, comp_count = 0;
	for (k = 0; i < bc && j < cc; k++) {
		comp_count++;
		if (b[i] < c[j]) {
			a[k] = b[i];
			i++;
		} else {
			a[k] = c[j];
			j++;
		}
	}

	if (i == bc)
		while (j < cc)
			a[k++] = c[j++];
	else
		while (i < bc)
			a[k++] = b[i++];
	printf("Comparison count is %d\n", comp_count);
}

void mergesort(int a[100], int count)
{
	int b[100], c[100];
	if (count > 1) {
		copy(a, b, 0, count / 2 - 1);
		copy(a, c, count / 2, count - 1);
		mergesort(b, count / 2);
		mergesort(c, count - count / 2);
		merge(b, c, a, count / 2, count - count / 2);
	}
}

int main()
{
	int a[100], count, n, i;

	printf("Enter the number of elements::");
	scanf("%d", &count);

	printf("\n\n\n Enter the %d elements one by one\n", count);
	for (i = 0; i < count; i++)
		scanf("%d", &a[i]);

	mergesort(a, count);

	printf("The sorted array is::");
	for (i = 0; i < count; i++)
		printf("%d ", a[i]);

	return 0;
}


