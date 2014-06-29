#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void merge(int *, int , int , int );
void merge_sort(int *, int, int);

int main()
{
	int i , *A;
	printf("Enter the size of ther array: ");
	scanf(" %d ", &i);
	A = malloc(sizeof(int) * i);
	for(int j = 0; j < i; j++)
	{
		printf("Enter %d element: ", (j+1));
		scanf("%d", &A[j]);
	}

	printf("Before Sorting \n");
	for(int j = 0; j < i; j++)
		printf("%d element: %d\n", (j+1), A[j]);

	merge_sort(A, 0, i-1);

	printf("After Sorting \n");
	for(int j = 0; j < i; j++)
		printf("%d element: %d\n", (j+1), A[j]);

	return 0;
}

void merge_sort(int *A, int p, int r)
{
	if( p < r)
	{
		int q = (p + r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

void merge(int* A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int * L = malloc((n1+1) * sizeof(int));
	int * R = malloc((n2+1) * sizeof(int));
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	for(int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for(int j = 0; j < n2; j++)
		R[j] = A[q + j + 1];

	int i = 0;
	int j = 0;
	for(int k = p; k <= r; k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i = i+1;
		}
		else
		{
			A[k] = R[j];
			j = j+1;
		}
	}
}
