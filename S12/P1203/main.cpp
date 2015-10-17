#include <stdio.h>

void qsort(int a[], int left, int right);

int main()
{
	int a[10], i;
	int N;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	//end of input
	qsort(a, 0, N - 1);
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	return 0;
}

void qsort(int a[], int left, int right)
{
	int l, r, head;
	if (left >= right)return;
	l = left;
	r = right;
	head = a[l];
	do
	{
		while ((l < r) && (a[r] >= head))
			r--;
		if (l < r)
		{
			a[l] = a[r]; l++;
		}
		while ((l < r) && a[l] <= head)
			l++;
		if (l < r)
		{
			a[r] = a[l]; r--;
		}
	}while (l != r);
	a[l] = head;
	qsort(a, left, l - 1);
	qsort(a, r + 1, right);
}