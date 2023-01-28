#include <stdio.h>

int say = 0;
void merge(int A[], int, int, int);
void mergeSort(int A[], int l, int h);

int main()
{
	int temp, i, j, m, l, h;
	m = 8;
	l = 0;
	h = m-1;
	
	int A[m] = {19,12,20,16,14,13,8,5};
	for(i=0; i<m; i++)
		printf(" %d ", A[i]);
	printf("\n");

	mergeSort(A, l, h);
	printf("\nSorted Array\n");
	
	for (i = 0; i <=h; i++)
		printf("%d, ", A[i]);
	return 0;
}
void mergeSort(int A[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h)/2;
		mergeSort(A, l, mid);
		mergeSort(A, mid+1, h);
		merge(A, l, mid, h);
	}
}

void merge(int A[], int l, int mid, int h)
{
	int i, j, k;
	i=l;
	j = mid + 1;
	k= l;
	int B[h+1] = {0};
	
	while ( i <= mid && j <= h)
	{
		if ( A[i] < A[j])
			B[k++] = A[i++];
		else 
			B[k++] = A[j++];
	}
	
	for ( ; i<=mid; i++)
		B[k++]=A[i];
		
	for ( ; j<= h; j++)
		B[k++] = A[j];
	say++;
	
	printf("%d. Merge ==>", say);	
		
	for(i=l; i<= h; i++)
	{
		A[i] = B[i];
		printf("%d, ", A[i]);
	}
	printf("\n");
	
}
