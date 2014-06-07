#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[], int num)
{
	int j, i, key;
	//for j = 2 to a.length
	for(j = 1; j < num; j++)
	{
		key = a[j];
		//insert A[j] in sorted Sequence A[1...j - 1]
		i = j - 1;
		while(i >= 0 && a[i] > key)
		{
			a[i+1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}

int main()
{
	int * a, num, i;
	printf("Enter the size of array: ");
	scanf("%d", &num);
	a = malloc(sizeof(int) * num);
	for(i = 0; i < num; i++)
	{
		printf("Enter the value of %d Element: ", (i+1));
		scanf(" %d", &a[i]);
	}
	insertion_sort(a, num);
	for(i = 0; i < num; i++)
		printf("the %d Element: %d.\n", (i+1), a[i]);
	return 0;
}
